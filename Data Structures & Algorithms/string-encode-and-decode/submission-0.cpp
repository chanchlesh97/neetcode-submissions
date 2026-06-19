class Solution {
public:

    string encode(vector<string>& strs) {
        string enString = "";
        for(auto &s: strs) {
            enString += s+"#^#";
        }
        // enString.pop_back();
        return enString;
    }

    vector<string> decode(string s) {
        vector<string> deString;
        string temp = "";
        for(int i = 0;i<s.size();) {
            if(s[i] == '#' && i + 2 < s.size() && s[i+1] == '^' && s[i+2] == '#' ) {
                deString.push_back(temp);
                temp = "";
                i+=2;
            } else {
                temp += s[i];
            }
            i++;
        }
        // if(temp) {
        //     deString.push_back(temp);
        // }
        return deString;
    }

    
};
