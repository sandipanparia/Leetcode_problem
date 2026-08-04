class Solution {
public:
    vector<vector<int>>res;
    vector<int>tmp;
    void dfs(int src,int dest,vector<vector<int>>& graph){
        tmp.push_back(src);
        if(src==dest){
            res.push_back(tmp);
        }
        else{
            for(auto it:graph[src]){
                dfs(it,dest,graph);
            }
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        dfs(0,n-1,graph);
        return res;
    }
};
