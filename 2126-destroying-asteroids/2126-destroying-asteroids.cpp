class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        long long m=1ll*mass;
        for(int i=0;i<n;i++)
        {
            if(m>=asteroids[i])
            {
                m+=asteroids[i];

            }
            else
            return false;
        }        
        return true;
    }
};