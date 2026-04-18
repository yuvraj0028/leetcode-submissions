class Solution {
private:
    int reverse(int n) {
        int res = 0;
        while(n) {
            int dig = n%10;
            res = (res * 10) + dig;
            n/=10;
        }
        return res;
    }

public:
    int mirrorDistance(int n) {
        int reversed = reverse(n);
        return abs(reversed - n);
    }
};