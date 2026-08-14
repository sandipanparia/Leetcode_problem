class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int s=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(find(banned.begin(),banned.end(),i)==banned.end()){
                s+=i;
                cnt++;
            }
            if(s>maxSum){cnt--;break;}
        }
        return cnt;
    }
};
