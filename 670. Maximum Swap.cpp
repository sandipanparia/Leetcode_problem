class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int>v(n);
        v[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            int ind=v[i+1];
            char m=s[ind];
            v[i]=s[i]>m? i: ind;
        }

        for(int i=0;i<n;i++){
            int ind=v[i];
            char m=s[ind];

            if(s[i]<m){
                swap(s[i],s[ind]);
                return stoi(s);
            }
        }
        return num;
        
    }
};
