class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1, mid, ans = INT_MAX;

        while(l<=h) {
            mid = (l+h)/2;

            if(target == nums[mid] ) {
                return mid;
            } else {
                if(nums[l] <= nums[mid] ) {
                    if(nums[l] <= target && target < nums[mid]) {
                        h = mid-1;
                    } else {
                        l = mid+1;
                    }
                } else {
                    if(nums[mid] < target && target <= nums[h]) {
                        l = mid+1;
                    } else {
                        h = mid-1;
                    }
                }
            }
            // cout<<ans<<endl;
        }

        return -1;
    }
};
