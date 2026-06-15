class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visited[256] = {false};

        int prev = 0, curr = 0, n = s.size(), result = 0;
        while(curr < n) {
            if(visited[s[curr]]) {
                while(prev < curr && visited[s[curr]]) {
                    visited[s[prev]] = false;
                    prev++;
                }
            } else {
                result = max(result, curr - prev + 1);
            }
            visited[s[curr]] = true;
            curr++;
        }

        return result;
    }
};
