class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>divFreq(mx+1,0);
        for(int i=0;i<n;i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    divFreq[j]++;
                    if(j!=nums[i]/j){
                        divFreq[nums[i]/j]++;
                    }
                }
            }
        }
        vector<long long>pairCounter(mx+1,0);
        for(int g=mx;g>=1;g--){
            long  long cnt=divFreq[g];
            pairCounter[g]=cnt*(cnt-1)/2;

            for(int mul=2*g;mul<=mx;mul+=g){
                pairCounter[g]-=pairCounter[mul];
            }
        }
        vector<long long >prefixCountGcd(mx+1,0);
        for(int g=1;g<=mx;g++){
            prefixCountGcd[g]=prefixCountGcd[g-1]+pairCounter[g];
        }
        vector<int>res;
        for(long long it:queries){
            int l=1;
            int r=mx;
            int tmp=1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(prefixCountGcd[mid]>it){
                    tmp=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
