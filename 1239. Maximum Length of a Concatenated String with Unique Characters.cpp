class Solution {
public:
    bool hasDuplicate(string s,string t){
        vector<int>v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
          for(int i=0;i<t.size();i++){
            v[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]>1)return true;
        }
        return false;
    }
    int f(int i,int j,vector<string>& arr,string tmp){
        if(i>j)return tmp.size();

        
        int in=0;
        int ex=0;
        if(hasDuplicate(tmp,arr[i])){
            ex=f(i+1,j,arr,tmp);
        }
        else{
            ex=f(i+1,j,arr,tmp);
            in=f(i+1,j,arr,tmp+arr[i]);
        }

        return max(in,ex);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string tmp="";
       
        return f(0,n-1,arr,tmp);
        
    }
};
