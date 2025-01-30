class Solution{   
public:
    string printMinNumberForPattern(string S){
        string res="";
        char num='1';
        
        int i=0;
        while(i<S.size()) {
            string str="";
            
            while(i<S.size() && S[i]=='D') {
                str=num+str;
                num++, i++;
            }
            
            str=num+str;
            num++, i++;
            
            res+=str;
            
            str="";
            
            while(i<S.size() && S[i]=='I') {
                res+=num;
                num++, i++;
            }
            
            if(i==S.size()) res+=num;
        }
        return res;
    }
};
