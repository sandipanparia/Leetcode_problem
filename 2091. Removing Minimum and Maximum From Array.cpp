class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int mx=INT_MIN;
        int mn=INT_MAX;
        int mxi=-1;
        int mni=-1;
        for(int i=0;i<n;i++){
            if(mn>nums[i]){
                mn=nums[i];
                mni=i;
            }
            if(mx<nums[i]){
                mx=nums[i];
                mxi=i;
            }
        }
        int x=(mni-0+1);
        int y=(mxi-0+1);
        int p=(n-mxi);
        int q=(n-mni);
        int s=max(x,y);
        int r=max(p,q);
        int qq=min(x,y)+min(p,q);
        return min({s,r,qq});
        
    }
};
