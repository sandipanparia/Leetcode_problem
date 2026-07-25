class Solution {
public:
    int maxProduct(int n) {
        long long mx=INT_MIN;
        long long mx1=INT_MIN;
        int N=n;
        while(n>0){
            long long r=n%10;
            mx=max(mx,r);
            n/=10;
        }
        int cnt=0;
        while(N>0){
            long long r=N%10;
            if(r==mx)cnt++;
            if(cnt==2)return (int)mx*mx;
            if(r!=mx)mx1=max(mx1,r);                            
            N/=10;
        }
        return (int)mx*mx1;
    }
};
