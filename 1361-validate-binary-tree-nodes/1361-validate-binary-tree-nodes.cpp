class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        set<int> st;
        for(int i=0;i<leftChild.size();i++)st.insert(leftChild[i]);
        for(int j=0;j<rightChild.size();j++)st.insert(rightChild[j]);

        int x=-1;
        for(int i=0;i<n;i++)
        {
            if(!st.count(i))
            {
                x=i;
                break;
            }
        }

        if(x==-1)return false;

        vector<int> vis(n,0);
        queue<int> q;
        q.push(x);
        vis[x]=1;
        int cnt=1;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front();
                q.pop();

                if(leftChild[x]!=-1)
                {
                    if(vis[leftChild[x]]==1)return false;
                    else{
                        vis[leftChild[x]]=1;
                        cnt++;
                        q.push(leftChild[x]);
                        }
                }
                if(rightChild[x]!=-1)
                {
                    if(vis[rightChild[x]]==1)return false;
                    else{
                        vis[rightChild[x]]=1;
                        cnt++;
                        q.push(rightChild[x]);
                        }
                }
            }
            
        }
        return cnt==n;
        
    }
};