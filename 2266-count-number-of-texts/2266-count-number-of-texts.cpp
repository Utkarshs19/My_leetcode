class Solution {
public:
    const int mod=1000000007;

    set<string> st;
    

   vector<int> dp;
       

    int helper(int i,string &s)
    {
        if(i==s.length())return 1;

        if(dp[i]!=-1)return dp[i];

        long long x=0;

        if(i+1<=s.length() && st.count(s.substr(i,1)))
        x=(x+helper(i+1,s))%mod;

        if(i+2<=s.length() && st.count(s.substr(i,2)))
        x=(x+helper(i+2,s))%mod;

        if(i+3<=s.length() && st.count(s.substr(i,3)))
        x=(x+helper(i+3,s))%mod;

        if(i+4<=s.length() && st.count(s.substr(i,4)))
        x=(x+helper(i+4,s))%mod;

        return dp[i]=x;


    }

    int countTexts(string pressedKeys) {

    st.insert("2");    st.insert("22");    st.insert("222");    
    st.insert("3");    st.insert("33");    st.insert("333");    
    st.insert("4");    st.insert("44");    st.insert("444");   
    st.insert("5");    st.insert("55");    st.insert("555");    
    st.insert("6");    st.insert("66");    st.insert("666");
    st.insert("7");    st.insert("77");    st.insert("777");    st.insert("7777");
    st.insert("8");    st.insert("88");    st.insert("888");    
    st.insert("9");    st.insert("99");    st.insert("999");    st.insert("9999");

   
        dp.resize(100001,-1);
        return helper(0,pressedKeys);
        
    }
};