class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>r(n,0);
        int i=n-1,j=m-1;
        int cnt=0;
        while(i>=0){
            if(j>=0&&word1[i]==word2[j]){
                cnt++;
                j--;
            }
            r[i]=cnt;
            i--;
        }
        i=0;j=0;
        vector<int>ans;
        bool f=true;
        while(i<n&&j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(f&&i+1<n&&r[i+1]>=m-j-1){
                ans.push_back(i);
                f=0;
                j++;
            }
            i++;
        }
        if(j==m)return ans;
        else return {};
    }
};
