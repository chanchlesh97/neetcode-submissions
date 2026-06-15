class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> result(n, 0);

        stack<int> st;
        for(int i = 0;i<n;i++) {
            if(st.empty() || temps[st.top()] >= temps[i]) {
                st.push(i);
            } else {
                while(!st.empty() && temps[st.top()] < temps[i]) {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};
