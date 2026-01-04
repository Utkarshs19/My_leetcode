/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans=0;

     map<int,vector<int>> m;
     map<int,int> m1;
     map<int,bool> m2;
    
    void dfs(int id)
    {
        ans+=m1[id];
        m2[id]=true;

        for(auto i:m[id])
        {
            if(m2[i]==false)
            {
                dfs(i);
            }
        }
    }

    int getImportance(vector<Employee*> employees, int id) {

       

        for(int i=0;i<employees.size();i++)
        {
            vector<int> v=employees[i]->subordinates;

            for(int j=0;j<v.size();j++)
            {
                m[employees[i]->id].push_back(v[j]);
            }
            
            m2[employees[i]->id]=false;
            m1[employees[i]->id]=employees[i]->importance;
        }

        dfs(id);

        return ans;
        
    }
};