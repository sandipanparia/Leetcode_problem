class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>a=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>v;
        int i=0;
        int j=0;
        while(j<n){
            if(v[arr[j]]==0){
                v[arr[j]]=i+1;
                i++;
            }
            j++;
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(v[a[i]]);
        }
        return res; 
    }
};
