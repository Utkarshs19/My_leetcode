class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> ans(queries.size(),0);

        vector<int> v(words.size());

        int l=words[0].length()-1;

        if((words[0][0]=='a'||words[0][0]=='e'||words[0][0]=='i'||words[0][0]=='o'||words[0][0]=='u')&&words[0][l]=='a'||words[0][l]=='e'||words[0][l]=='i'||words[0][l]=='o'||words[0][l]=='u')
        v[0]=1;


        for(int i=1;i<words.size();i++)
        {
            v[i]=v[i-1];
            
            int l=words[i].length()-1;

        if((words[i][0]=='a'||words[i][0]=='e'||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u')&&words[i][l]=='a'||words[i][l]=='e'||words[i][l]=='i'||words[i][l]=='o'||words[i][l]=='u')
        v[i]++;

        }
        
        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];

            if(x==0)
            ans[i]=v[y];
            else
            {
                ans[i]=v[x]-v[x-1];
                ans[i]+=v[y];
                ans[i]=ans[i]-v[x];
            }
        }

         return ans;   
    }
};