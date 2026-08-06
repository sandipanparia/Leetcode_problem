class Solution {
public:
    int smallestNumber(int n, int t) {
        long long cnt=1;
        int x=n;
        while(1){
            int c=1;
            int y=x;
            while(y!=0){
                int r=y%10;
                c*=r;
                y/=10;
            }
            if(c%t==0){
                return x;
            }
            x++;
        }
        return -1;
    }
};
