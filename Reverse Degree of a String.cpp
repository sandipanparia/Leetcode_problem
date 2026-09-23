class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int x='z'-s[i]+1;
            ans+=(x*(i+1));
        }
        return ans;
    }
};
