class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {

        map<int,vector<int>> m;

        for(int i=0;i<pieces.size();i++)
        {
            m[pieces[i][0]]=pieces[i];
        }

        int i=0;

        for(int i=0;i<arr.size();)
        {
            if(m.find(arr[i])!=m.end())
            {
                vector<int> v=m[arr[i]];

                int j=0;

                while(j<v.size())
                {
                    if(arr[i]==v[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    return false;
                }

            }
            else return false;
        }

        return true;

        
        
    }
};