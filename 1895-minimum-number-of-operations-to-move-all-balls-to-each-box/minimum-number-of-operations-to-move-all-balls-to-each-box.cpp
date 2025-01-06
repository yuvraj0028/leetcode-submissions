class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n);

        int rightOnes = 0;
        int leftOnes = 0;
        int sum = 0;
        int prefixSum = 0;

        for(int i =0; i<n; i++){
            if(boxes[i] == '1'){
                rightOnes++;
                sum+=i;
            }
        }

        for(int i = 0; i<n; i++){
            int moves = sum + prefixSum;

            result[i] = moves;

            if(boxes[i] == '1'){
                rightOnes--;
                leftOnes++;
            }

            prefixSum += leftOnes;
            sum -= rightOnes;
        }

        return result;
    }
};