class FoodRatings {
public:

    map<string,string> m1;

    map<string,int> m2;

    map<string,set<pair<int,string>>> m3;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

            for(int i=0;i<foods.size();i++)
            {
                m1[foods[i]]=cuisines[i];
                m2[foods[i]]=ratings[i];
                m3[cuisines[i]].insert({-ratings[i],foods[i]});
            }

    }
    
    void changeRating(string food, int newRating) {

        string cuisine=m1[food];

        int old=m2[food];

        m3[cuisine].erase({-old,food});
        m3[cuisine].insert({-newRating,food});

        m2[food]=newRating;
        
    }
    
    string highestRated(string cuisine) {

        return m3[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */