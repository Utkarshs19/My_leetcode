class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {

        vector<int> even,odd;

        for(auto i:nums)
        {
            if(i%2==0)
            {
                even.push_back(i);
            }
            else
            odd.push_back(i);
        }

        sort(even.rbegin(),even.rend());
        sort(odd.begin(),odd.end());

        long long ans=LLONG_MIN;

        vector<int> odd1;
        int i=odd.size()-1;

        while(i-1>=0)
        {
            odd1.push_back(odd[i]+odd[i-1]);
            i-=2;
        }
        
        i=0;

        int j=even.size()-1;


        vector<long long> even_pref,odd_pref;

        if(even.size()>0)
        even_pref.push_back(even[0]);
        if(odd1.size()>0)
        odd_pref.push_back(odd1[0]);

        for(int i=1;i<even.size();i++)
        {
            even_pref.push_back(even_pref.back()+even[i]);
        }

        for(int i=1;i<odd1.size();i++)
        {
            odd_pref.push_back(odd_pref.back()+odd1[i]);
        }

        int x=0;
         
         for(int x = 0; x <= odd1.size(); x++)
            {
                int len = k - 2*x;

                if(len < 0)
                break;

                if(len > even.size())
                continue;

                long long e = (len == 0 ? 0 : even_pref[len-1]);
                long long o = (x == 0 ? 0 : odd_pref[x-1]);

                ans = max(ans, e + o);
}
        
            return ans==LLONG_MIN?-1:ans;


        
    }
};