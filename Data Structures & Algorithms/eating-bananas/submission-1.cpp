class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid ;
        int ans = high;
        while(low < high) {
            mid = (low+high)/2;
            cout<<mid<<" ";
            if(findHours(piles, mid) <= h) {
                high = mid;
                ans = mid;
                
            } else {
                low = mid+1;
            }
        }

        return ans;

    }

    int findHours(vector<int>& piles, int rate) {
        int hours = 0;
        for(auto &p: piles) {
            hours += ceil(double(p)/rate);
        }
        return hours;
    }
};
