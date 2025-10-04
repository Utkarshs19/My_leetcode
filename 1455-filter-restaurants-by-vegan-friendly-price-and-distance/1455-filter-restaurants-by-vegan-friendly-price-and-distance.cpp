class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        

        // id rating vegan price distance

        vector<int> ans;

        priority_queue<pair<int,pair<int,pair<int,pair<int,int>>>>> pq;

        for(int i=0;i<restaurants.size();i++)
        {
            
            pq.push({restaurants[i][1],{restaurants[i][0],{restaurants[i][2],{restaurants[i][3],restaurants[i][4]}}}});
            
        }


        while(!pq.empty())
        {
            int rating=pq.top().first;
            int id=pq.top().second.first;
            int vegan=pq.top().second.second.first;
            int price=pq.top().second.second.second.first;
            int dist=pq.top().second.second.second.second;

            if(veganFriendly==1)
            {
                if(vegan==1)
                {
                    if(price<=maxPrice && dist<=maxDistance)
                    ans.push_back(id);
                }
            }
            else
            {
                if(price<=maxPrice && dist<=maxDistance)
                ans.push_back(id);
            }
            pq.pop();
        }

        return ans;
    }
};