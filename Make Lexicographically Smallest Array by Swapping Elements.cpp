class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        int no=0;
        unordered_map<int,int>mp;
        mp[vec[0]]=no;
        unordered_map<int,list<int>>v;
        v[no].push_back(vec[0]);
        for(int i=1;i<n;i++){
            if(vec[i]-vec[i-1]>limit){
                no++;
            }
            mp[vec[i]]=no;
            v[no].push_back(vec[i]);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int x=mp[num];
            res[i]=*(v[x].begin());
            v[x].pop_front();
        }
        return res;
    }
};
