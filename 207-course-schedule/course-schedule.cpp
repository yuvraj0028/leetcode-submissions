class Solution {
private:
    bool dfs(
        int course,
        unordered_map<int, vector<int>>& adjList,
        unordered_map<int,int>& visited,
        unordered_map<int,int>& dfsVisited
    ) {
        visited[course] = 1;
        dfsVisited[course] = 1;
        for(const int &nextCourse : adjList[course]) {
            if(dfsVisited[nextCourse]) {
                return true;
            }
            
            if(!visited[nextCourse]) {
                if(dfs(nextCourse, adjList, visited, dfsVisited)) {
                    return true;
                }
            }
        }

        dfsVisited[course] = 0;
        return false; 
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int > > adjList;
        unordered_map<int, int> visited, dfsVisited;

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        for(int i = 0; i<numCourses;i++) {
            if(!visited[i]){
                if(dfs(i, adjList, visited, dfsVisited)) {
                    return false;
                }
            }
        }

        return true;
    }
};