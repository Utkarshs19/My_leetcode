class MovieRentingSystem {
public:

    map<int,set<pair<int,int>>> avail;  // movie-> {price,shop};
    map<pair<int,int>,int> m;           // movie,shop --> price;

    set<tuple<int,int,int>> st;         // price,shop,movie;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for(int i=0;i<entries.size();i++)
        {
            avail[entries[i][1]].insert({entries[i][2],entries[i][0]});

            m[{entries[i][1],entries[i][0]}]=entries[i][2];
        }
        
    }
    
    vector<int> search(int movie) {

        vector<int> v;

        if(avail.find(movie)==avail.end())return {};

        for(auto &[price,shop]:avail[movie])
        {
            v.push_back(shop);
            if(v.size()==5)break;
        }

        return v;
        
    }
    
    void rent(int shop, int movie) {

        st.insert({m[{movie,shop}],shop,movie});

        avail[movie].erase({m[{movie,shop}],shop});
        
    }
    
    void drop(int shop, int movie) {

        st.erase({m[{movie,shop}],shop,movie});
        avail[movie].insert({m[{movie,shop}],shop});
        
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int>> v;

        for(auto &[price,shop,movie]:st)
        {
            v.push_back({shop,movie});
            if(v.size()==5)break;
        }

        return v;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */