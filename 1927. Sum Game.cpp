class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftSum=0,rightSum=0;
        int leftQMark=0,rightQMark=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftQMark++;
                }
                else{
                    rightQMark++;
                }
            }
            else{
                if(i<n/2){
                    leftSum+=num[i]-'0';
                }
                else{
                    rightSum+=num[i]-'0';
                }
            }
        }
        int t=leftQMark+rightQMark;
        if(t%2==1)return true;

        int l=2*leftSum+9*leftQMark;
        int r=2*rightSum+9*rightQMark;
        if(l==r)return false;
        else return true;
    }
};
