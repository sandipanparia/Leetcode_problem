class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&mp,int curr,int par,vector<bool>&hasApple){
        int t=0;
        for(auto it:mp[curr]){
            if(it==par)continue;
            int x=dfs(mp,it,curr,hasApple);
            if(x>0||hasApple[it]==true){
                t+=x+2;
            }
        }
        return t;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        return dfs(mp,0,-1,hasApple);
    }
};
