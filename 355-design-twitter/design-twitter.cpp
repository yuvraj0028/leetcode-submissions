class TweetMeta{
public:
    int userId;
    int tweetId;
    int time;
};

class Comparator {
public:
    bool operator()(const TweetMeta &a, const TweetMeta &b) {
        return a.time < b.time;
    }
};

class Twitter {
private:
    int time;
    unordered_map<int, priority_queue<TweetMeta, vector<TweetMeta>, Comparator> >userToTweetMeta;
    unordered_map<int, vector<TweetMeta > > userToTweet;
    unordered_map<int, set<int > > followers;

    void populateFeed(int userId, int tweetId) {
        set<int> followedUsers = followers[userId];
        TweetMeta tm;
        tm.userId = userId;
        tm.tweetId = tweetId;
        tm.time = time;

        for(const auto user: followedUsers) {
            userToTweetMeta[user].push(tm);
        }
    }

    vector<int> parseFeed(int userId) {
        vector<int> feed;
        auto tweetMeta = userToTweetMeta[userId];

        int cnt = 0;
        while(!tweetMeta.empty() && cnt < 10) {
            auto tm = tweetMeta.top();
            feed.push_back(tm.tweetId);
            tweetMeta.pop();
            cnt++;
        }

        return feed;
    }

public:
    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        TweetMeta tm;
        tm.userId = userId;
        tm.tweetId = tweetId;
        tm.time = time;

        userToTweetMeta[userId].push(tm);
        userToTweet[userId].push_back(tm);
        populateFeed(userId, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        return parseFeed(userId);
    }
    
    void follow(int followerId, int followeeId) {
        // 1 follows 2
        if(followerId == followeeId) return;
        if(followers[followeeId].count(followerId)) return;
        
        followers[followeeId].insert(followerId);
        vector<TweetMeta> tweets = userToTweet[followeeId];
        for(const TweetMeta &tweet: tweets) {
            userToTweetMeta[followerId].push(tweet);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        // 1 unfollows 2
        if(followerId == followeeId) return;
        if(!followers[followeeId].count(followerId)) return;

        followers[followeeId].erase(followerId);
        auto oldMeta = userToTweetMeta[followerId];
        priority_queue<TweetMeta, vector<TweetMeta>, Comparator> newMeta;

        while(!oldMeta.empty()) {
            auto meta = oldMeta.top();
            if(meta.userId != followeeId) {
                newMeta.push(meta);
            }
            oldMeta.pop();
        }

        userToTweetMeta[followerId] = newMeta;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */