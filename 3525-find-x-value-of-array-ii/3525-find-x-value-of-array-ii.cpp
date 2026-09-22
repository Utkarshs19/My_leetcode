class Solution {
public:
    struct Node{
        int pro;
        int count[5]={0};
    };

    class segmentTree{

        public:
            int n;
            int k;
            vector<Node> segTree;

            segmentTree(vector<int> &nums,int k)
            {
                this->k=k;
                this->n=nums.size();
                segTree.resize(4*n, Node());
                build(0,0,n-1,nums);
            }

            void build(int i,int l,int r,vector<int> &nums)
            {
                if(l==r)
                {
                    leaf(i,nums[l]);
                    return;
                }
                int mid=l+(r-l)/2;

                build(2*i+1,l,mid,nums);
                build(2*i+2,mid+1,r,nums);

                segTree[i]=merge(segTree[2*i+1],segTree[2*i+2]);
            }

            void leaf(int i,int val)
            {
                for(int j=0;j<k;j++)
                {
                    segTree[i].count[j]=0;
                }
                segTree[i].pro=val%k;
                segTree[i].count[val%k]++;

            }
            Node merge(Node &left,Node &right)
            {
                Node result;
                result.pro=(left.pro*right.pro)%k;

                for(int j=0;j<5;j++)
                {
                    result.count[j]=left.count[j];
                }

                for(int j=0;j<5;j++)
                {
                    int newRem=(left.pro*j)%k;

                    result.count[newRem]+=right.count[j];
                }

                return result;
            }
            void segTreeUpdate(int i,int l,int r,int idx,int val)
            {
                if(l==r)
                {
                    leaf(i,val);
                    return;
                }

                int mid=l+(r-l)/2;

                if(idx<=mid)
                {
                    segTreeUpdate(2*i+1,l,mid,idx,val);
                }
                else
                {
                    segTreeUpdate(2*i+2,mid+1,r,idx,val);
                }

                segTree[i]=merge(segTree[2*i+1],segTree[2*i+2]);
            }
            void update(int i,int val)
            {
                segTreeUpdate(0,0,n-1,i,val);
            }

            Node segTreeQuery(int s,int e,int i,int l,int r)
            {
                if(l>=s && r<=e)
                {
                    return segTree[i];
                }

                int mid=l+(r-l)/2;

                if(e<=mid)
                {
                    return segTreeQuery(s,e,2*i+1,l,mid);
                }
                if(s>mid)
                {
                    return segTreeQuery(s,e,2*i+2,mid+1,r);
                }

                Node left=segTreeQuery(s,e,2*i+1,l,mid);
                Node right=segTreeQuery(s,e,2*i+2,mid+1,r);

                return merge(left,right);

            }
            Node query(int s,int e)
            {
                Node res=segTreeQuery(s,e,0,0,n-1);
                return res;
            }


    };
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {

        vector<int> ans;

        int n=nums.size();

        segmentTree segTree(nums,k);

        for(int i=0;i<queries.size();i++)
        {
            segTree.update(queries[i][0],queries[i][1]);
            Node resultNode=segTree.query(queries[i][2],n-1);
            ans.push_back(resultNode.count[queries[i][3]]);
        }

        return ans;
        
    }
};