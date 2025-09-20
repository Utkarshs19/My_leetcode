class WordDictionary {

    struct Node
    {
        Node* links[26];
        bool flag=false;

        bool containsKey(char ch)
        {
            return links[ch-'a']!=NULL; 
        }

        void put(char ch,Node *node)
        {
            links[ch-'a']=node;
        }

        Node *get(char ch)
        {
            return links[ch-'a'];
        }

        void setEnd()
        {
            flag=true;
        }

        bool isEnd(){
        return flag;
        }
    };

    Node *root;

public:

    bool dfs(int i,string &word,Node *node)
    {
        if(i==word.length())
        return node->isEnd();

        char ch=word[i];

        if(ch=='.'){
        for(int j=0;j<26;j++)
        {
            if(node->links[j] && dfs(i+1,word,node->links[j]))
            return true;
        }
        return false;
        }
        else
        {
            if(!node->containsKey(ch))return false;

            return dfs(i+1,word,node->get(ch));
        }

    }

    WordDictionary() {

        root=new Node();
        
    }
    
    void addWord(string word) {

        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            
            node=node->get(word[i]);
        }

        node->setEnd();        
    }
    
    bool search(string word) {

        return dfs(0,word,root);
       
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */