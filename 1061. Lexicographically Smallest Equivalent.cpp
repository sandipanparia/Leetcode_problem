class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&adj,char ch,vector<int>&vis){
        vis[ch-'a']=1;
        char mn=ch;
        for(auto it:adj[ch]){
            if(!vis[it-'a']){
               mn=min(mn, dfs(adj,it,vis));
            }
        }
        return mn;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        int m=baseStr.size();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res="";
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            vector<int>vis(26,0);
            char mn=dfs(adj,ch,vis);
            res.push_back(mn);
        }
        return res;
    }
};
