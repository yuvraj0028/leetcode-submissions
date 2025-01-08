class Solution {
private:
    vector<int> computeLps(string &s){
        int n = s.size();

        vector<int> lpsTable(n);

        int i = 1;
        int j = 0;

        while(i<n){
            if(s[i]==s[j]){
                lpsTable[i] = j+1;
                i++;
                j++;
            } else if(j>0){
                j = lpsTable[j-1];
            } else {
                i++;
            }
        }

        return lpsTable;
    }

    bool contains(string s, string goal, vector<int> &lpsTable){
        int size = s.size();
        int goalSize = goal.size();

        int i = 0, j = 0;

        while(i < size && j < goalSize){
            if(s[i] == goal[j]){
                i++;
                j++;
            }

            if(i == size){
                return true;
            }

            if(s[i] != goal[j]){
                if(i>0){
                    i = lpsTable[i-1];
                } else {
                    j++;
                }
            }
        }

        return false;
    }

public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size())
            return false;
        
        vector<int> lpsTable = computeLps(s);

        goal+=goal;

        return contains(s, goal, lpsTable);
    }
};