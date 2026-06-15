class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        auto comp = [&] (const pair<int,int> &a, const pair<int,int>&b) {
            return a.second > b.second;
        };

        vector<pair<int,int>> cars;
        int n = position.size();
        for(int i = 0;i<n;i++) {
            cars.push_back({speed[i], position[i]});
        }
        sort(cars.begin(), cars.end(), comp);

        stack<double> st;
        double pres = 1e-7;

        for(int i = 0;i<n;i++) {
            double time = double(target - cars[i].second)/cars[i].first;
            if(st.empty()) {
                st.push(time);
            } else if (st.top()+pres <  time) {
                st.push(time);
            }
        }
    return st.size();

    }
};
