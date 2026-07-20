class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(auto it: strs){
            string s=it;
            sort(it.begin(),it.end());
            mp[it].push_back(s);
        }
        vector<vector<string>>res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
