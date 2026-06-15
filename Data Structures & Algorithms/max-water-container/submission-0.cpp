class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, h = heights.size()-1, result = INT_MIN;

        while(l<h) {
            result = max(result, min(heights[l], heights[h]) * (h-l));

            if(heights[l] < heights[h]) {
                l++;
            } else {
                h--;
            }
        }

        return result;
    }
};
