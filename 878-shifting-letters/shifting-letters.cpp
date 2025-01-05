class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();        
        
        // finding totalSum to add shifts from 
        long long totalSum = accumulate(shifts.begin(), shifts.end(), 0LL);

        for(int i = 0; i < n; i++){
            // getting the ascii value of character
            long long ascii = s[i] - 97;

            // adding shifts to character
            ascii += totalSum;

            // reducing current shift for nxt characters
            totalSum-=shifts[i];

            // replacing the character whith new shift
            s[i] = (char)((ascii % 26) + 97);
        }

        return s;
    }
};