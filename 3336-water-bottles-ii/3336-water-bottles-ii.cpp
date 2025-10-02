class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {


        int ans=0;
        int empty=0;

        while(true)
        {
            ans+=numBottles;
            empty+=numBottles;
            numBottles=0;

            if(empty<numExchange)return ans;

            while(empty>=numExchange)
            {
                empty=empty-numExchange;
                numExchange++;
                numBottles++;
            }

        }

        return -1;
        
    }
};