class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        set<vector<int>> st(points.begin(),points.end());

        if(st.count(target))return 0;

        int k=0;

        while(true){
        
        vector<vector<int>> v(st.begin(),st.end());
        bool flag=false;
        set<vector<int>> next=st;
        for(int i=0;i<v.size();i++)
        {   
            for(int j=i+1;j<v.size();j++)
            {
              
                int x=(v[i][0]+v[j][0])/2;
                int y=(v[i][1]+v[j][1])/2;
                int z=(v[i][2]+v[j][2])/2;
                vector<int> mid={x,y,z};

                if(mid==target)return k+1;

                if(!next.count({x,y,z})){
                    next.insert({x,y,z});
                    flag=true;
                }

            }    
        }
        k++;
        st=next;
        if(flag==false)break;
        }

        return -1;
    }
};