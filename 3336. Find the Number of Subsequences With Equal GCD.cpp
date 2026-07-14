class Solution {
public:
    int m=1e9+7;
    int solve(vector<int>& nums,int i,int f,int s,vector<vector<vector<int>>>&v){
        if(i==nums.size()){
            bool a=(f!=0) && (s!=0);
            bool b=(f==s);
            return a&&b ? 1:0;
        }
        if(v[i][f][s]!=-1)return v[i][f][s];

        int skip=solve(nums,i+1,f,s,v);
        
        int t1=solve(nums,i+1,__gcd(f,nums[i]),s,v);

        int t2=solve(nums,i+1,f,__gcd(s,nums[i]),v);

        return v[i][f][s]=((skip+t1)%m+t2)%m;

    }
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<vector<int>>>v(nums.size()+1,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(nums,0,0,0,v);
    }
};
