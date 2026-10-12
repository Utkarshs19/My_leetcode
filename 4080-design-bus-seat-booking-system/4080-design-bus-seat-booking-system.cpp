class BusBooking {
public:
    map<string,int> m;
    int n;
    int time=0;
    BusBooking(int n) {
    
    this->n=n;    
        
    }
    
    void toggle(string seat) {

        char ch=seat[0];
        string num=seat.substr(1);
        
        if(m.count(seat)){time-=m[seat];
                           m.erase(seat);
                           return;
                          }
        if(m.count(seat)){time-=m[seat];
                           m.erase(seat);
                          return;
                          }
    
        if(seat[0]=='A' || seat[0]=='D'){
            if(seat[0]=='A')
            {
                string str;
                str+='B';
                str+=num;
                if(m.count(str))
                {time+=3;
                 m[seat]=3;
                }
                else{
                    time+=1;
                m[seat]=1;}
            }
            else
            {
                string str;
                str+='C';
                str+=num;
                if(m.count(str)){time+=3;m[seat]=3;}
                else {time+=1;m[seat]=1;}
            }
        }
        else
        {
            time+=1;
            m[seat]=1;
        }
        
    }
    
    int getTotalTime() {
        return time;
    }
    
    int getMinTime() {
        return m.size();
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */