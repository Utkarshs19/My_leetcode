class Solution {
public:
    vector<int> v1;
    vector<vector<int>> v;
    int ans=0;
    void helper(int i)
    {
        if(i==v1.size()) 
        {
            int sum=0;
            for(int j=0;j<v1.size();j++)
            {
                sum+=v[v1[j]][j];
            }
            ans=max(ans,sum);
            return;
        }

        for(int j=i;j<v1.size();j++)
        {
            swap(v1[i],v1[j]);
            helper(i+1);
            swap(v1[i],v1[j]);
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {

        int m=students.size();
        int n=students[0].size();

        for(int i=0;i<m;i++)v1.push_back(i);

        v.resize(m);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=0;
                for(int k=0;k<n;k++)
                {
                    if(students[i][k]==mentors[j][k])
                    cnt++;
                }
                v[i].push_back(cnt);
            }
        }
        

        helper(0);
        return ans;
    }
};