class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        if(n == 1 && preorder[0] == '#') return true;
        if(n == 1 || n == 2 || preorder[n-1] != '#' || preorder[n-3] != '#') return false;

        int counter = 0;

        for(int i=0; i<n-2; i++){
            if(preorder[i] == ',') continue;
            else if(preorder[i] != '#'){
                while(preorder[i+1] != ',') i++;
                counter++;
            }
            else counter--;
            if(counter < 0) return false;
        }

        return true;
    }
};