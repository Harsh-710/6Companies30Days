class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string,int> mapi;
        
        for(auto word: startWords) {
            sort(word.begin(), word.end());
            mapi[word] = 1;
        }
        
        int ans = 0;
        for(auto word: targetWords) {
            sort(word.begin(), word.end());
            for(int i=0; i < word.length(); i++) {
                string s1 = word.substr(0, i);
                string s2 = word.substr(i+1);
                
                if(mapi[s1+s2] != 0) {
                    ans += 1;
                    break;
                }
            }
        }
        
        return ans;
    }
};