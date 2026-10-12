class Solution {
    
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size(), n = grid[0].size();

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 0 ) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }

        pair<int,int> temp;
        int level = 1, size, xx, yy;
        int dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}};

        while(!q.empty()) {
            size = q.size();

            while(size--) {
                temp = q.front();
                q.pop();

                for(int i = 0;i<4;i++) {
                    xx = temp.first+dir[i][0];
                    yy = temp.second + dir[i][1];

                    if(isValid(xx, yy, m, n) && grid[xx][yy] == INT_MAX) {
                        q.push({xx, yy});
                        grid[xx][yy] = level;
                    }
                }

            }
            level++;
        }
        return ;
    }

    int isValid(int x, int y, int &m, int &n) {
        if(x<0 || y<0 || x>=m || y >= n)return false;
        return true;
    }
};
