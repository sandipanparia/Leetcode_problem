class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>a(n,false);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            a[v]=true;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(a[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
