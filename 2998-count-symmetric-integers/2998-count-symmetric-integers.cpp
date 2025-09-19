class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int cnt=0;

        while(low<=high)
        {
            vector<int> v;
            int x=low;
            while(x>0)
            {
                v.push_back(x%10);
                x=x/10;
            }
            int n=v.size();
            if(n%2==0)
            {
                int sum1=0;
                int sum2=0;
                for(int i=0;i<n/2;i++)
                sum1+=v[i];
                for(int i=n/2;i<n;i++)
                sum2+=v[i];
                
                if(sum1==sum2)
                cnt++;
            }
            low++;
        }
        
        return cnt;
    }
};