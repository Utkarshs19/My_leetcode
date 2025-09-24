class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> pq;
        unordered_map<char,int> freq;

        for(char c : s) freq[c]++;
        for(auto &p : freq) pq.push({p.first, p.second});

        string ans = "";

        while(!pq.empty()) {
            char x=pq.top().first;
            int y=pq.top().second;
            pq.pop();

            
            if(!ans.empty() && ans.back() == x) {
                if(pq.empty()) break; // nothing else left

                char a = pq.top().first;
                int b=pq.top().second;
                pq.pop();

                ans.push_back(a);
                b--;

                if(b > 0) pq.push({a, b});
                pq.push({x, y}); // put back the original
            } 
            else {
                // Case 2: safe to use current char
                int use = min(y, repeatLimit);
                ans.append(use, x);
                y -= use;

                if(y > 0) pq.push({x, y});
            }
        }

        return ans;
    }
};
