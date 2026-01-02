class ThroneInheritance {
public:
    map<string,vector<string>> m;
    map<string,bool> m1;
    set<string> st;

    string king;

    vector<string> ans;

    void dfs(string s)
    {
        if(st.find(s)==st.end())
        ans.push_back(s);

        m1[s]=true;

        for(auto &i:m[s])
        {
            if(m1[i]==false)
            {
                dfs(i);
            }
        }
    }

    ThroneInheritance(string kingName) {
        king=kingName;
        m1[king]=false;
    }
    
    void birth(string parentName, string childName) {
        
        m[parentName].push_back(childName);
        m1[parentName]=false;
        m1[childName]=false;

    }
    
    void death(string name) {

        st.insert(name);
        
    }
    
    vector<string> getInheritanceOrder() {

        ans.clear();

        for(auto &i:m1)
        {
            i.second=false;
        }

        dfs(king);

        return ans;
        
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */