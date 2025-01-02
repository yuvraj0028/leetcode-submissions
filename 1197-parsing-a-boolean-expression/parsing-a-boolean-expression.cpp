class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for(const char &ch : expression){
            if(ch == ',') continue;

            if(ch == ')'){
                char result;

                vector<char> subExpression;

                while(stk.top() != '('){
                    subExpression.push_back(stk.top());
                    stk.pop();
                }

                stk.pop();

                char lastOperator = stk.top();
                stk.pop();

                if(lastOperator == '!'){
                    result = subExpression[0] == 't' ? 'f' : 't'; 
                } else if(lastOperator == '&'){
                    result = 't';

                    for(const char &opr : subExpression){
                        if(opr == 'f'){
                            result = 'f';
                            break;
                        }
                    }
                } else if(lastOperator == '|'){
                    result = 'f';

                    for(const char &opr : subExpression){
                        if(opr == 't'){
                            result = 't';
                            break;
                        }
                    }
                }

                stk.push(result);
            } else {
                stk.push(ch);
            }
        }

        return stk.top() == 't';
    }
};