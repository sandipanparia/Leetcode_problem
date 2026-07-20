class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>a(n*m);
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[x]=grid[i][j];
                x++;
            }
        }
        k=k%(n*m);
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
        vector<vector<int>>ans;
        x=0;
        for(int i=0;i<n;i++){
            vector<int>tmp(m);
            for(int j=0;j<m;j++){
                tmp[j]=a[x];
                x++;
            }
            ans.push_back(tmp);
        }
        return ans;
        
    }
};
