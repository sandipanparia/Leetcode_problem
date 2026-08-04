//  DFS approach--->
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&mp,int src,int dest,vector<bool>&vis){
        if(src==dest)return true;
        if(vis[src]==true)return false;
        vis[src]=true;
        for(auto it:mp[src]){
            if(dfs(mp,it,dest,vis))return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        return dfs(mp,source,destination,vis);
    }
};

//bfs approach----->
class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(t==destination)return true;
            for(auto it:mp[t]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        return false;
    }
};
