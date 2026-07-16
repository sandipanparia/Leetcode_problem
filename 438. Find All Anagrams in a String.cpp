class Solution {
public:
    bool f(vector<int>&v,string p){
        for(int i=0;i<p.size();i++){
            if(v[p[i]-'a']!=0)return false;
        }
        return true;

    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        vector<int>v(26,0);
        for(int i=0;i<k;i++){
            v[p[i]-'a']++;
        }
        vector<int>res;
        int i=0,j=0;
        while(j<n){
            char ch=s[j];
            v[ch-'a']--;
            if(j-i+1==k){
                if(f(v,p)){
                    res.push_back(i);
                }
                v[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
        
    }
};
