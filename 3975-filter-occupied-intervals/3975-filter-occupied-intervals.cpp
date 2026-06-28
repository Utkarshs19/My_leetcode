class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        vector<vector<int>> o;
        int s=occupiedIntervals[0][0];
        int e=occupiedIntervals[0][1];
        for(int i=1;i<occupiedIntervals.size();i++)
        {
            if(e>=occupiedIntervals[i][0])
            {
                e=max(e,occupiedIntervals[i][1]);
            }
            else
            {
                if(o.size()>0 && o.back()[1]+1==s)
                o.back()[1]=e;
                else
                o.push_back({s,e});
                s=occupiedIntervals[i][0];
                e=occupiedIntervals[i][1];
            }
        }
        if(o.size()>0 && o.back()[1]+1==s)
        o.back()[1]=e;
        else
        o.push_back({s,e});

        vector<vector<int>> ans;
        for(int i=0;i<o.size();i++)
        {
            if(freeStart<=o[i][0] && freeEnd>=o[i][1])continue;
            else if(freeStart>=o[i][0] && freeEnd<=o[i][1])
            {
                if(o[i][0]<=freeStart-1)
                ans.push_back({o[i][0],freeStart-1});
                if(freeEnd+1<=o[i][1])
                ans.push_back({freeEnd+1,o[i][1]});
            }
            else if(freeStart>=o[i][0] && freeStart<=o[i][1])
            {
                ans.push_back({o[i][0],freeStart-1});
            }
            else if(freeEnd>=o[i][0] && freeEnd<=o[i][1])
            {
                ans.push_back({freeEnd+1,o[i][1]});
            }
            else ans.push_back({o[i][0],o[i][1]});
        }

        return ans;
        
    }
};