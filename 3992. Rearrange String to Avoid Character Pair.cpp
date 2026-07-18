class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==y)ans.push_back(y);
        }
        for(int i=0;i<n;i++){
            if(s[i]==x)ans.push_back(x);
        }
        for(int i=0;i<n;i++){
            if(s[i]!=x&&s[i]!=y)ans.push_back(s[i]);
        }
        
        
        return ans;
        
        
    }
};
