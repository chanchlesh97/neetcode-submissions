class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), curr = 1;
        vector<int> suffProd(n+1, 1);

        for(int i = n-1;i>=0;i--) {
            curr *= nums[i];
            suffProd[i] = curr;
        }
        curr = 1;
        int temp = 1;
        for(int i = 0;i<n;i++) {
            temp = nums[i];
            nums[i] = curr * suffProd[i+1];
            curr*= temp;
        }
        return nums;
    }
};
