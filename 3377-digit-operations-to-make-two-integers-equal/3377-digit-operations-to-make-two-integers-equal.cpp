class Solution {
public:
    bool isPrime(int num)
    {
        if(num<2)return false;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)return false;
        }
        return true;
    }
    int minOperations(int n, int m) {

        if(isPrime(n) || isPrime(m))return -1;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(100001,INT_MAX);

        pq.push({n,n});
        dist[n]=n;

        while(!pq.empty())
        {
            int cost=pq.top().first;
            int num=pq.top().second;
            pq.pop();

            if(num==m)return cost;

            string str=to_string(num);
            for(int i=0;i<str.length();i++)
            {
                if(str[i]!='0')
                {
                    str[i]--;
                    int next=0;
                    for(int j=0;j<str.length();j++)
                    {
                        next=next*10+(str[j]-'0');
                    }
                    if(!isPrime(next) && dist[next]>next+cost && next>=0)
                    {
                        dist[next]=next+cost;
                        pq.push({next+cost,next});
                    }
                    str[i]++;
                }
                
                 if(str[i]!='9')
                {
                    str[i]++;
                    int next=0;
                    for(int j=0;j<str.length();j++)
                    {
                        next=next*10+(str[j]-'0');
                    }
                    if(!isPrime(next) && dist[next]>next+cost && next<=10000)
                    {
                        dist[next]=next+cost;
                        pq.push({next+cost,next});
                    }
                    str[i]--;
                }
            }
        }
        return -1;
    }
};