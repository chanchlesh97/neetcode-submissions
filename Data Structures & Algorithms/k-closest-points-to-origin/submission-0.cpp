class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first < b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq;

        vector<vector<int>> result;
        int dist, n = points.size();

        for(int i = 0;i<n;i++) {
            dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(pq.size() == k) {
                if(pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist,i});
                }
            } else {
                pq.push({dist, i});
            }
        }
        pair<int,int> temp;
        while(!pq.empty()) {
            temp = pq.top();
            pq.pop();
            result.push_back(points[temp.second]);
        }
        return result;
    }
};
