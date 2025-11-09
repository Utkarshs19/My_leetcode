class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        set<string> s;

        for(int i=0;i<arr1.size();i++)
        {
            string str=to_string(arr1[i]);

            for(int j=0;j<str.length();j++)
            {   
                
                s.insert(str.substr(0,j-0+1));
            }
        }

        set<string> s1;

        for(int i=0;i<arr2.size();i++)
        {
            string str=to_string(arr2[i]);

            for(int j=0;j<str.length();j++)
            {
                s1.insert(str.substr(0,j-0+1));
            }
        }


        int ans=0;

        for(auto i:s)
        {
            // cout<<i<<endl;
            if(s1.find(i)!=s1.end())
            {
                ans=max(ans,(int)(i.length()));
            }
        }

        return ans;
        
    }
};