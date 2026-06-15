class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, h = m*n-1, mid;

        int x,y;

        while(l<=h) {
            mid = (l+h)/2;
            x = mid/m;
            y = mid%m;
            cout<<x<<" "<<y<<endl;
            if(matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return false;
    }
};
