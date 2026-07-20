class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>res;
        for(auto it:mp){
            if(it.first%2!=0){
                for(auto i:it.second)res.push_back(i);
            }
            else{
                reverse(it.second.begin(),it.second.end());
                for(auto i: it.second)res.push_back(i);
            }
        }
        return res;
    }
};
