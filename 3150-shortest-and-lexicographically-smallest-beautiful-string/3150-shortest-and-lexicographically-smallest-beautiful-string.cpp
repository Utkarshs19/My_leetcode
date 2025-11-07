class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i=0,j=0;

        string ans="";
        int x=0;

        while(j<s.length())
        {
            int cnt=0;
            i=j;
            
            while(i<s.length())
            {
                cout<<j<<"  "<<i<<" "<<cnt<<endl;
                if(s[i]=='1')
                {
                    cnt++;
                }
                 if(cnt==k)
                {
                    cout<<s.substr(j,i-j+1)<<endl;
                    if(ans==""){
                        x=i-j+1;
                    ans=s.substr(j,i-j+1);}
                    else{
                        if(x>i-j+1){
                            x=i-j+1;
                    ans=s.substr(j,i-j+1);
                    }
                    else if(x==i-j+1)
                    {
                        ans=min(ans,s.substr(j,i-j+1));
                    }
                    }
                    
                    break;
                }

                i++;
            }
            j++;
        }
        
        return ans;
    }
};