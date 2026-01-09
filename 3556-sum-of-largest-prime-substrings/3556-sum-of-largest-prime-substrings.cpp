class Solution {
public:
    long long ans=0;

    bool valid(long long n)
    {

          int cnt = 0; 

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;  
            if (n / i != i) {
                cnt++;
            }
        }
    }

    if (cnt == 2) {
        return true;
    } else {
        return false;  
    }

        
    }



    long long sumOfLargestPrimes(string s) {

        priority_queue<long long> pq;
        set<long long> st;

        for(int i=0;i<s.length();i++)
        {
            long long x=0;

            for(int j=i;j<s.length();j++)
            {
                x=x*10+(s[j]-'0');

                if(valid(x)){
                    if(st.find(x)==st.end())
                    pq.push(x);
                    st.insert(x);}
            }
            
        }

        int k=3;
        while(k-- && !pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }

        return ans;


        
    }
};