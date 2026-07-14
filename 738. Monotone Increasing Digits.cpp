class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string s=to_string(n);
        int sz=s.size();
        int m=sz;
        for(int i=sz-2;i>=0;i--){
            if(s[i]>s[i+1]){
                s[i]--;
                m=i+1;
            }
        }
        for(int i=m;i<sz;i++){
            s[i]='9';
        }
        return stoi(s);
        
    }
};
