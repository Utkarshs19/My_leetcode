class Solution {
public:
    unordered_map<int,int> m;
    int ans=0;
    void dfs(int d,int pos,int sum)
    {
        int key=d*10+pos;

        if(!m.count(key))return;

        sum+=m[key];
        
        int left=(d+1)*10+(2*pos-1);
        int right=(d+1)*10+(2*pos);

        if(!m.count(left) && !m.count(right))
        {
            ans+=sum;
            return;
        } 

        dfs(d+1,pos*2-1,sum);
        dfs(d+1,pos*2,sum);

    }

    int pathSum(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            int val=nums[i]%10;
            int pos=(nums[i]/10)%10;
            int d=nums[i]/100;

            m[d*10+pos]=val;
        }

        dfs(1,1,0);

        return ans;

    }
};