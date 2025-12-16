class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        
        vector<int> v={a,b,c};
        sort(v.begin(),v.end());
        
        int mini=min(v[1]-v[0]-1,v[2]-v[1]-1);
        int maxi=max(v[1]-v[0]-1,v[2]-v[1]-1);

        if(mini==0 && maxi==0)return {mini,maxi};
        if(mini==0||mini==1)mini=1;
        else mini=2;

        return {mini,v[2]-v[0]-2};

    }
};