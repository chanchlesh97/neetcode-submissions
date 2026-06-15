class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, h = n-1;

        while(l<h) {
            while(l<=h && getValue(s[l]) == -1) {
                l++;
            }
            while(l<=h && getValue(s[h]) == -1) {
                h--;
            }

            if(l>=h) break;
            // cout<< l<<" "<<h<<" "<<getValue(s[l])<<" "<<getValue(s[h])<<endl;
            if(getValue(s[l]) == getValue(s[h])) {
                l++;
                h--;
            } else {
                return false;
            }
        }
        return true;
    }

    int getValue(char &ch) {
        if(ch >= 'a' && ch <= 'z') return ch - 'a';
        if(ch >= 'A' && ch <= 'Z') return ch - 'A';
        if(ch >= '0' && ch <= '9') return ch - '0';
        return -1;
    }
};
