class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto comp = [] (pair<int,int> &a, pair<int,int> &b) {
            return a.first > b.first;
        };
        unordered_map<int,int> countMap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq;
        vector<int> result;
        for(auto &a: nums) {
            ++countMap[a];
        }
        // cout<<countMap.size()<<endl;
        for(auto [key,v] : countMap) {
            if (pq.size() < k) {
                pq.push({v, key});
            }
            else if(pq.size() == k && pq.top().first < v ) {
                pq.pop();
                pq.push({v, key});
            } 
            
        }
        // cout<<pq.size()<<endl;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
