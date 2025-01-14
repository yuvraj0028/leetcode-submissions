class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> open, openClose;

        int n = s.size();

        if(n%2 != 0) return false;

        for(int i = 0;i<n;i++){
            char lock = locked[i];
            char para = s[i];

            if(lock == '0'){
                openClose.push(i);
            } else if(para == '('){
                open.push(i);
            } else {
                if(!open.empty()){
                    open.pop();
                } else if(!openClose.empty()){
                    openClose.pop();
                } else {
                    return false;
                }
            }
        }

        while(!open.empty() && !openClose.empty()){
            if(open.top() > openClose.top()){
                return false;
            }

            open.pop();
            openClose.pop();
        }

        return open.empty();
    }
};