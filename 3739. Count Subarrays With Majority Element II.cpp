class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp[0]=1;
        long long cumSum=0;
        long long validLeftPoints=0;
        long long ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==target){
                validLeftPoints+=mp[cumSum];
                cumSum++;
            }
            else{
                cumSum--;
                validLeftPoints-=mp[cumSum];
            }
            mp[cumSum]++;
            ans+=validLeftPoints;
        }
        return ans;
    }
};
