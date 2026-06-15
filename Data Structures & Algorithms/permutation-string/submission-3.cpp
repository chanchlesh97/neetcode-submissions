class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int charMap[26] = {0}, currMap[26] = {0}, found = 0,unique = 0, currUnique = 0;

        for(auto &c: s1) {
            charMap[c-'a']++; 
            if(charMap[c-'a']==1) unique++;
        }

        int l = 0, h = 0, n = s2.size();

        while(h<n) {
            if(charMap[s2[h]-'a']==0) {
                l = h+1;
                h++;
                found = 0;
                currUnique = 0;
                for(int i = 0;i<26;i++) currMap[i] = 0;
                continue;
            }
            currMap[s2[h]-'a']++;
            if(currMap[s2[h]-'a'] == 1) {
                found++;
            }
            if(currMap[s2[h]-'a'] == charMap[s2[h]-'a']) {
                currUnique++;
            }
            while(charMap[s2[h]-'a'] && currMap[s2[h]-'a'] > charMap[s2[h]-'a']) {

                if(currMap[s2[l]-'a'] == charMap[s2[l]-'a']) {
                    currUnique--;
                }
                currMap[s2[l]-'a']--;
                if(currMap[s2[l]-'a']==0) {
                    found--;
                }
                l++;
            }
            
            // cout<<h<<" "<<l<<" "<<currUnique<<" "<<found<<endl;
            if(currUnique == unique && found == unique) {
                return true;
            }
            h++;
        }
        return false;
    }
};
