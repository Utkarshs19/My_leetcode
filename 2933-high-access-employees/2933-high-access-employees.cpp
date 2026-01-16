class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        map<string,vector<string>> m;
        vector<string> ans;
        for(int i=0;i<access_times.size();i++)
        {
            m[access_times[i][0]].push_back(access_times[i][1]);
        }

        for(auto i:m)
        {
            sort(i.second.begin(),i.second.end());

            vector<string> v=i.second;

            for(int j=0;j<v.size();j++)
            {
                string s = v[j];  
                int firstTwo = stoi(s.substr(0, 2));  
                firstTwo += 1;                        

                string str = "";
                str += (firstTwo < 10 ? "0" : "") + to_string(firstTwo);
                str += s.substr(2);    
                cout<<str<<endl;
                int cnt=0;
                for(int k=j+1;k<v.size();k++)
                {
                    if(v[k]<str)cnt++;
                }
                if(cnt==2){
                ans.push_back(i.first);break;}
            }

        }
        return ans;
        
    }
};