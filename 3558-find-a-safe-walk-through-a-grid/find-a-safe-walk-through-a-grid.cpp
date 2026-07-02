class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int startHealth = health - grid[0][0];

        if(startHealth <=0 ) return false;

        queue<tuple<int,int,int>> q;
        q.push({0,0, startHealth});

        //best[i][j] = maximum remaining health seen at cell(i,j);

        vector<vector<int>> best(m, vector<int>(n, -1));
        best[0][0] = startHealth;

        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty())
        {
            auto [r,c,h] = q.front();
            q.pop();

            if(r == m-1 && c == n-1)
            {
                return true;
            }

            for (auto &[dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newHealth = h - grid[nr][nc];

                    if (newHealth > 0 && newHealth > best[nr][nc]) {
                        best[nr][nc] = newHealth;
                        q.push({nr, nc, newHealth});
                    }
                }
            }

        }

        return false;
    }
};