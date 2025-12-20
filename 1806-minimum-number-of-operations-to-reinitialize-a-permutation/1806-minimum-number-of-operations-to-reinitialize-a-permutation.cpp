class Solution {
public:
    int reinitializePermutation(int n) {

        int ans=0;

        vector<int> v(n),perm(n);

        for(int i=0;i<n;i++)
        {
            v[i]=i;
            perm[i]=i;
        }
        vector<int> arr(n);

        if(arr==v)return 0;
  

        while(true)
        {
            
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                {
                    arr[i]=perm[i/2];
                }
                else
                {
                    arr[i]=perm[n/2+(i-1)/2];
                }
            }
            perm=arr;
            ans++;
            if(v==perm)break;
        }

        return ans;
        
    }
};