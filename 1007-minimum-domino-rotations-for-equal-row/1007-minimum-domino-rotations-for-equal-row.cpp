class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int ans=INT_MAX;

        int x=tops[0];
        int y=bottoms[0];

        int cnt=0;
        vector<int> v1=tops;
        vector<int> v2=bottoms;
        bool flag=true;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==x)continue;
            else if(v2[i]==x)cnt++;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)ans=min(ans,cnt);
        cnt=0;
        flag=true;
        v1=tops;
        v2=bottoms;
        for(int i=0;i<v2.size();i++)
        {
            if(v2[i]==x)continue;
            else if(v1[i]==x)cnt++;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)ans=min(ans,cnt);

        cnt=0;
        flag=true;
        v1=tops;
        v2=bottoms;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==y)continue;
            else if(v2[i]==y)cnt++;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)ans=min(ans,cnt);
        cnt=0;
        flag=true;
        v1=tops;
        v2=bottoms;
        for(int i=0;i<v2.size();i++)
        {
            if(v2[i]==y)continue;
            else if(v1[i]==y)cnt++;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)ans=min(ans,cnt);


        return ans==INT_MAX?-1:ans;
        
    }
};