class DetectSquares {
public:
    map<pair<int,int>,int> m;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {

        m[{point[0],point[1]}]++;
        
    }
    
    int count(vector<int> point) {

        int x=point[0],y=point[1];

        int ans=0;

        for(auto i:m)
        {
            int x1=i.first.first;
            int y1=i.first.second;

            if(x==x1 || y==y1)continue;
            if(abs(x-x1)!=abs(y-y1))continue;

            pair<int,int> p1={x,y1};
            pair<int,int> p2={x1,y};


            ans+=i.second*m[p1]*m[p2];

        }

        return ans;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */