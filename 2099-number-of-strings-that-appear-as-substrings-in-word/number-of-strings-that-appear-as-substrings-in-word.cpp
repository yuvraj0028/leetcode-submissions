class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int num = 0;
        for(int i = 0; i<patterns.size(); i++) {
            int index = word.find(patterns[i]);
            if(index != -1) num++;
        }
        return num;
    }
};