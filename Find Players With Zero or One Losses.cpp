class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int>mp;
        for(auto it:matches){
            int u=it[0];
            int v=it[1];
            mp[v]++;
        }
        vector<int>tmp1,tmp2;
        for(auto it:matches){
            int u=it[0];
            int v=it[1];
            if(mp.find(u)==mp.end()){
                tmp1.push_back(u);
                mp[u]=2;
            }
            if(mp[v]==1){
                tmp2.push_back(v);
            }
        }
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        return {tmp1,tmp2};
    }
};
