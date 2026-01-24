class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
                int n = grid.size();
        
        // Min-heap: {current_max_height, x, y}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int time = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            // Reached destination
            if (x == n - 1 && y == n - 1) {
                return time;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    int newTime = max(time, grid[nx][ny]);
                    pq.push({newTime, {nx, ny}});
                }
            }
        }
        
        return -1; // never reached
    }
};
