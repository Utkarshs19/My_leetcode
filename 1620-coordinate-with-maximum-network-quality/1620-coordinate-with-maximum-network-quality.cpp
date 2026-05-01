class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {

        int signal=0;
        vector<int> ans={0,0};

        for(int a=0;a<=50;a++)
        {
            for(int b=0;b<=50;b++)
            {
                int sum=0;

                for(int j=0;j<towers.size();j++)
                {
                    double d = sqrt((towers[j][0]-a)*(towers[j][0]-a) +
                (towers[j][1]-b)*(towers[j][1]-b));

                    if(d>radius)continue;
                    
                    sum += floor(towers[j][2] / (1 + d));   
                }
            
                    if(sum>signal)
                    {
                        signal=sum;
                        ans={a,b};
                    }
            }

            
        }
            
        
        return ans;
    }
};