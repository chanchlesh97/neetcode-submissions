class Solution {
    int dir[4][3] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    int n,m;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(),  m = grid[0].size();
        int result = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]) {
                    result = max(result, findArea(grid, i, j));
                }
            }
        }
        return result;
    }

    int findArea(vector<vector<int>> & grid, int x, int y) {
        if(x<0 || y< 0 || x >= n || y>= m || !grid[x][y]) return 0;
        int xx, yy, area = 1;
        grid[x][y] = 0;
        for(int i = 0;i<4;i++) {
            xx = x+dir[i][0];
            yy = y+dir[i][1];
            area += findArea(grid, xx, yy);

        }

        return area;
    }
};
