class Solution {
public:
    int n;
    int mxlen;
    unordered_set<string>st;
    void solve(string &s,int i,int cnt,string& curr){
        if(cnt<0)return;
        if(i==n){
            if(cnt==0){
                if(curr.size()>mxlen){
                    mxlen=curr.size();
                    st.clear();
                }
                if(curr.size()==mxlen){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i]!='('&&s[i]!=')'){
            curr.push_back(s[i]);
            solve(s,i+1,cnt,curr);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        solve(s,i+1,cnt+ (s[i]=='('? 1:-1),curr);
        curr.pop_back();
        solve(s,i+1,cnt,curr);
    }
    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        mxlen=0;
     
        string curr="";
        solve(s,0,0,curr);
        return vector<string>(st.begin(),st.end());
    }
};
