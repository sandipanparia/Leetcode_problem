class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int curr,int par,vector<int>&res,string &s,vector<int>&cnt){
        char m=s[curr];
        int bf=cnt[m-'a'];
        cnt[m-'a']++;
        for(auto it:mp[curr]){
            if(it==par)continue;
            dfs(mp,it,curr,res,s,cnt);
        }
        int af=cnt[m-'a'];
        res[curr]=af-bf;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<int>res(n);
        vector<int>cnt(26,0);
        dfs(mp,0,-1,res,labels,cnt);
        return res;
    }
};
