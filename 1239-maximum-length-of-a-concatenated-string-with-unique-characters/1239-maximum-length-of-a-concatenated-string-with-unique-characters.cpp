class Solution {
public:
    int ans=0;
    void helper(int i,vector<string> &arr,string str)
    {
            ans=max(ans,(int)str.length());
           
        set<char> st;
        for(auto i:str)
        {
            st.insert(i);
        }
        for(int j=i;j<arr.size();j++)
        {
            string s=arr[j];
            bool flag=true;
            set<char> t;
            for(int k=0;k<s.length();k++)
            {
                if(st.count(s[k]) || t.count(s[k])){
                    flag=false;
                    break;
                }
                t.insert(s[k]);
            }
            if(flag)
            {   
                helper(j+1,arr,str+arr[j]);
            }
        }
    }
    int maxLength(vector<string>& arr) {

       helper(0,arr,""); 

       return ans;

    }
};