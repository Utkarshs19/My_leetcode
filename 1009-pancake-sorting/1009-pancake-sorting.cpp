class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        vector<int> ans;

        vector<int> v=arr;
        sort(v.begin(),v.end());
        int i=0;
        int j=arr.size()-1;
        while(true)
        {
            if(v==arr)return ans;

            int idx = max_element(arr.begin(), arr.begin() + j+1) - arr.begin();
            ans.push_back(idx+1);

            reverse(arr.begin(),arr.begin()+idx+1);

            reverse(arr.begin(),arr.begin()+j+1);
            ans.push_back(j+1);
           
            j--;
        }

        return ans;
        
    }
};