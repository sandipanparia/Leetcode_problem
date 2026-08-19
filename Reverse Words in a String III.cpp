class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string tmp="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(tmp.begin(),tmp.end());
                tmp+=' ';
                ans+=tmp;
                tmp="";
            }
            else{
                tmp+=s[i];
            }
        }
        reverse(tmp.begin(),tmp.end());
        for(auto it:tmp){
            ans+=it;
        }
        return ans;
    }
};
