//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
        
    bool static cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            pair<int,int> p;
            p.first=start[i];
            p.second=end[i];
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int ans=1;
        int x=v[0].second;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first>x)
            {
                ans++;
                x=v[i].second;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends