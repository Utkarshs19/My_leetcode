class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        
        int area=0;
        double maxi=0.0;
        
        double D=0.0;

        for(int i=0;i<d.size();i++)
        {
            double diag=sqrt((d[i][0]*d[i][0])+(d[i][1]*d[i][1]));
            int a=d[i][0]*d[i][1];

            cout<<diag<<" "<<a<<endl;

            if(diag>maxi)
            {
                maxi=diag;
                area=a;
                D=diag;
            }
            else if(diag==maxi)
            {
                area=max(area,a);
            }
        }

        return area;
        
    }
};