class Solution {
public:
    vector<int> constructRectangle(int area) {

        vector<int> ans;
        if(area==1)return {1,1};
        ans.push_back(area);
        ans.push_back(1);

        for(int i=area-1;i>=0;i--)
        {
            if(area%i==0)
            {
                if(i<area/i)break;
                ans[0]=i;
                ans[1]=area/i;
            }
        }

        return ans;
        
    }
};