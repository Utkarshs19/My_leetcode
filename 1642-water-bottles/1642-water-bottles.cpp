class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int ans=0;
        int empty=0;
        while(true)
        {
            
            ans+=numBottles;
            numBottles+=empty;
            empty=0;
            if((numBottles)<numExchange)return ans;

            if(numBottles%numExchange==0)
            {
                numBottles=numBottles/numExchange;
                empty=0;
            }
            else
            {
                int rem=numBottles%numExchange;

                numBottles=numBottles/numExchange;
                empty=rem;
            }


        }

        return -1;
        
    }
};