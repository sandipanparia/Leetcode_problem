class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long ans=1e5;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                long long s=nums[i]+nums[j]+nums[k];
                if(abs(target-s)<abs(target-ans)){
                    ans=s;
                }
                if(s<target)j++;
                else k--;
            }
        }
        return (int)ans;

    }
};
