class Solution {
public:
    int row;
    int col;
    vector<vector<int>>ancestorTable;
    int customUpperBound(vector<pair<int,int>>&arr,int target){
        int n=arr.size();
        int l=0;
        int r=n-1;
        int resInd=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid].first<=target){
                resInd=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return resInd;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        sort(arr.begin(),arr.end());
        vector<int>nodeToIndx(n);
        for(int i=0;i<n;i++){
            int node=arr[i].second;
            nodeToIndx[node]=i;
        }
        row=n;
        col=log2(n)+1;
        ancestorTable.resize(row,vector<int>(col,0));
        for(int node=0;node<n;node++){
            int farthesIdxOneHop=customUpperBound(arr,arr[node].first+maxDiff);
            ancestorTable[node][0]=farthesIdxOneHop;
        }
        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }
        vector<int>res;
        for(auto it: queries){
            int u=it[0];
            int v=it[1];

            int a=nodeToIndx[u];
            int b=nodeToIndx[v];
            if(a==b){
                res.push_back(0);
                continue;
            }
            if(a>b)swap(a,b);

            int curr=a;
            int jump=0;
            for(int j=col-1;j>=0;j--){
                if(ancestorTable[curr][j]<b){
                    curr=ancestorTable[curr][j];
                    jump+=(1<<j);
                }
            }
            if(ancestorTable[curr][0]>=b){
                res.push_back(jump+1);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};
