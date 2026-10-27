class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string> ans;

        for(int i=0;i<m;i++)
        {
            
            if(i==0)
            {
                string str(n,'.');
                ans.push_back(str);
            }
            else
            {
                string str(n,'#');
                str[n-1]='.';
                ans.push_back(str);
            }
        }
        return ans;
        
    }
};