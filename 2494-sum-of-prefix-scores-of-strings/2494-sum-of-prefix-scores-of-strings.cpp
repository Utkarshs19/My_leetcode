class Solution {

    struct Node{
        
        Node *links[26];
        int  pre=0;

        bool containsKey(char ch)
        {
            return links[ch-'a']!=NULL;
        }

        void put(char ch,Node *node)
        {
            links[ch-'a']=node;
        }

        Node* get(char ch)
        {
            return links[ch-'a'];
        }

        void prefix()
        {
            pre++;
        }

        int getPre()
        {
            return pre;
        }


    };

    Node *root=new Node();

public:

    vector<int> sumPrefixScores(vector<string>& words) {

        for(int i=0;i<words.size();i++)
        {
            Node *node=root;

            for(int j=0;j<words[i].length();j++)
            {
                if(!node->containsKey(words[i][j]))
                {
                    node->put(words[i][j],new Node());
                }

                node=node->get(words[i][j]);

                node->prefix();

            }
        }
        
        vector<int> ans;

         for(int i=0;i<words.size();i++)
        {
            Node *node=root;

            int cnt=0;

            for(int j=0;j<words[i].length();j++)
            {
                if(node->containsKey(words[i][j]))
                {
                    node=node->get(words[i][j]);
                    cnt+=node->getPre();
                }
            }

            ans.push_back(cnt);
            
        }


        return ans;
    }
};