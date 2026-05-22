class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {

        map<int,int> m;
        vector<int> ans;
        int i=0,j=0;

        while(j<nums.size())
        {
            m[nums[j]]++;   

            if(j-i+1==k)
            {   
                
                ans.push_back(m.size());

                m[nums[i]]--;
                if(m[nums[i]]==0)m.erase(nums[i]);
                i++;
            }
            j++;
        }

        return ans;
        
    }
};