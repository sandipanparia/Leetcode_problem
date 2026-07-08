class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<ll> digitcnt(n);
        vector<ll>digitsum(n);
        vector<ll>digit(n);
        vector<ll>pow10(n+1,0);
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%mod;
        }
        digitcnt[0]=s[0]=='0'? 0:1;
        for(int i=1;i<n;i++){
            digitcnt[i]=digitcnt[i-1]+(s[i]=='0'? 0:1);
        }
        digitsum[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            digitsum[i]=(digitsum[i-1]+(s[i]-'0'))%mod;
        }
        digit[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            if(s[i]!='0')digit[i]=(digit[i-1]*10+(s[i]-'0'))%mod;
            else digit[i]=digit[i-1];
        }
        ll q=queries.size();
        vector<int>res(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            ll sum=digitsum[r]-(l==0? 0:digitsum[l-1]);

            ll k=digitcnt[r]-(l==0? 0:digitcnt[l-1]);
            ll a= (l==0? 0: digit[l-1]);
            ll x=(digit[r]-(a*pow10[k])%mod+mod)%mod;
            res[i]=(x*sum)%mod;
        }
        return res;
    }
};
