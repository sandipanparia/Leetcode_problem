class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long inc=n/2;
        return 1LL*s +inc*m-max(0LL,inc-1);
    }
};
