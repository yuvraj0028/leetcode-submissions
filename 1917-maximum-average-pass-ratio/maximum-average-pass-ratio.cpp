#define Pair pair<pair<int,int>,double> 

// comparator to sort according to difference of potential increase in ratio
class Compare{
public:
    bool operator() (Pair &a, Pair &b){
        double gainA = (double)(a.first.first + 1)/(a.first.second + 1) - (double)(a.first.first)/(a.first.second);
        double gainB = (double)(b.first.first + 1)/(b.first.second + 1) - (double)(b.first.first)/(b.first.second);

        return gainA < gainB;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double avgPassRatio = 0;
        double maxPotential = DBL_MIN;
        
        // heap to track lowest no of students in class 
        priority_queue<Pair ,vector<Pair>, Compare> pq;

        for(vector<int> &cls : classes){
            double tempRatio = (double)(cls[0])/cls[1];
            Pair tempPair = make_pair(make_pair(cls[0],cls[1]),tempRatio);
            pq.push(tempPair);
        }

        while(extraStudents--){
            Pair top = pq.top(); pq.pop();

            // adding based on potential increase of value
            int passed = top.first.first + 1;
            int total = top.first.second + 1;

            double newPassRatio = (double)(passed)/total;

            Pair tempPair = make_pair(make_pair(passed,total),newPassRatio);

            pq.push(tempPair);
        }

        while(!pq.empty()){
            Pair top = pq.top(); pq.pop();
            avgPassRatio+=top.second;
        }

        return (double)(avgPassRatio / n);

    }
};