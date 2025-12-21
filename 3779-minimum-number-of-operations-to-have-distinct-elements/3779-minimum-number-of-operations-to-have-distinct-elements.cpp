class Solution {
public:
    int minOperations(vector<int>& nums) {

        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++)m[nums[i]]++;
        
        int ans=0;
        int i=0;

        while(true)
        {
            if(m.size()==n-i)return ans;
            if(m.size()==0)return ans;

            ans++;

            if(i<n)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)m.erase(nums[i]);
            }

            if(i+1<n)
            {
                m[nums[i+1]]--;
                if(m[nums[i+1]]==0)m.erase(nums[i+1]);
            }

            if(i+2<n)
            {
                m[nums[i+2]]--;
                if(m[nums[i+2]]==0)m.erase(nums[i+2]);
            }
            i+=3;

        }
        return ans;
    }
};