class TimeMap {
    unordered_map<string, vector<pair<int,string>>> container;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        container[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &values = container[key];

        int l = 0, h = values.size()-1, mid;
        string value = "";
        
        while(l<=h) {
            mid = (l+h)/2;
            cout<<values[mid].second<<endl;
            if(values[mid].first == timestamp) {
                return values[mid].second;
            }
            if(values[mid].first <= timestamp) {
                value = values[mid].second;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        return value;
    }
};
