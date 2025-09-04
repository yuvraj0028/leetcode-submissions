class Solution {
public:
    int findClosest(int x, int y, int z) {
        int x_steps = abs(z - x);
        int y_steps = abs(z - y);

        if(x_steps == y_steps){
            return 0;
        } else if (x_steps < y_steps){
            return 1;
        } else {
            return 2;
        }
    }
};