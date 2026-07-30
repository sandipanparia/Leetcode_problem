class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8)return n;
        n-=8;
        int ans=8;
        bool f=0;
        for(int i=2;i<=3;i++){
            for(int j=2;j<=9;j++){
                ans+=i;
                n--;
                if(n==0){f=1;break;}
            }
            if(f)break;
        }
        if(n>0)ans+=n*4;
        return ans;
    }
};
