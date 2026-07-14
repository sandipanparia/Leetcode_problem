class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        string ans;
        vector<int> lastInd(26);
        vector<bool>f(26,false);
        for(int i=0;i<n;i++){
            char ch=s[i];
            lastInd[ch-'a']=i;
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            int ind=ch-'a';

            if(f[ind]==1)continue;
            while(ans.size()>0&&ans.back()>ch&&lastInd[ans.back()-'a']>i){
                f[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            f[ch-'a']=true;

        }
        return ans;
    }
};
