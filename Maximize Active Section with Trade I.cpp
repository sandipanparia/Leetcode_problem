class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int>v;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt++;
            }
            else{
                if(cnt>0)v.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt>0)v.push_back(cnt);
        cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
        }
        int mx=0;
        if(v.size()<=1)return mx+cnt;
        for(int i=0;i<v.size()-1;i++){
            mx=max(mx,(v[i]+v[i+1]));
        }
        return mx+cnt;
    }
};
