class Solution {
public:

    string ans;

    void helper(int i,vector<int> &arr)
    {
        if(i==arr.size())
        {
            int x=arr[0];
            x=x*10+arr[1];

            int y=arr[2];
            y=y*10+arr[3];

        
            if(x<=23 && y<=59)
            {
                string s;
                if(x < 10) s += '0';
                s += to_string(x);
                s += ':';

                if(y < 10) s += '0';
                s += to_string(y);

                ans=max(ans,s);
            }

            return;
        }

        for(int j=i;j<arr.size();j++)
        {
            swap(arr[i],arr[j]);
            helper(i+1,arr);
            swap(arr[i],arr[j]);
        }
    }

    string largestTimeFromDigits(vector<int>& arr) {
        
        helper(0,arr);

        return ans;

    }
};