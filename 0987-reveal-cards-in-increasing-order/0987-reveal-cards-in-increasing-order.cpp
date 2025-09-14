class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n=deck.size();

        vector<int> ans(n,0);

        sort(deck.begin(),deck.end());


        bool flag=true;

        int j=0,i=0;

         while(i<n)
        {
                if(ans[j]==0)
                {
                    if(flag)
                    {
                        ans[j]=deck[i];
                        i++;
                    }
                    flag=!flag;
                }
            
            j=(j+1)%n;
        }

        return ans;
        
    }
};