class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), left = height[0], right = height[n-1], l = 0, r = n-1, ans = 0;

        while(l<=r) {
            if(left < right) {
                left = max(left, height[l]);
                ans +=  left - height[l];
                l++;
            } else {
                right = max(right, height[r]);
                ans += right - height[r];
                r--;
            }
        }
        return ans;
    }
};
