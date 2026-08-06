class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int o=0;
        int z=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                o++;
            }
            else z++;
        }
        int ans = 1e9;
        ans = min(ans, z);
        ans = min(ans, max(0, o - 1));
        if (n >= 2) {
            int cost = 0;
            if (s[0] != '1') cost++;
            if (s[n - 1] != '1') cost++;
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '1') cost++;
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};
