class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> ans(num_people,0);
        int i=0;
        int k=1;
        while(candies>0)
        {
            for(i=0;i<num_people;i++)
            {
                if(candies<=0)break;
                if(candies>=k)
                ans[i]+=k;
                else
                ans[i]+=candies;

                candies-=k;
                k++;
            }

            if(i==num_people)i=0;
        }

        return ans;
        
    }
};