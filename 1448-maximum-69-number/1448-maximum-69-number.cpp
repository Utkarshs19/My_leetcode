class Solution {
public:
    int maximum69Number (int num) {
        
       long long int x=num;
       vector<int> v;
       while(x>0)
       {
           v.push_back(x%10);
           x=x/10;
       }
       reverse(v.begin(),v.end());

       for(int i=0;i<v.size();i++)
       {
           if(v[i]==6){
           v[i]=9;
            break;
            }    
       }
       x=0;

       for(int i=0;i<v.size();i++) 
        {
            x=x*10+v[i];
        }

        return x;
    }
};