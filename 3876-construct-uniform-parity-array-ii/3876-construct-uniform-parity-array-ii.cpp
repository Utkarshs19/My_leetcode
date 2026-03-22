class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        bool even=true,odd=true;
        int o=INT_MAX,e=INT_MAX;
        int n=nums1.size();

        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==0)
            {
                e=min(e,nums1[i]);
            }
            else
            {
                o=min(o,nums1[i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==0)continue;
            else
            {
                if(o==-1)even=false;
                else
                {
                    if(nums1[i]-o<1)even=false;
                }
            }
        }

        if(even)return true;

         for(int i=0;i<n;i++)
        {
            if(nums1[i]%2!=0)continue;
            else
            {
                if(o==-1)odd=false;
                else
                {
                    if(nums1[i]-o<1)odd=false;
                }
            }
        }
        if(odd)return true;
        return false;
    }
};