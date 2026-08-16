class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c1=0,c2=0,c0=0;
        for(auto it:stones){
            if(it%3==1)c1++;
            else if(it%3==2)c2++;
            else if(it%3==0) c0++;
        }
        if(c0%2==0){
            return (c1>=1&&c2>=1)&&(c1>=c2||c2>=c1);
        }
        return abs(c1-c2)>=3;
    }
};
