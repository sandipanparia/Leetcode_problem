class Solution {
public:
    int solve(int i,int j,vector<int>&nums){
        if(i==j)return nums[i];
        if(i>j)return 0;
        int take_i=nums[i]+min(solve(i+1,j-1,nums),solve(i+2,j,nums));
        int take_j=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int p1=solve(0,nums.size()-1,nums);
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        int p2=s-p1;
        if(p1>=p2)return true;
        else return false;
    }
};
