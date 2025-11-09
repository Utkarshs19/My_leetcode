class Solution {
public:

    map<int,int> m1;
    set<int> s;

    void check(int n)
    {   
        if(n<2) return;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return;
        }
        
        m1[n]++;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {


        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=i,y=j;
                int p=mat[i][j];
                while(x-1>=0)
                {
                    p=p*10+mat[x-1][y];
                    if(p>10)
                {
                    check(p);
                }
                    x--;
                }

                p=mat[i][j];
                x=i,y=j;

                while(x+1<n)
                {
                    p=p*10+mat[x+1][y];
                    if(p>10)
                {
                    check(p);
                }
                    x++;
                }

                p=mat[i][j];
                x=i,y=j;

                while(y-1>=0)
                {
                    p=p*10+mat[x][y-1];
                    if(p>10)
                {
                    check(p);
                }
                    y--;
                }

                p=mat[i][j];
                x=i,y=j;

                while(y+1<m)
                {
                    p=p*10+mat[x][y+1];
                    if(p>10)
                {
                    check(p);
                }
                    y++;
                }

                p=mat[i][j];
                x=i,y=j;

                while(x-1>=0 && y-1>=0)
                {
                    p=p*10+mat[x-1][y-1];
                    if(p>10)
                {
                    check(p);
                }
                    x--;y--;
                }

                p=mat[i][j];
                x=i,y=j;

                while(x-1>=0 && y+1<m)
                {
                    p=p*10+mat[x-1][y+1];
                    if(p>10)
                {
                    check(p);
                }
                    x--;
                    y++;
                }

                p=mat[i][j];
                x=i,y=j;

                while(x+1<n && y-1>=0)
                {
                    p=p*10+mat[x+1][y-1];
                    if(p>10)
                {
                    check(p);
                }
                    x++;y--;
                }

                p=mat[i][j];
                x=i,y=j;

                while(x+1<n && y+1<m)
                {
                    p=p*10+mat[x+1][y+1];
                    if(p>10)
                {
                    check(p);
                }
                    x++;
                    y++;
                }
                cout<<endl;


            }
        }   

        int maxi=INT_MIN;

        for(auto k:m1)
        {
            cout<<k.first<<"  "<<k.second<<endl;
            maxi=max(maxi,(int)k.second);
        }

        if(maxi==INT_MIN)return -1;

        int ans;

        for(auto k:m1)
        {
            if(k.second==maxi)
            ans=k.first;
        }


        return ans;
        
    }
};