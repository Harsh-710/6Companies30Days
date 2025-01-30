class Solution {
  public:
    string encode(string s) {
        // code here
       string ans;
       int cnt=1;
       char prev=s[0];
       for(int i=1;i<s.length();i++){
           if(s[i]==prev){
               cnt++;
           }
           else{
               ans+=prev;
               ans+=to_string(cnt);
               prev=s[i];
               cnt=1;
           }
       }
        ans+=prev;
        ans+=to_string(cnt);
       return ans;
    }
};
