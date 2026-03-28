class Solution {
public:

    bool helper(vector<vector<int>> &rect,int k)
    {
        sort(rect.begin(), rect.end(), [&](auto& a, auto& b){
            return a[k] < b[k];
        });

        int cnt=0;
        int maxi=rect[0][k+2];

        for(int i=1;i<rect.size();i++)
        {
            int s=rect[i][k];
            int e=rect[i][k+2];

            if(s>=maxi)
            {
                cnt++;
            }
            maxi=max(maxi,e);

        }

        return cnt>=2;

    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        return helper(rectangles,0)||helper(rectangles,1);
        
    }
};