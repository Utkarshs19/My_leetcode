class Bank {
public:
    map<int,long long> m;
    Bank(vector<long long>& balance) {

        for(int i=0;i<balance.size();i++)
        {
            m[i+1]=balance[i];
        }
        
    }
    
    bool transfer(int account1, int account2, long long money) {

        if(m.find(account1)==m.end())return false;
        if(m.find(account2)==m.end())return false;
        

        if(m[account1]<money)return false;

        m[account1]=m[account1]-money;
        m[account2]+=money;
        return true;
        
    }
    
    bool deposit(int account, long long money) {

         if(m.find(account)==m.end())return false;

         m[account]+=money;
         return true;
        
    }
    
    bool withdraw(int account, long long money) {
        
         if(m.find(account)==m.end())return false;

         if(m[account]<money)return false;

         m[account]-=money;
         return true;

    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */