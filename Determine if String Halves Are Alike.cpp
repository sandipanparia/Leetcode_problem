class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int mid=n/2;
        mid--;
        int x=0,y=0;
        for(int i=0;i<=mid;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')x++;
        }
        for(int i=mid+1;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')y++;
        }
        return x==y;
    }
};
