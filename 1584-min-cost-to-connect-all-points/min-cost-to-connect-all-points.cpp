#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Adjacency list: u -> {weight, v}
        vector<vector<pair<int,int>>> adjList(n);
        min_heap pq;
        vector<bool> visited(n, false);

        // Step 1: Build complete graph with Manhattan distances
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2 - x1) + abs(y2 - y1);

                adjList[i].push_back({dist, j});
                adjList[j].push_back({dist, i});
            }
        }

        // Step 2: Initialize Prim's Algorithm from node 0
        pq.push({0, 0});
        int minCost = 0;

        // Step 3: Process edges greedily via Min-Heap
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int wt = top.first;
            int index = top.second;

            if(visited[index]) continue; // Skip already included nodes

            visited[index] = true;
            minCost += wt;

            for(const auto &node : adjList[index]) {
                int nextIndex = node.second;
                int nextWt = node.first;

                if(!visited[nextIndex]) {
                    pq.push(node);
                }
            }
        }

        return minCost;
    }
};