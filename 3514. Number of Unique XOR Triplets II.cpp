class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int t=1;
        int mx=*max_element(nums.begin(),nums.end());
        while(t<=mx){
            t<<=1;
        }
        vector<int>s1(t,false);
        vector<int>s2(t,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<t;i++){
            if(s1[i]==true){
                for(auto it: nums){
                    s2[i^it]=true;
                }
            }
        }
        int res=0;
        for(int i=0;i<t;i++){
            if(s2[i]==true)res++;
        }
        return res;
    }
};
