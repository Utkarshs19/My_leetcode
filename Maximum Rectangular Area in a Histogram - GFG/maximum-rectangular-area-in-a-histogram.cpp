//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> v(n,0),v1(n,0);
        stack<pair<long long,int>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)v[i]=n;
            else if(st.size()>0&&st.top().first<arr[i])v[i]=st.top().second;
            else if(st.size()>0&&st.top().first>=arr[i]){
                while(st.size()>0&&st.top().first>=arr[i])st.pop();
                
                if(st.size()==0)v[i]=n;
                else v[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        while(st.size()>0)st.pop();
        
        for(int i=0;i<n;i++)
        {
              if(st.size()==0)v1[i]=-1;
            else if(st.size()>0&&st.top().first<arr[i])v1[i]=st.top().second;
            else if(st.size()>0&&st.top().first>=arr[i]){
                while(st.size()>0&&st.top().first>=arr[i])st.pop();
                
                if(st.size()==0)v1[i]=-1;
                else v1[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        
        long long int ans=-1e9;
        
        for(int i=0;i<v.size();i++)
        {
            long long int temp=v[i]-v1[i]-1;
            temp=temp*arr[i];
            
            ans=max(ans,temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends