class Solution {
private:
    long long INF = 1e18;
    long long dist[26][26];
    void dijkstra(unordered_map<int,vector<pair<int,int > > > &adjList, char src){
        priority_queue<pair<int,int >, vector<pair<int,int > >, greater<pair<int,int > > > pq;
        pq.push({src - 'a', 0});

        while(!pq.empty()){
            auto [node, wt] = pq.top(); pq.pop();

            for(const auto &[newNode, newWt] : adjList[node]){
                if(wt + newWt < dist[src-'a'][newNode]){
                    dist[src-'a'][newNode] = wt + newWt;
                    pq.push({newNode, wt + newWt});
                }
            }
        }
    }
public:
    long long minimumCost(
        string source,
        string target,
        vector<char>& original,
        vector<char>& changed, vector<int>& cost
    ) {   
        if(source == target) return 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dist[i][j] = INF;
            }
        }
        int n = original.size();
        unordered_map<int,vector<pair<int,int > > > adjList;
        for(int i = 0; i<n; i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int wt = cost[i];

            adjList[u].push_back({v,wt});
        }

        for(int i= 0; i<26; i++){
            dijkstra(adjList, i + 'a');
        }

        n = source.size();
        long long sum = 0;

        for(int i = 0; i<n; i++){
            int src = source[i];
            int dest = target[i];

            if(src == dest){
                continue;
            }

            if(dist[src - 'a'][dest - 'a'] == INF){
                return -1; 
            }

            sum+=dist[src-'a'][dest - 'a'];

        }
        return sum;
    }
};