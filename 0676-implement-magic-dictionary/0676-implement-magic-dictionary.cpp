class MagicDictionary {
public:

    vector<string> v;
    vector<int> l;

    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {

        for(int i=0;i<dictionary.size();i++)
        {
            v.push_back(dictionary[i]);
            l.push_back(dictionary[i].length());
        }
        
    }
    
    bool search(string searchWord) {

        for(int i=0;i<l.size();i++)
        {
            if(l[i]==searchWord.length())
            {
                int cnt=0;

                for(int j=0;j<l[i];j++)
                {
                    if(v[i][j]!=searchWord[j])cnt++;
                    if(cnt==2)break;
                }
                if(cnt==1)return true;
            }
        }

        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */