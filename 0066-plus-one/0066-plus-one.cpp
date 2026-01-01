class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        vector<int> v;
        int carry=1;

        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]==9 && carry==1)
            {
                v.push_back(0);
                
                carry=1;
            }
            else
            {
                v.push_back(digits[i]+carry);
                carry=0;
            }
        }

        if(digits[0]==9 && carry==1)v.push_back(1);

        reverse(v.begin(),v.end());

        return v;
        
    }
};