class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        long long cnt=1;
        long long ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                cnt++;
            }
            else{
                ans=(ans+cnt*(cnt+1)/2)%mod;
                cnt=1;
            }
        }
        ans=(ans+cnt*(cnt+1)/2)%mod;
        return ans%mod;
    }
};
