class Solution {
public:
    void dfs(int i,unordered_map<int ,vector<int>>&adj,vector<bool>&vis,int &v,int &e){
        vis[i]=true;
        v++;
        e+=adj[i].size();
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int ,vector<int>>adj;
        int res=0;
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int v=0,e=0;
                dfs(i,adj,vis,v,e);

                if((v*(v-1))==e){
                    res++;
                }
            }
        }
        return res;
    }
};
