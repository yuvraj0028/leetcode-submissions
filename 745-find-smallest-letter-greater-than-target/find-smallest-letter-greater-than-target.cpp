class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0;
        int e = letters.size() - 1;
        char c = letters[0];

        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(letters[mid] > target) {
                c = letters[mid];
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return c;
    }
};