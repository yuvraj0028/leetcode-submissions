class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;

        q.push({beginWord,1});

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string word = q.front().first;
                string temp = word;
                int cnt = q.front().second;

                q.pop();

                if(word == endWord) return cnt;

                for(int i = 0; i<word.size(); i++){
                    char ch = temp[i];

                    for(int j = 0; j<26; j++){
                        temp[i] = char(j+97);

                        if(temp != word && st.find(temp) != st.end()){
                            st.erase(temp);
                            q.push({temp,cnt+1});
                        }
                    }

                    temp[i] = ch;
                }
            }
        }
        return 0;
    }
};