class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=nums[0];
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c){
                c++;
            }
            else{
               res.push_back(c);
               c++;
               i--;
            }
        }
        return res;
        

    }
};
