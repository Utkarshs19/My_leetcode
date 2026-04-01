class Solution {
public:

    vector<int> bin(int x)
    {
        vector<int> v(30,0);
        int k=0;
        while(x>0)
        {
            if(x%2==1)v[k]=1;
            
            x=x/2;
            k++;
        }

        return v;
    }

    int longestNiceSubarray(vector<int>& nums) {

        vector<vector<int>> binary;

        for(int i=0;i<nums.size();i++)
        {
            binary.push_back(bin(nums[i]));
        }

        int i=0,j=0;
        vector<int> used(30,0);
        int ans=0;
        set<int> st;
        while(j<binary.size())
        {
            for(int k=0;k<30;k++)
            {
                used[k]+=binary[j][k];
                if(used[k]>1)st.insert(k);
            }

            while(!st.empty())
            {
                for(int k=0;k<30;k++)
                {
                    if(binary[i][k]==1 && st.count(k)){
                    st.erase(k);
                    }
                    if(binary[i][k])used[k]--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};