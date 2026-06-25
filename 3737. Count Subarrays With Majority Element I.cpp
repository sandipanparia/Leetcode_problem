class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>a(n);
        for(int i=0;i<n;i++){
            if(nums[i]==target)a[i]=1;
            else a[i]=-1;
        }
        vector<int>p(n+1,0);
        
        for(int i=0;i<n;i++){
            p[i+1]=p[i]+a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int s=p[j+1]-p[i];
                if(s>0)ans++;
            }
        }
        return ans;
    }
};
