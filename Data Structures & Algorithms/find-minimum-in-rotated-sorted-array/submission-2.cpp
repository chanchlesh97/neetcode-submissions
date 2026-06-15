class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, h = nums.size()-1, mid, ans = INT_MAX;

        while(l<=h) {
            mid = (l+h)/2;

            if(nums[l] <= nums[mid] ) {
                ans = min(ans, nums[l]);
                l = mid+1;
            } else {
                ans = min(ans, nums[mid]);
                h = mid-1;
            }
            // cout<<ans<<endl;
        }

        return ans;
    }
};
