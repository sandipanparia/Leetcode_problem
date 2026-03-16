class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int l=0,r=0;
        while(r<n-1){
            int f=0;
            for(int i=l;i<=r;i++){
                f=max(f,i+nums[i]);
            }
            l=r+1;
            r=f;
            j++;
        }
        return j;
    }
};
