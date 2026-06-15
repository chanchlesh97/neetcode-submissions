class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> countMap;
        vector<int> result;
        int n = nums.size();
        for(int i = 0;i<k-1;i++) {
            countMap[nums[i]]++;
        }
        for(int i = k-1;i<n;i++) {
            countMap[nums[i]]++;
            result.push_back(countMap.rbegin()->first);

            
            if(--countMap[nums[i-k+1]] == 0) {
                countMap.erase(nums[i-k+1]);
            }
        }

        return result;

    }
};
