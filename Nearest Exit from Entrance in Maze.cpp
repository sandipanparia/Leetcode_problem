class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int  n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int dx[4]={0,-1,0,+1};
        int dy[4]={-1,0,+1,0};
        int step=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto it=q.front();
                q.pop();
                int i=it.first;
                int j=it.second;
                
                if(!(i==entrance[0]&&j==entrance[1])&&(i==0||i==n-1||j==0||j==m-1))return step;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0&&ni<n&&nj>=0&&nj<m&&maze[ni][nj]!='+'){
                        q.push({ni,nj});
                        maze[ni][nj]='+';
                    }
                }
            }
            step++;
        }
        return -1;
        
    }
};
