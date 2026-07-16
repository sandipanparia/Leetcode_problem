class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2==1)return {};
        sort(changed.begin(),changed.end());
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[changed[i]]++;
        }
        for(int i=0;i<n;i++){
            int t=2*changed[i];
            if(mp[changed[i]]==0)continue;

            if(mp.find(t)==mp.end()|| mp[t]==0)return {};
            v.push_back(changed[i]);
            mp[changed[i]]--;
            mp[t]--;
        }
        return v;
        
    }
};
