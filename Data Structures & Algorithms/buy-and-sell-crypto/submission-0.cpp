class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minVal = prices[0], n = prices.size();

        for(int i = 1;i<n;i++) {
            ans = max(ans, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }

        return ans;

    }
};
