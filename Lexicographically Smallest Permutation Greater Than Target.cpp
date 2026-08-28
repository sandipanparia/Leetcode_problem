class Solution {
public:
    string res="";
    bool solve(string &curr,string &target,vector<int>&cnt,int i,bool f){
        if(i==target.size()){
            if(f){
                res=curr;
                return true;
            }
            return false;
        }
        for(char ch='a';ch<='z';ch++){
            if(cnt[ch-'a']==0)continue;
            if(!f&&ch<target[i])continue;
            

            curr.push_back(ch);
            cnt[ch-'a']--;
            bool ff=f||ch>target[i];
            if(solve(curr,target,cnt,i+1,ff))return true;

            curr.pop_back();
            cnt[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
       string curr="";
       vector<int>cnt(26,0);
       for(auto it:s){
            cnt[it-'a']++;
       }
       solve(curr,target,cnt,0,false);

       return res;
    }
};
