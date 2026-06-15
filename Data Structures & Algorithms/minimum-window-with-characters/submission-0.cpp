class Solution {
public:
    string minWindow(string s, string t) {
        int charMap[256] = {0}, currMap[256] = {0}, found = 0,unique = 0, currUnique = 0;

        for(auto &c: t) {
            charMap[c]++; 
            if(charMap[c]==1) unique++;
        }

        int l = 0, h = 0, n = s.size(), foundLength = INT_MAX;
        string result = "";

        while(h<n) {
            currMap[s[h]]++;
            if(currMap[s[h]] == charMap[s[h]]) {
                currUnique++;
            }

            if(currUnique == unique){
                while(unique == currUnique) {
                    
                    if(currMap[s[l]] == charMap[s[l]]) {
                        currUnique--;
                    }
                    currMap[s[l]]--;
                    l++;
                }
                if(h-l+2 < foundLength) {
                    foundLength = h-l+2;
                    result = s.substr(l-1, h-l+2);
                }
            }
            
            // cout<<h<<" "<<l<<" "<<currUnique<<" "<<found<<endl;
            
            h++;
        }
        return result;
    }
};
