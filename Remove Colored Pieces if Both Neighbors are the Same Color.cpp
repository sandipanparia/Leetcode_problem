class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        int n=colors.size();
        for(int i=1;i<n-1;i++){
            if(colors[i-1]==colors[i]&&colors[i]==colors[i+1]&&colors[i]=='A')a++;
            if(colors[i-1]==colors[i]&&colors[i]==colors[i+1]&&colors[i]=='B')b++;
        }
        if((a-b)>0)return true;
        else return false;
    }
};
