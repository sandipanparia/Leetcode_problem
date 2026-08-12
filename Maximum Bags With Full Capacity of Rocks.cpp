class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int cnt=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            if((capacity[i]-rocks[i])==0){cnt++;continue;}
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if((additionalRocks-v[i])>=0){
                cnt++;
                additionalRocks-=v[i];
            }
        }
        return cnt;
    }
};
