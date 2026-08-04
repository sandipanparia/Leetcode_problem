class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>v(n+1,-1);
        unordered_map<int,vector<int>>mp;
        for(auto it:dislikes){
            int u=it[0];
            int v=it[1];
            mp[u].push_back(v);   
            mp[v].push_back(u);   
        }
        for(int it=1;it<=n;it++){
            if(v[it]!=-1) continue;
            queue<int>q;
            q.push(it);
            v[it]=0;
            while(!q.empty()){
                int top=q.front();
                q.pop();
                for(auto it:mp[top]){
                    if(v[it]==-1){
                        if(v[top]==1)v[it]=0;
                        else if(v[top]==0)v[it]=1;
                        q.push(it);
                    }
                    else{
                        if(v[it]==0&&v[top]==0)return false;
                        else if(v[it]==1&&v[top]==1)return false;
                    }

                }
            }
        }
        return true;
    }
};
