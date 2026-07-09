class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n);
        int cmp=0;
        comp[0]=0;
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>maxDiff){
                cmp++;
            }
            comp[i]=cmp;
        }
        vector<bool>res;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            res.push_back(comp[u]==comp[v]);
        }
        return res;
    }
};
