class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {

        int j=0;
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<friends.size();i++)m[friends[i]]++;

        for(int i=0;i<order.size();i++)
        {
            if(m.find(order[i])!=m.end())
            {
                ans.push_back(order[i]);
                m.erase(order[i]);
                if(m.size()==0)break;

            }
        }

        return ans;
        
    }
};