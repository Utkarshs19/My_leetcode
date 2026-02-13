class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int i=0,j=0;
        int ans=0;
        map<int,int> m;

        while(j<fruits.size())
        {
            m[fruits[j]]++;
            while(m.size()>2)
            {
                m[fruits[i]]--;
                if(m[fruits[i]]==0)m.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
        
    }
};