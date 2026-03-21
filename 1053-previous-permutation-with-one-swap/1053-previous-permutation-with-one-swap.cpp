class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {

        int j=arr.size()-2;

        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                int maxi=-1;
                for(int j=arr.size()-1;j>i;j--)
                {
                    if(arr[i]>arr[j] && (maxi==-1 || arr[j]>=arr[maxi]))
                    maxi=j;
                }
                swap(arr[i],arr[maxi]);
                return arr;
            }
        }

        return arr;
        
    }
};