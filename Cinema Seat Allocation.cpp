class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto it:reservedSeats){
            int row=it[0];
            int b=it[1];
            mp[row].insert(b);
        }
        int res=(n-mp.size())*2;
        for(auto it:mp){
            auto f=[&](int x){
                return it.second.find(x)==it.second.end();
            };
            bool a=f(2)&&f(3)&&f(4)&&f(5);
            bool b=f(4)&&f(5)&&f(6)&&f(7);
            bool c=f(6)&&f(7)&&f(8)&&f(9);

            if(a&&c){
                res+=2;
            }
            else if(a||b||c)res++;
        }
        return res;
    }
};
