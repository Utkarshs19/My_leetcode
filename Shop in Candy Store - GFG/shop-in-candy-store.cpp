//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
        sort(candies,candies+N);
        
        vector<int> ans;
        int mini=0;
        int maxi=0;
        
        int j=N-1;
        for(int i=0;i<=j;i++)
        {
            mini+=candies[i];
            j=j-K;
        }
        j=0;
        for(int i=N-1;i>=j;i--)
        {
            maxi+=candies[i];
            j=j+K;
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends