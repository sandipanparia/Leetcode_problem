class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        if(s.size()==0)return "";
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty()&&st.top()==s[i])st.pop();
            else st.push(s[i]);
        }
        string t="";
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            t+=ch;
        }
        reverse(t.begin(),t.end());
        return t;
    }
};
