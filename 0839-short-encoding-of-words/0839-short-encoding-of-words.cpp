class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        if(words.size()==1)
        return words[0].size()+1;

        priority_queue<pair<int,string>> pq;

        for(int i=0;i<words.size();i++)
        {
            pq.push({words[i].length(),words[i]});
        }

        map<string,int> m;

        while(!pq.empty())
        {
            string s=pq.top().second;
            pq.pop();
            bool flag=false;
            for(auto i:m)
            {
                string str=i.first;
                if(str.substr(str.length()-s.length())==s)
                {flag=true;
                break;}
            }
            if(flag==false)
            m[s]++;
        }
        int ans=0;
        for(auto i:m)
        {


            ans+=i.first.length();
        }
        ans+=m.size();

        return ans;
    }
};