class Solution {
public:
    unordered_map<string,int> m;
    string ans;
    bool flag=false;
    void helper(int i,int n)
    {
        if(i==n)
        {
            if(!m.count(ans))
            {
                flag=true;
            }
            return;
        }
        if(flag)return;
        ans+='0';
        helper(i+1,n);
        if(flag)return;
        ans.pop_back();
        ans+='1';
        helper(i+1,n);
        if(flag)return;
        ans.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {

        int n=nums[0].length();
        for(auto i:nums)m[i]++;

        helper(0,n);

        return ans;
        
    }
};