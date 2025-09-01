class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        double ans=0.0;
        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<classes.size();i++)
        {
            double change;
            double x=classes[i][0];
            double y=classes[i][1];

            change=((x+1)/(y+1))-(x/y);


            pq.push({change,{classes[i][0],classes[i][1]}});
        }


        while(extraStudents>0)
        {
            double x=pq.top().first;
            double first=pq.top().second.first;
            double second=pq.top().second.second;
            pq.pop();
            first=first+1;
            second=second+1;

            x=((first+1)/(second+1))-(first/second);

            pq.push({x,{first,second}});

            extraStudents--;
        }

        

        while(!pq.empty())
        {
            int first=pq.top().second.first;
            int second=pq.top().second.second;

            cout<<pq.top().first<<"-->  "<<first<<" "<<second<<endl;

            pq.pop();
            ans+=(double)first/second;
        }


        return double(ans/classes.size());

    }
};