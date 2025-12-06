class Solution {
public:

    map<int,int> m;

    
        string binary(int n)
        {
            string s="";

            while(n>0)
            {
                if(n%2==0)
                s+='0';
                else s+='1';

                n=n/2;
            }
            reverse(s.begin(),s.end());
            int i=0;
            while(i<s.length())
            {
                if(s[i]=='0')i++;
                else break;
            }
            s=s.substr(i);
         
            return s;
        }



    vector<int> minOperations(vector<int>& nums) {

        vector<int> ans;


        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];

            if(m.find(x)!=m.end())
                {
                    ans.push_back(0);
                    continue;
                }

            string str="";

            str+=binary(x);

            string s=str;
            reverse(s.begin(),s.end());
            if(s==str){
                m[x]++;
                ans.push_back(0);
                continue;
                }

            int k1=0;
            int k2=0;
            x=nums[i];
            while(x>0)
            {
                x--;
                k1++;

                if(m.find(x)!=m.end())
                {
                    break;
                }


            string str="";

            str+=binary(x);

            string s=str;
            reverse(s.begin(),s.end());
            if(s==str){
                m[x]++;
                break;}
            }

            x=nums[i];

            while(x<1e9)
            {
                x++;
                k2++;

                if(m.find(x)!=m.end())
                {
                    break;
                }
                

            string str="";

            str+=binary(x);

            string s=str;
            reverse(s.begin(),s.end());
            if(s==str){m[x]++;
            break;}
            }

            cout<<nums[i]<<" "<<k1<<"  "<<k2<<endl;

        ans.push_back(min(k1,k2));
        }

        return ans;
        
    }
};