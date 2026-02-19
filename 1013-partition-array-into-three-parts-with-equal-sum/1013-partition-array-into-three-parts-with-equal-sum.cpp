class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {

        int sum=accumulate(arr.begin(),arr.end(),0);

        if(sum%3!=0) return false;

        int cnt=0;
        int sum1=0;

        for(int i=0;i<arr.size();i++)
        {
            sum1+=arr[i];
            if(sum1==sum/3)
            {
                cnt++;
                sum1=0;
            }
        }
        return (cnt>=3);
        
    }
};