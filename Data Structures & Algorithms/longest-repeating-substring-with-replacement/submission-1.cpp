class Solution {
public:
    int characterReplacement(string s, int k) {
        int charCount = 0, prev = 0, curr = 0, ans = 0;
        int count[256] = {0}, n = s.size();

        while(curr < n) {
            count[s[curr]]++;
            int maxVal = 0, total = 0, maxChar, ch;

            for(int i =0;i<256;i++) {
                
                if(count[i] > maxVal) {
                    maxVal = count[i];
                    ch = i;
                }
                total += count[i];
            }
            if(total - maxVal > k){
                while(prev < curr && total - maxVal > k) {
                    count[s[prev]]--;
                    prev++;
                    total = 0, maxVal = 0;
                    for(int i =0;i<256;i++) {
                    
                        if(count[i] > maxVal) {
                            maxVal = count[i];
                            ch = i;
                        }
                        total += count[i];
                    }
                    
                }
                ans = max(ans, total);
                cout<<" "<<ans;
            }

            else {
                
                ans = max(ans, total);
                cout<<ans;
            }
            curr++;


        }
        return ans;
    }
};
