class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        vector<int> ans;
        int i=0,j=0;

        map<int,int> m;

        while(j<nums.size())
        {
            if(nums[j]<0)
            m[nums[j]]++;

            if(j-i+1==k)
            {
                int cnt=0;
                bool flag=false;
                for(auto y:m)
                {
                    cnt+=y.second;
                    if(cnt>=x)
                    {
                        flag=true;
                        ans.push_back(y.first);
                        break;
                    }
                }
                if(!flag)ans.push_back(0);

                if(nums[i]<0)m[nums[i]]--;
                i++;
            }

            j++;
        }

        return ans;
        
    }
};