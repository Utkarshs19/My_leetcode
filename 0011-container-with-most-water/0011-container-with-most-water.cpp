class Solution {
public:
    int maxArea(vector<int>& height) {

        int ans=INT_MIN;


        int i=0;
        int j=height.size()-1;

        while(i<j)
        {
            int area=min(height[i],height[j])*(j-i);
            ans=max(ans,area);
            if(height[i]<=height[j])i++;
            else j--;
        }

        return ans;
        
    }
};