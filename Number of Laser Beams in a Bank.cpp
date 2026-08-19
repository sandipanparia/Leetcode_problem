class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prev=0;
        int res=0;
        for(int i=0;i<n;i++){
            int curr=0;
            for(auto it:bank[i]){
                if(it=='1')curr++;
            }
            res+=(curr*prev);
            if(curr!=0)prev=curr;
        }
        return res;
    }
};
