class Solution {
public:
    int minimumPushes(string word) {
        vector<int>cnt(26,0);
        int res=0;
        for(int i=0;i<word.size();i++){
            cnt[word[i]-'a']++;
        }
        sort(cnt.rbegin(),cnt.rend());
        for(int i=0;i<26;i++){
            int fr=cnt[i];
            int press=(i/8+1);
            res+=fr*press;
        }
        return res;
    }
};
