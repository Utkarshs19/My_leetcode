class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());

        int x=0,y=0;

        if(right.size()>0)
        x=n-right[0];

        if(left.size()>0)
        y=left[left.size()-1];

        return max(x,y);

    }
};