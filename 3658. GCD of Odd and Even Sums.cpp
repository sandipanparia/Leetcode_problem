class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            a+=(2*i-1);
            b+=2*i;
        }
        return __gcd(a,b);
        
    }
};
