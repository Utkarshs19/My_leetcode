class Solution {
public:
    bool flag=false;
    int length;

    bool helper(int i,vector<int> &v,vector<int> &matchsticks)
    {
        if(i==matchsticks.size())
        {
            return (v[0]==v[1] && v[1]==v[2] && v[2]==v[3]);
        }

        for(int j=0;j<4;j++)
        {   
            if(v[j]+matchsticks[i]<=length){
            v[j]+=matchsticks[i];
            if(helper(i+1,v,matchsticks))return true;
            v[j]-=matchsticks[i];
            }
            if(v[j]==0)break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);

        if(sum%4!=0)return false;

        length=sum/4;

        vector<int> v(4,0);

        return helper(0,v,matchsticks);

        
    }
};