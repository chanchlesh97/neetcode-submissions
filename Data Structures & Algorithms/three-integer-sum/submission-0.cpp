class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size(), i = 0, l , r, sum;
        sort(nums.begin(), nums.end());

        while(i< n && nums[i] <= 0) {
            l = i+1, r = n-1;

            while(l<r) {
                sum = nums[l]+nums[r]+nums[i];
                if(sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l] == nums[l+1])l++;
                    while(l<r && nums[r] == nums[r-1])r++;
                    l++;
                    r--;

                }else if(sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
            while(i<n-1 && nums[i] == nums[i+1])i++;
            i++;
        }
        return result;

    }
};
