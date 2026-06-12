class Solution {
public:
    int n,col,m=1e9+7;
    unordered_map<int,vector<int>>adj;
    vector<vector<int>>ancestorTable;
    vector<int>depth;
    void dfs(int root,int parent){
        ancestorTable[root][0]=parent;
        
        for(auto it:adj[root]){
            if(it==parent)continue;
            depth[it]=depth[root]+1;
            dfs(it,root);
        }

    }
    void buildAncestorTable(){
        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                if(ancestorTable[node][j-1]!=-1){
                    ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
                }

            }
        }
    }
    int findLCA(int u,int v){
        if(depth[u]<depth[v]){
            swap(u,v);
        }
        int k=depth[u]-depth[v];
        for(int j=0;j<col;j++){
            if(k&(1<<j)){
                u=ancestorTable[u][j];
            }
        }
        if(u==v)return u;//both are in the same path
        for(int j=col-1;j>=0;j--){
            if(ancestorTable[u][j]==-1){
                continue;
            }

            if(ancestorTable[u][j]!=ancestorTable[v][j]){
                u=ancestorTable[u][j];
                v=ancestorTable[v][j];
            }
        }
        return ancestorTable[u][0];  //ancestorTable[v][0];

    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=edges.size()+1;// total no of nodes
        col=log2(n)+1;

        for(auto it:edges){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        depth.resize(n,0);
        ancestorTable.resize(n,vector<int>(col,-1));
        dfs(0,-1);
        buildAncestorTable();

        //Precompute power of 2
        vector<int>pow2(n+1);
        pow2[0]=1;
        for(int i=1;i<=n;i++){
            pow2[i]=(2LL*pow2[i-1])%m;
        }
        vector<int>res;
        for(auto it:queries){
            int u=it[0]-1;
            int v=it[1]-1;

            int lca=findLCA(u,v);
            int d=depth[u]+depth[v]-2*depth[lca];

            if(d==0){
                res.push_back(0);
            }
            else{
                res.push_back(pow2[d-1]);
            }
        }
        return res;

    }
};
