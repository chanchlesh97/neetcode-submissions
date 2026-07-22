class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int curr = 0, result = 0;

        int count[26] = {0};
        // auto comp = [](pair<int,int>&a, pair<int,int> &b) {
        //     return a.second > b.second;
        // };
        for(auto &c: tasks) {
            count[c-'A']++;
        }
        // priority_queue<pair<int,int>, vector<pair<int,int>>,
        // decltype(comp)>pq;
        priority_queue<int, vector<int>
        >pq;
        queue<pair<int,int>> q;

        for(int i = 0;i<26;i++) {
            if(count[i])
            pq.push(count[i]);
        }
        int p;
        int prev = 0;
        pair<int,int> temp;
        while(!pq.empty() || !q.empty()) {
            result++;
            while(!q.empty() && q.front().second <= result) {
                temp = q.front();
                q.pop();
                pq.push(temp.first);
            }
            if(!pq.empty()) {
                int c = pq.top();
                pq.pop();
                cout<<" "<<c;

                
                if(c-1) {
                    q.push({c-1, result+n+1});
                }
            }
            cout<<endl;
            
        }

        return result;


    }
};
