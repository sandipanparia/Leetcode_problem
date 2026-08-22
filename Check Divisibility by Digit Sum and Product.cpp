class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sz=s.size();
        int x=0,y=1;
        for(int i=0;i<sz;i++){
            x+=(s[i]-'0');
            y*=(s[i]-'0');
        }
        return n%(x+y)==0;
    }
};
