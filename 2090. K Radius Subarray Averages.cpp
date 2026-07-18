class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n,0);
        vector<int>res(n,-1);
        if(k==0)return nums;
        if(n<2*k+1)return res;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=k;i<n-k;i++){
            int l=i-k;
            int r=i+k;
            long long s=prefix[r];
            if(l>0){
                s-=prefix[l-1];
            }
            res[i]=s/(2*k+1);
        }
        return res;
    }
};
