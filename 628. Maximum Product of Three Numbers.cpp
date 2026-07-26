class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==3)return nums[n-1]*nums[n-2]*nums[n-3];
        int cnt=0;
        for(int i=0;i<n;i++)if(nums[i]<0)cnt++;
        int c=1;
        if(cnt>=2){
            c=nums[0]*nums[1];
            c*=nums[n-1];
        }
       
        int x=nums[n-1]*nums[n-2]*nums[n-3];
        if(c>x&& cnt>=2)return c;
        else return x;
    }
};
