class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        unordered_map<int,int>v;
        for(auto it:mp){
            v[it.second]++;
        }
        for(auto it:v){
            if(it.second>=2)return false;
        }
        return true;
    }
};
