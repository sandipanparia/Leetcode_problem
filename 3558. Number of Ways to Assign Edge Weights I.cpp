class Solution {
public:
    
    int m=1e9+7;
    long long powermod(int base,int expoential){
        if(expoential==0){
            return 1;
        }
        long long half=powermod(base,expoential/2);
        long long res=(half*half)%m;
        if(expoential%2==1){
            res=(res*base)%m;
        }
        return res;
    }
    int getDepth(unordered_map<int,vector<int>>&mp,int node,int par){
        int d=0;
        for(auto it: mp[node]){
            if(it==par)continue;
            d=max(d,getDepth(mp,it,node)+1);
        }
        return d;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto it: edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int depth=getDepth(mp,1,-1);
        return powermod(2,depth-1);
    }
};
