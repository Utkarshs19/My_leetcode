class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {

        list<int> l;

        for(int i=0;i<arr.size();i++)
        {
            l.push_back(arr[i]);
            if(l.size()==m)
            {   
                int cnt=1;
                vector<int> v;
                int j;
                for(j=i+1;j<arr.size();j++)
                {
                    v.push_back(arr[j]);
                    if(v.size()==m)
                    {
                        vector<int> temp(l.begin(),l.end());
                        if(temp==v){cnt++;
                        v.clear();
                        if(cnt>=k)return true;}
                        else
                        break;
                    }
                }
                l.pop_front();

            }
        }

        return false;
        
    }
};