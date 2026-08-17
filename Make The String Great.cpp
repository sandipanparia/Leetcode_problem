class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        if(n==0)return"";
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty()&&abs(st.top()-s[i])==32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string r="";
        while(!st.empty()){
            r+=st.top();
            st.pop();
            
        }
        reverse(r.begin(),r.end());
        return r;
    }
};
