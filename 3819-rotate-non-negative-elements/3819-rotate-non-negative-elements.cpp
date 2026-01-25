class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                v.push_back(nums[i]);
            }
        }

        vector<int> v1(v.size());

        if(v.size()>0)k=k%v.size();

        for(int i=0;i<v.size();i++)
        {
            v1[(i-k+v.size())%v.size()]=v[i];
        }
        int a=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                nums[i]=v1[a];
                a++;
            }
        }

        return nums;
        
    }
};