class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        int left = (startIndex+n-1)%n, right = (startIndex+1)%n;
        int leftCnt = 1, rightCnt = 1;
        bool foundLeft = false, foundRight = false;

        if(words[startIndex] == target) return 0;

        while(left != startIndex) {
            if(words[left] == target) {
                foundLeft = true;
                break;
            }

            leftCnt++;
            left = (left + n - 1)%n;
        }

        while(right != startIndex) {
            if(words[right] == target) {
                foundRight = true;
                break;
            }

            rightCnt++;
            right = (right + 1)%n;
        }

        if(foundLeft) {
            ans = min(ans, leftCnt);
        }

        if(foundRight) {
            ans = min(ans, rightCnt);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};