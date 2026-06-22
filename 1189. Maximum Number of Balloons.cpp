class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        int n=text.size();
        for(int i=0;i<n;i++){
            mp[text[i]]++;
        }
        string s="balloon";
        int ans=INT_MAX;
        for(char ch:s){
            if(ch=='l'||ch=='o'){
                ans=min(ans,mp[ch]/2);
            }
            else
                ans=min(ans,mp[ch]);

        }
        if(ans==INT_MAX)return 0;
        else return ans;
    }
};
