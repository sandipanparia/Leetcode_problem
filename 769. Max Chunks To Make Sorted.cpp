class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 1;
        int mx=arr[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
            if(mx==i)cnt++;

        }
        return cnt;
        
    }
};
