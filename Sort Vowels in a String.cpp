class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<int>ind;
        vector<char>ch;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                ind.push_back(i);
                ch.push_back(s[i]);
            }
        }
        sort(ch.begin(),ch.end());
        for(int i=0;i<ind.size();i++){
            s[ind[i]]=ch[i];
        }
        return s;
    }
};
