class Solution {
private:
    bool solve(string name, string typed, int i, int j){
        if(j==typed.size()) {
            return i == name.size();
        }

        if(i<name.size() && name[i] == typed[j]){
            return solve(name, typed, i+1, j+1);
        } else if(j>0 && typed[j-1] == typed[j]){
            return solve(name, typed, i, j+1);
        }
        return false;
    }
public:
    bool isLongPressedName(string name, string typed) {
        return solve(name, typed, 0, 0);
    }
};