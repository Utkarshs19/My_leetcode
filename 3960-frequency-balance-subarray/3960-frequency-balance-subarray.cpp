class Solution {
public:
    int getLength(vector<int>& nums) {

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {   
            unordered_map<int,int> m;
            int maxi=0;
            for(int j=i;j<nums.size();j++)
            {
                m[nums[j]]++;
                maxi=max(maxi,m[nums[j]]);
                if(m.size()==1)
                {
                    ans=max(ans,(int)(j-i+1));
                    continue;
                }
                if(maxi%2==1)continue;
                int half=maxi/2;
                bool f=false;
                bool flag=true;
                for(auto i:m)
                {
                    if(i.second==half)f=true;
                    if(i.second!=maxi && i.second!=half)flag=false;
                }
                if(f && flag)
                {
                    ans=max(ans,(int)(j-i+1));
                }
                
            }
        }
        return ans;
    }
};