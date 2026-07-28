class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>cnt(26,0);
        for(auto it:s){
            cnt[it-'a']++;
        }
        string l="",m="";
        for(int i=0;i<26;i++){
            l+=string(cnt[i]/2,'a'+i);
            if(cnt[i]%2==1)m='a'+i;
        }
        string r=l;
        reverse(r.begin(),r.end());
        string ans=l+m+r;
        return ans;
    }
};
