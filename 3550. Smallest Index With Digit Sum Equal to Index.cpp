class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            int x=0;
            for(int j=0;j<s.size();j++){
                x+=s[j]-'0';
            }
            if(x==i)return i;
        }
        return -1;
    }
};
