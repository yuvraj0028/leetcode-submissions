#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Twitter {
private:
    int time;
    // Maps a user to a list of their own tweets stored chronologically: {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> userTweets;
    // Maps a user to the set of people they follow
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        time = 0;
    }
    
    // O(1) time - Extremely fast write operation
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({++time, tweetId});
    }
    
    // O(F + 10 log F) time, where F is the number of followees
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        // Priority Queue stores: tuple<time, tweetId, userId, vector_index>
        priority_queue<tuple<int, int, int, int>> maxHeap;

        // 1. Include the user's own latest tweet if it exists
        if (userTweets.count(userId) && !userTweets[userId].empty()) {
            int idx = userTweets[userId].size() - 1;
            maxHeap.push({userTweets[userId][idx].first, userTweets[userId][idx].second, userId, idx});
        }

        // 2. Include the latest tweet from every followee
        if (following.count(userId)) {
            for (int followeeId : following[userId]) {
                if (userTweets.count(followeeId) && !userTweets[followeeId].empty()) {
                    int idx = userTweets[followeeId].size() - 1;
                    maxHeap.push({userTweets[followeeId][idx].first, userTweets[followeeId][idx].second, followeeId, idx});
                }
            }
        }

        // 3. Extract the top 10 overall most recent tweets
        while (!maxHeap.empty() && feed.size() < 10) {
            auto [t, tweetId, authorId, idx] = maxHeap.top();
            maxHeap.pop();
            
            feed.push_back(tweetId);

            // If this author has older tweets left, push the next one down into the heap
            if (idx > 0) {
                int nextIdx = idx - 1;
                maxHeap.push({userTweets[authorId][nextIdx].first, userTweets[authorId][nextIdx].second, authorId, nextIdx});
            }
        }

        return feed;
    }
    
    // O(1) time - Just adding an ID to a hash set
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    // O(1) time - Just removing an ID from a hash set
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};