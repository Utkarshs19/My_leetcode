class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        set<int> s;

        for(int i=0;i<friendships.size();i++)
        {
            unordered_map<int,int> m;

            for(int j:languages[friendships[i][0]-1])
            {
                m[j]++;
            }
            bool flag=false;
            for(int j:languages[friendships[i][1]-1])
            {
                if(m[j])
                {
                    flag=true;
                    break;
                }
            }            

            if(flag==false)
            {
                s.insert(friendships[i][0]-1);
                s.insert(friendships[i][1]-1);
            }

        }

        int maxi=0;

        vector<int> v(n+1,0);

        for(auto i:s)
        {
            for(int j:languages[i])
            {
                v[j]++;
                maxi=max(maxi,v[j]);
            }
        }

        return s.size()-maxi;

    }
};