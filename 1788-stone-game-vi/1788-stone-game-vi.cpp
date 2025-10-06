class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {

        vector<pair<int,int>> v;
        int n=aliceValues.size();

        for(int i=0;i<aliceValues.size();i++)
        {
            v.push_back({aliceValues[i]+bobValues[i], i});
        }

        sort(v.rbegin(),v.rend());

         int alice = 0, bob = 0;

        for (int i = 0; i < n; i++) {
            int idx = v[i].second;
            if (i % 2 == 0) {
               
                alice += aliceValues[idx];
            } else {
               
                bob += bobValues[idx];
            }
        }

        if (alice == bob) return 0;     // Draw
        else if (alice > bob) return 1; // Alice wins
        else return -1;  
        
    }
};