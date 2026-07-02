class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        deque<pair<int,int>>dq;
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        res[0][0]=grid[0][0];
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        dq.push_front({0,0});
        while(!dq.empty()){
            auto it=dq.front();
            int r=it.first;
            int c=it.second;
            dq.pop_front();
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr<0||nr>=n||nc<0||nc>=m)continue;
                if(res[nr][nc]>grid[nr][nc]+res[r][c]){
                    res[nr][nc]=grid[nr][nc]+res[r][c];
                    if(grid[nr][nc]==0){
                        dq.push_front({nr,nc});
                    }
                    else{
                        dq.push_back({nr,nc});
                    }
                }
            }
        }
        int x=res[n-1][m-1];
        if(health-x>=1)return true;
        else return false;
    }
};
