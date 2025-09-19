class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        
        int x=tomatoSlices-(2*cheeseSlices);
        if(x<0)return {};
        if(cheeseSlices-(x/2)<0) return {};

        if(x%2==0)
        return {x/2,cheeseSlices-(x/2)};

        return {};

    }
};