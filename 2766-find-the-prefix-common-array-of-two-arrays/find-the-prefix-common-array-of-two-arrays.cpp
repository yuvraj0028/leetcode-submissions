class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt = 0;
        int n = A.size();
        vector<int> freq(n+1), res(n);

        for(int i = 0; i<n; i++){
            int a = A[i];
            int b = B[i];

            freq[a]++;
            if(freq[a] == 2) cnt++;
            freq[b]++;
            if(freq[b] == 2) cnt++;

            res[i] = cnt;
        }

        return res;
    }
};