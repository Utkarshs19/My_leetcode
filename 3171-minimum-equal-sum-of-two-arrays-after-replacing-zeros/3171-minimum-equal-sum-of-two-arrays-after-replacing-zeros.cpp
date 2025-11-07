class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        long long sum1=accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0LL);

        long long int cnt1=0;
        long long int cnt2=0;

        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]==0)
            cnt1++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]==0)
            cnt2++;
        }

        cout<<sum1<<"  "<<sum2<<"  "<<cnt1<<"  "<<cnt2;

        if(sum1==sum2 && cnt1==0 && cnt2==0)return sum1;

        if(sum1==sum2 && cnt1>0 &&cnt2>0)
        {
            if(cnt1>cnt2)
            return sum1+cnt1;
            else
            return sum2+cnt2;
        }

        if(sum1>sum2)
        {
            sum1+=cnt1;
            if(cnt2==0)return -1;
            else if(sum2+cnt2>sum1){
                if(cnt1==0)
                return -1;
                else
                return sum2+cnt2;
                }
            else
            return sum1;
        }
        else
        {
            sum2+=cnt2;
            if(cnt1==0)return -1;
            else if(sum1+cnt1>sum2){
                if(cnt2==0)return -1;
                else return sum1+cnt1;
            }
            else
            return sum2;

        }
        
        return sum1+cnt1;
    }
};