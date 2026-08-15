class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ind=0;
        int i=0;
        while(i<n){
            int cnt=0;
            char ch=chars[i];
            while(i<n&&ch==chars[i]){
                cnt++;
                i++;
            }
            chars[ind]=ch;
            ind++;
            if(cnt>1){
                string s=to_string(cnt);
                for(auto it:s){
                    chars[ind]=it;
                    ind++;
                }
            }
        }
        return ind;
    }
};
