class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string,int> mp;

        for(int i=0; i<n; i++)
        {
            string row = "";
            for(int j=0; j<n; j++)
            {
                row += to_string(grid[i][j]) + "#";
            }
            mp[row]++;
        }

        int count = 0;

        for(int j=0; j<n; j++)
        {
            string col = "";
            for(int i=0; i<n; i++)
            {
                col += to_string(grid[i][j]) + "#";
            }

            if(mp.count(col))
                count += mp[col];
        }

        return count;
    }
};