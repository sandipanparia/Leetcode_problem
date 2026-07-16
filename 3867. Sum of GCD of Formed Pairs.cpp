class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n);
        vector<int>pr(n);
        mx[0]=nums[0];
        for(int i=1;i<n;i++){
            mx[i]=max(mx[i-1],nums[i]);
        }
        for(int i=0;i<n;i++){
            pr[i]=__gcd(nums[i],mx[i]);
        }
        sort(pr.begin(),pr.end());
        int l=0,r=n-1;
        long long s=0;
        while(l<r){
            s+=__gcd(pr[l],pr[r]);
            l++;
            r--;
        }
        return s;
    }
};
