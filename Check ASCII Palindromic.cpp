class Solution {
public:
    bool isPalindromic(string s) {
        string ans="";
        for(auto ch:s){
            int x=ch;
            for(int i=7;i>=0;i--){
                ans+=((x>>i)&1)+'0';
            }
        }
        int n=ans.size();
        int l=0,r=n-1;
        while(l<r){
            if(ans[l]!=ans[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
};
