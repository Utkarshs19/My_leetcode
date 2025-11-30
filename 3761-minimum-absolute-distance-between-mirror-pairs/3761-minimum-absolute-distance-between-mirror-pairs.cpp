class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        map<string,int> m;

        int ans=INT_MAX;

        int n=nums.size();

        
        m[to_string(nums[n-1])]=n-1;

        for(int i=n-2;i>=0;i--)
        {
            string str=to_string(nums[i]);
            string str1=str;
            reverse(str1.begin(),str1.end());
            int j=0;
            while(j<str1.length())
            {
                if(str1[j]!='0')break;
                else j++;
            }
            if(m.find(str1.substr(j))!=m.end())
            {
                ans=min(ans,abs(i-m[str1.substr(j)]));
            }
            m[str]=i;
        }

        return ans==INT_MAX?-1:ans;
        
    }
};