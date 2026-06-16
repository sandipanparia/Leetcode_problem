class Solution {
public:
    string r(string s){
        string x=s;
        int n=s.size();
        int l=0,r=n-1;
        while(l<=r){
            swap(x[l],x[r]);
            l++;r--;
        }
        return x;
    }
    string processStr(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(ans.size()>0){
                    ans.pop_back();
                }
            }
            else if(s[i]=='#'){
                ans+=ans;
            }
            else if(s[i]=='%'){
                string x=r(ans);
                ans=x;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
