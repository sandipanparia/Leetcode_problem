class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<bool>s(n,false);
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        q.push(k);
        s[k]=true;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it: adj[curr]){
                indegree[it]--;
                if(!s[it]){
                    q.push(it);
                    s[it]=true;
                }
            }
        }
        vector<int>res;
        bool f=false;
        for(int i=0;i<n;i++){
            if(s[i]&&indegree[i]>0){
                f=true;
                break;
            }
            if(!s[i]){
                res.push_back(i);
            }
        }
        if(f){
            vector<int>tmp;
            for(int i=0;i<n;i++){
                tmp.push_back(i);
            }
            return tmp;
        }
        return res;
    }
};
