class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> ans;
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int > > adjList;

        for(const auto &courses : prerequisites) {
            int u = courses[0];
            int v = courses[1];

            adjList[v].push_back(u);
        }

        for(int i=0; i<numCourses; i++) {
            for(const int &course : adjList[i]) {
                inDegree[course]++;
            }
        }

        for(int i = 0; i<numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(const int &course : adjList[front]) {
                inDegree[course]--;
                if(inDegree[course] == 0) {
                    q.push(course);
                }
            }
        }

        if(ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};