class Solution {
public:
    void dfs(vector<int>& edges,vector<int>&vis,vector<int>&dist,int node){
        vis[node]=1;
        int v=edges[node];
        if(v!=-1&&!vis[v]){
            dist[v]=1+dist[node];
            dfs(edges,vis,dist,v);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();

        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        dist1[node1]=0;
        dist2[node2]=0;

        vector<int>vis1(n,0);
        vector<int>vis2(n,0);

        dfs(edges,vis1,dist1,node1);
        dfs(edges,vis2,dist2,node2);

        int mn=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int mx=max(dist1[i],dist2[i]);
            if(mn>mx){
                mn=mx;
                ans=i;
            }
        }
        return ans;
    }
};
