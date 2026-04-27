class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int ans;
        int a=1e9;
        int x=0;
        int n=nums1.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                a=1e9;
                x=0;
                for(int k=0;k<n;k++)
                {
                    if(k==i || k==j)continue;
                    else
                    {
                        if(a==1e9)
                        {
                           a=nums2[x]-nums1[k];
                            x++;
                        }
                        else
                        {
                            if(nums2[x]-nums1[k]!=a)break;
                            else
                            x++;   
                        }
                    }
                }
                if(x==nums2.size())return a;
            }
        }
        
        return 1e9;
    }
};