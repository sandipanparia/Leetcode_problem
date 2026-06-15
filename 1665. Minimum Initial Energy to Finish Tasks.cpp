class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks,int mid){
        int n=tasks.size();
        for(auto it: tasks){
            int actual=it[0];
            int mini=it[1];
            if(mid<mini){
                return false;
            }
            mid-=actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        auto comp=[](auto &tasks1,auto tasks2){
            int d1=tasks1[1]-tasks1[0];
            int d2=tasks2[1]-tasks2[0];
            return d1>d2;
        };
        sort(tasks.begin(),tasks.end(),comp);
        int l=0;
        int r=1e9;
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(tasks,mid)){
                if(mid<res)res=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
