class Comparator {
public:
    bool operator()(pair<string, int> a, pair<string, int> b){
        int c1 = count(a.first.begin(), a.first.end(), '1');
        int c2 = count(b.first.begin(), b.first.end(), '1');

        if(c1 == c2){
            return a.second > b.second;
        }

        return c1 > c2;
    }
};

class Solution {
private:
    string convertToBin(int num){
        int temp = num;
        string bin = "";

        while(temp){
            int dig = temp%2;
            bin.push_back(dig + '0');
            temp/=2;
        }

        if(bin == "") bin = "0";

        return bin;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        priority_queue<pair<string, int> , vector<pair<string, int > >, Comparator> pq;

        for(int i = 0; i<arr.size(); i++){
            string bin = convertToBin(arr[i]);
            pq.push({bin, arr[i]});
        }

        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            ans.push_back(top.second);   
        }

        return ans;
    }
};