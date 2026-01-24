class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> ans;

        int mini=INT_MAX;
        sort(arr.begin(),arr.end());

        for(int i=1;i<arr.size();i++)
        {
            mini=min(mini,abs(arr[i]-arr[i-1]));
        }

        for(int i=0;i<arr.size()-1;i++)
        {
            if(mini==(abs(arr[i+1]-arr[i])))
            {
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;
        
    }
};