class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {

        int even_count=1;
        int odd_count=0;

        int sum=0;

        int ans=0;

        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];

            if(sum%2==1)
            {
                ans=(ans+even_count)%MOD;
                odd_count++;
            }
            else
            {
                ans=(ans+odd_count)%MOD;
                even_count++;
            }
           
        }

        return ans;
        
    }
};