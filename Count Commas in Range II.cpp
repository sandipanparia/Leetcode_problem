class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long long cnt=0;
        long long l=1000;
        long long cm=1;
        while(l<=n){
            long long x=min(n,l*1000-1);
            long long xx=(x-l+1);
            cnt+=(xx*cm);
            if(l>n/1000)break;
            l=l*1000;
            cm++;
        }
        return cnt;
    }
};
