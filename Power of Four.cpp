class Solution {
public:
    bool f(int n){
        while(n!=1){
            if(n%4==0)n/=4;
            else return false;
        }
        if(n==1)return true;
        else return false;
    }
    bool isPowerOfFour(int n) {
        if(n==0)return false;
        return f(n);
    }
};
