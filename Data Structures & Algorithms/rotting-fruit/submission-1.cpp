class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, size, minutes = -1;
        pair<int,int> temp;
        queue<pair<int, int>> q;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        int dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}}, xx, yy;
        if (fresh == 0) return 0;
        while(!q.empty()) {
            size = q.size();
            minutes++;
            // cout<<size<<endl;
            while(size--) {
                temp = q.front();
                q.pop();

                for(int i =0;i<4;i++) {
                    xx = temp.first + dir[i][0];
                    yy = temp.second + dir[i][1];

                    if(isValid(xx, yy, m, n) && grid[xx][yy] == 1) {
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                        fresh--;
                    }
                }
            }
            
        }

        return fresh == 0 ?  minutes : -1;
    }
    bool isValid( int x, int y, int &m, int &n) {
        if(x<0 || y<0 || x>= m || y >=n) return false;
        return true;
    }
};
