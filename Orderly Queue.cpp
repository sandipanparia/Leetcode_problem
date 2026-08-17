class Solution {
public:
    string orderlyQueue(string s, int k) {
        string r=s;
        if(k==1){
            for(int i=1;i<s.size();i++){
                string tmp=s.substr(i)+s.substr(0,i);
                r=min(r,tmp);
            }
            return r;
        }
        sort(s.begin(),s.end());
        return s;
    }
};
