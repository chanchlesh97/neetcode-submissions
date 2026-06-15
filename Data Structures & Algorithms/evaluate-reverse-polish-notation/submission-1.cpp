class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b,c;
        for(auto &t: tokens) {
            if(t == "+") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b+a);
            } else if(t == "-") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b-a);
            } else if(t == "*") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b*a);
            } else if(t == "/") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b/a);
            } else {
                st.push(stoi(t));
            }

        }

        return st.top();
    }
};
