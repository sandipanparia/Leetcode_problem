class Solution {
public:
    struct State{
        int r;
        int c;
        int el;
        int coll;
    };
    using VB=vector<bool> ;
    using VVB=vector<VB> ;
    using VVVB=vector<VVB> ;
    using VVVVB=vector<VVVB> ;
    int dr[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();
        int mxE=energy;
        int litt[20][20];
        int littno=0;
        int sr=0,sc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                litt[i][j]=-1;
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(classroom[i][j]=='L'){
                    litt[i][j]=littno;
                    littno++;
                }
            }
        }
        int allo=(1<<littno)-1;
        VVVVB vis(n,VVVB(m,VVB(energy+1,VB(allo+1,false))));
        queue<State>q;
        q.push({sr,sc,mxE,0});
        vis[sr][sc][mxE][0]=true;
        int move=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                State curr=q.front();
                q.pop();
                if(curr.coll==allo)return move;
                if(curr.el==0)continue;

                for(auto it: dr){
                    int nr=curr.r+it[0];
                    int nc=curr.c+it[1];

                    if(nr<0||nr>=n||nc<0||nc>=m)continue;

                    char ch=classroom[nr][nc];

                    int nxE=curr.el-1;
                    int mask=curr.coll;

                    if(ch=='X')continue;
                    if(ch=='R'){
                        nxE=mxE;
                    }
                    if(ch=='L'){
                        mask |= (1<< litt[nr][nc]);
                    }
                    if(!vis[nr][nc][nxE][mask]){
                        vis[nr][nc][nxE][mask]=true;
                        q.push({nr,nc,nxE,mask});
                    }
                }
            }
            move++;
        }
        return -1;
    }
};
