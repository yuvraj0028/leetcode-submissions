class Solution {
public:
    string decodeString(string s) {
        // Stack to store the counts (k)
        std::stack<int> countStack;
        // Stack to store the partial strings (decoded string before the current bracket)
        std::stack<string> resultStack;
        
        string currentString = "";
        int k = 0; // Stores the current accumulated number

        for (char ch : s) {
            if (isdigit(ch)) {
                // Parse the full multi-digit number k
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                // 1. Save the current state before entering the nested segment
                countStack.push(k);
                resultStack.push(currentString);
                
                // 2. Reset k and currentString for the new segment
                k = 0;
                currentString = "";
            } else if (ch == ']') {
                // 1. Get the repeat count and previous string
                int repeatCount = countStack.top();
                countStack.pop();
                
                string prevString = resultStack.top();
                resultStack.pop();
                
                // 2. Repeat the currentString
                string repeatedString = "";
                for (int i = 0; i < repeatCount; ++i) {
                    repeatedString += currentString;
                }
                
                // 3. Update the currentString: previous segment + repeated segment
                currentString = prevString + repeatedString;
            } else {
                // Must be a letter: append it to the current string
                currentString += ch;
            }
        }

        return currentString;
    }
};