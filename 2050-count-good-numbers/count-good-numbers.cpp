class Solution {
public:
    int mod = 1000000007;

    int countGoodNumbers(long long n) {
        long even = (n+1)/2;
        long odd = n/2;

        long first = pow(5,even)%mod ;
        long second = pow(4,odd)%mod;

        return (int)((first*second)%mod);
    }

    long pow(long x,long n){
        if(n==0) return 1;

        long temp = pow(x,n/2);

        if(n%2==0) return((temp*temp) % mod);

        else {
            return ((x*temp*temp) % mod);
        }
    };
};