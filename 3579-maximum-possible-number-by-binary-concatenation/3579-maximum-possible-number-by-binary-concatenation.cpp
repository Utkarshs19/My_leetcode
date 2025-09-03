class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        
        int ans=INT_MIN;

         string s1="",s2="",s3="";

        while(nums[0]>0)
        {
            int x=nums[0]%2;
            if(x==1)s1+="1";
            else s1+="0";

            nums[0]=nums[0]/2;
        }
        reverse(s1.begin(),s1.end());

        while(nums[1]>0)
        {
            int x=nums[1]%2;
            if(x==1)s2+="1";
            else s2+="0";

            nums[1]=nums[1]/2;
        }
        reverse(s2.begin(),s2.end());

        while(nums[2]>0)
        {
            int x=nums[2]%2;
            if(x==1)s3+="1";
            else s3+="0";

            nums[2]=nums[2]/2;
        }
        reverse(s3.begin(),s3.end());

        string s="";
        int k=0;

        s+=s1+s2+s3;
        
        k=0;
        int xyz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            xyz+=((s[i]-'0')*(pow(2,k)));
            k++;
        }
        ans=max(ans,xyz);

        s="";
        s+=s1+s3+s2;
        
        k=0;
         xyz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            xyz+=((s[i]-'0')*(pow(2,k)));
            k++;
        }
        ans=max(ans,xyz);

        s="";
        s+=s2+s1+s3;
        
        k=0;
         xyz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            xyz+=((s[i]-'0')*(pow(2,k)));
            k++;
        }
        ans=max(ans,xyz);

        s="";
        s+=s2+s3+s1;
        
        k=0;
         xyz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            xyz+=((s[i]-'0')*(pow(2,k)));
            k++;
        }
        ans=max(ans,xyz);

        s="";
        s+=s3+s1+s2;
        
        k=0;
         xyz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            xyz+=((s[i]-'0')*(pow(2,k)));
            k++;
        }
        ans=max(ans,xyz);

        s="";
        s+=s3+s2+s1;
        
        k=0;
         xyz=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            xyz+=((s[i]-'0')*(pow(2,k)));
            k++;
        }
        ans=max(ans,xyz);

        return ans;

    }
};