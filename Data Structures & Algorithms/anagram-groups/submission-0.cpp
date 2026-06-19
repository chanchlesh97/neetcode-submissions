class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> anaMap;
        string temp;
        for(auto &s: strs) {
            temp = s;
            sort(temp.begin(), temp.end());
            anaMap[temp].push_back(s);
        }

        for(auto &e: anaMap) {
            result.push_back(e.second);
        }
        return result;
    }
};
