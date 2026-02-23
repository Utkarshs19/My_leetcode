class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int maxi1=0,maxi2=0,maxi3=0;

        for(int i=0;i<triplets.size();i++)
        {
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2])
            {
                maxi1=max(maxi1,triplets[i][0]);
                maxi2=max(maxi2,triplets[i][1]);
                maxi3=max(maxi3,triplets[i][2]);
            }
        }

        return maxi1==target[0] && maxi2==target[1] && maxi3==target[2];

    }
};