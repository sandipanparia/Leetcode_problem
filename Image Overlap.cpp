class Solution {
public:
    int count(vector<vector<int>>& img1,vector<vector<int>>& img2,int x,int y){
        int n=img1.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nr=i+x;
                int nc=j+y;
                if(nr>=n||nr<0||nc>=n||nc<0)continue;

                if(img1[i][j]==img2[nr][nc]&&img1[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int mx=INT_MIN;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int x=count(img1,img2,i,j);
                mx=max(mx,x);
            }
        }
        return mx;
    }
};
