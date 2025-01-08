class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size()) return false;
        
        goal+=goal;

        return goal.find(s) != string::npos;

    }
};