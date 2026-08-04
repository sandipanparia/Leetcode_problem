class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        vector<bool>vis(n,false);
        for(auto it:rooms[0]){
            q.push(it);
            vis[it]=true;
        }
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int top=q.front();
                q.pop();

                for(auto it:rooms[top]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
};
