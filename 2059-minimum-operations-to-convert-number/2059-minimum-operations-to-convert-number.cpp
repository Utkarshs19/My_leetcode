class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {

        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> vis(1001,0);
        vis[start]=1;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int node=q.front().first;
                int cost=q.front().second;
                q.pop();
                
                for(int j=0;j<nums.size();j++)
                {

                    vector<int> next={node+nums[j],node-nums[j],node^nums[j]};

                    for(auto val:next)
                    {
                        if(val==goal)return cost+1;
                        if(val<0 || val>1000)continue;
                        if(!vis[val])
                        {
                            vis[val]=1;
                            q.push({val,cost+1});
                        }
                    }
                    
                }

            }
        }
        
        return -1;
    }
};