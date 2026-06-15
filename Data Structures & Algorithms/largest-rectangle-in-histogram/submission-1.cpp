class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), ans = INT_MIN;
        vector<int> result(n, 0);
        for(int i = 0;i<n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) {
                result[i] = (i+1)*heights[i];
                
            } else {
                result[i] = (i-st.top()) * heights[i];
            }
            cout<<result[i]<<" ";
            st.push(i);
        }
cout<<endl;
while(!st.empty()) st.pop();
        for(int i = n-1;i>=0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) {
                result[i] += (n-i-1)*heights[i];
                
            } else {
                result[i] += (st.top()-i-1) * heights[i];
            }
            cout<<result[i]<<" ";
            st.push(i);
            ans = max(ans , result[i]);
        }
        return ans;
    }
};
