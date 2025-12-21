class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {

        int n=pizzas.size();
        sort(pizzas.begin(),pizzas.end());
        
        int i=0;
        int j=n-1;
        long long ans=0;
       
       long long odd=ceil(n/8.0);
        while(odd>0)
        {
            ans+=pizzas[j];
            odd--;
            j--;
        }
        cout<<ans<<endl;
        long long even=(n/4)/2;

        while(even--)
        {
            ans+=pizzas[j-1];
            j-=2;
        }

        return ans;
        
    }
};