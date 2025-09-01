class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) {
        v.resize(rows);
        for(int i=0;i<rows;i++)
        v[i].resize(26);

        
    }
    
    void setCell(string cell, int value) {
        
        char x=cell[0];
        
        int y=stoi(cell.substr(1));

        v[y-1][x-'A']=value;

    }
    
    void resetCell(string cell) {
        char x=cell[0];
       int y=stoi(cell.substr(1));

        v[y-1][x-'A']=0;
    }
    
    int getValue(string formula) {
        
        string str=formula.substr(1);

        string first="";
        string second="";

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='+')
            {
                first=str.substr(0,i);
                second=str.substr(i+1);
                break;
            }
        }
        cout<<first<<" "<<second<<endl;
        int ans=0;
        int x=0,y=0;
        if(isalpha(first[0]))
        {
            x=v[stoi(first.substr(1))-1][first[0]-'A'];
        }
        else
        {
            x=stoi(first);
        }

         if(isalpha(second[0]))
        {
            y=v[stoi(second.substr(1))-1][second[0]-'A'];
        }
        else
        {
            y=stoi(second);
        }

        return x+y;


    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */