class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int t=0;
        int p=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if(i>0&&colors[i]!=colors[i-1]){
                p=0;
            }
            int c=neededTime[i];
            t+=min(p,c);
            p=max(p,c);
        }
        return t;
    }
};
