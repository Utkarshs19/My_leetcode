class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

       int n=s.length(); 
        queue<int> q;
        vector<int> vis(n,0);

        q.push(0);
        vis[0]=0;
        int far=0;

        if(s[n-1]=='1')return false;

        while(!q.empty())
        {
            int ind=q.front();
            q.pop();

            if(ind==n-1)return true;

            int start=max(ind+minJump,far+1);
            int end=min(ind+maxJump,n-1);

            for(int j=start; j<=end;j++)
            {
                if(s[j]=='0')
                {
                    if(!vis[j])
                    {
                        if(j==n-1)return true;
                        vis[j]=1;
                        q.push(j);
                    }
                }
            } 
            far=end;
        }

        return false;

    }
};