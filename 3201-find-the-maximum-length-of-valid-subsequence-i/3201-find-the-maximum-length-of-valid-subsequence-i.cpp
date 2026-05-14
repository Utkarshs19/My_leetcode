class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;

        for(auto i:nums)
        {
            if(i%2==0)cnt1++;
            else cnt2++;
        }

        bool flag=true;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0 && flag==true){flag=!flag;
            cnt3++;}
            else if(nums[i]%2==1 && flag==false){flag=!flag;
            cnt3++;}
        }

        flag=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1 && flag==true){flag=!flag;
            cnt4++;}
            else if(nums[i]%2==0 && flag==false){flag=!flag;
            cnt4++;}
        }
        

        return max({cnt1,cnt2,cnt3,cnt4});
    }
};