class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        long long s=0;
        int cnt=0;
        sort(happiness.rbegin(),happiness.rend());
        for(int i=0;i<k;i++){
            s+=max(happiness[i]-cnt,0);
            cnt++;
        }
        return s;
    }
};
