class Solution {
private:
    long long dfs(int currNode, int parentNode, int &compCount, int k, vector<vector<int > > &adj, vector<int> &values){
        long long sum = 0;

        for(const int &i : adj[currNode]){
            if(i!=parentNode){
                sum+=dfs(i, currNode, compCount, k, adj, values);
            }
        }

        sum+=values[currNode];

        if(sum%k == 0){
            compCount++;
            sum = 0;
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int > >  adj(n);

        for(const auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int compCount = 0;

        dfs(0, -1, compCount, k, adj, values);

        return compCount;
    }
};