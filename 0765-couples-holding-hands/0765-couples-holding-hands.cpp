class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        map<int,int> m;

        for(int i=0;i<row.size()-1;i+=2)
        {
            m[row[i]]=row[i+1];
            m[row[i+1]]=row[i];
        }

        int ans=0;

        for(int i=0;i<row.size();i+=2)
        {
            if(m[i]!=i+1)
            {
                ans++;
                int x=m[i];
                int y=m[i+1];

                m[x]=y;
                m[y]=x;

                m[i]=i+1;
                m[i+1]=i;
            }
        }
        
        return ans;
    }
};