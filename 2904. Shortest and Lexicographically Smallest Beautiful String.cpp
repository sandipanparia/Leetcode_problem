class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        for(int len=k;len<=n;len++){
            string res="";
            for(int i=0;i<=n-len;i++){
                string tmp=s.substr(i,len);
                int cnt=0;
                for(auto ch:tmp){
                    if(ch=='1')cnt++;
                }
                if(cnt==k){
                    if(res.empty()||tmp<res)res=tmp;
                }
            }
            if(!res.empty())return res;
        }
        return "";
    }
};
