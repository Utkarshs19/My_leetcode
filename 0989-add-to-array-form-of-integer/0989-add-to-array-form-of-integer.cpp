class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry=0;

        vector<int> ans;
        
        for(int i=num.size()-1;i>=0;i--)
        {
            num[i]=(num[i]+(k%10)+carry);
            if(num[i]>=10)
            {
                carry=num[i]/10;
                num[i]=num[i]%10;
            }
            else
            carry=0;

            k=k/10;
        }

        k=k+carry;

        while(k>0){
        ans.push_back(k%10);
        k=k/10;
        }
        reverse(ans.begin(),ans.end());

        for(int i=0;i<num.size();i++)ans.push_back(num[i]);

    
        return ans;
        
    }
};