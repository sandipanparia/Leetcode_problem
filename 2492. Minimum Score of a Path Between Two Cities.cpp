class Solution {
public:
    void dfs(int src,vector<vector<pair<int,int>>>&v,vector<bool>&vis,int &res){
        vis[src]=true;
        for(auto it: v[src]){
            int node=it.first;
            int d=it.second;
            res=min(res,d);
            if(vis[node]==false){
                dfs(node,v,vis,res);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>v(n+1);
        for(auto it: roads){
            int a=it[0];
            int b=it[1];
            int d=it[2];
            v[a].push_back({b,d});
            v[b].push_back({a,d});
        }
        vector<bool>vis(n+1,false);
        int res=INT_MAX;
        dfs(1,v,vis,res);
        return res;

    }
};
