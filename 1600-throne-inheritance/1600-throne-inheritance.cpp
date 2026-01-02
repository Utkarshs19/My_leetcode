class ThroneInheritance {
public:
    map<string,vector<string>> m;
    
    set<string> st;

    string king;

    vector<string> ans;

    void dfs(string s)
    {
        if(st.find(s)==st.end())
        ans.push_back(s);


        for(auto &i:m[s])
        {
            dfs(i);
        }
    }

    ThroneInheritance(string kingName) {
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        
        m[parentName].push_back(childName);
    }
    
    void death(string name) {

        st.insert(name);
        
    }
    
    vector<string> getInheritanceOrder() {

        ans.clear();


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