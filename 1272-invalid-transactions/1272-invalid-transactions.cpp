class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {

        vector<string> ans;
        int n=transactions.size();

        vector<string> name;
        vector<int> time;
        vector<int> amount;
        vector<string> city;

        for(auto s:transactions )
        {
            int p1=s.find(',');
            int p2=s.find(',',p1+1);
            int p3=s.find(',',p2+1);

            name.push_back(s.substr(0,p1));
            time.push_back(stoi(s.substr(p1+1,p2-p1-1)));
            amount.push_back(stoi(s.substr(p2+1,p3-p2-1)));
            city.push_back(s.substr(p3+1));
        }

        vector<bool> invalid(n,false);

        for(int i=0;i<n;i++)
        {
            if(amount[i]>1000)invalid[i]=true;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;

                if(name[i]==name[j] && city[i]!=city[j] && abs(time[i]-time[j])<=60)
                {invalid[i]=true;
                break;}
            }
        }

        for(int i=0;i<n;i++)
        {
            if(invalid[i])
            ans.push_back(transactions[i]);
        }

        return ans;
        
    }
};