class Solution {
private:
    unordered_map<int, vector<pair<int,int > > > mp;
    vector<vector<bool > > visited;

    void buildStreets() {
        mp[1].push_back({0, 0});
        mp[1].push_back({1,-1});

        mp[2].push_back({1,-1});
        mp[2].push_back({0, 0});

        mp[3].push_back({0, 1});
        mp[3].push_back({-1,0});

        mp[4].push_back({0, 1});
        mp[4].push_back({1, 0});

        mp[5].push_back({-1,0});
        mp[5].push_back({0,-1});

        mp[6].push_back({-1,0});
        mp[6].push_back({0, 1});
    }

    bool travelPath(vector<vector<int>>& grid, int i, int j, int pi, int pj) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j]) {
            return false;
        }

        int currElem = grid[i][j];
        visited[i][j] = true;

        int i1 = mp[currElem][0].first;
        int j1 = mp[currElem][1].first;

        int i2 = mp[currElem][0].second;
        int j2 = mp[currElem][1].second;

        if(pi != -1 && pj != -1) {
            if((i1+i!=pi || j1+j!=pj) && (i2+i!=pi || j2+j!=pj)) {
                return false;
            }
        }

        if(i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }
        
        bool travelPoint1 = travelPath(grid, i + i1, j + j1, i, j);
        bool travelPoint2 = travelPath(grid, i + i2, j + j2, i, j);
    
        return travelPoint1 || travelPoint2;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        buildStreets();
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        return travelPath(grid, 0, 0, -1, -1);
    }
};