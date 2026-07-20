class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        v[0]=nums[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+nums[i];
        }
        int ind=-1;
        if(v[n-1]-v[0]==0)return 0;
        for(int i=1;i<n;i++){
            int r=v[n-1]-v[i];
            if((r==v[i-1])&&i>0){
                ind=i;
                break;
            }

        }
        return ind;
        
    }
};
