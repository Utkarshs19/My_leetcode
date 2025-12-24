class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int sum=accumulate(apple.begin(),apple.end(),0);

        sort(capacity.begin(),capacity.end());

        int tot=0;
        int ans=0;

        for(int i=capacity.size()-1;i>=0;i--)
        {
            ans++;
            tot+=capacity[i];
            if(tot>=sum)break;
        }

        return ans;
        
    }
};