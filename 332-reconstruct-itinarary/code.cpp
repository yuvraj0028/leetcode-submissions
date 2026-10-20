#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<string, vector<string>, greater<string > > min_heap;

class Solution {
private:

    void dfs(
        const string node,
        unordered_map<string, min_heap> &adjList,
        vector<string> &result
    ) {
        auto &pq = adjList[node];

        while(!pq.empty()) {
            string nextNode = pq.top();
            pq.pop();

            dfs(nextNode, adjList, result);
        }
        result.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // result array
        const string source = "JFK";
        vector<string> result;

        // string -> min heap {string}
        unordered_map<string, min_heap> adjList;

        // lexigraphically sorted strings 
        for(const vector<string> &ticket : tickets) {
            adjList[ticket[0]].push(ticket[1]);
        }
        
        dfs(source, adjList, result);
        reverse(result.begin(), result.end());

        return result;
    }
};