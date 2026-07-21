class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_map<int,int> seqCount;
        int result = 1;
        for(auto &a: nums) {
            if(seqCount.count(a-1)) {
                seqCount[a] = 1+seqCount[a-1];
                
            } else {
                seqCount[a] = 1;
            }
            int v = a;
                while(seqCount.count(v+1)) {
                   seqCount[v+1] = seqCount[v]+1; 
                   v++;
                }
                result = max(result, seqCount[v]);
        }
        return result;
    }
};
