class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {

        int h1=0,h2=0;

        int r=red,b=blue;
        int k=1;

        while(r>0 || b>0)
        {   
            if(r-k>=0)
            r=r-k;
            else break;
            k++;
            h1++;
            
            if(b-k>=0)
            b=b-k;
            else break;
            k++;
            h1++;
        }

        r=red;
        b=blue;
        k=1;

        while(r>0 || b>0)
        {
            if(b-k>=0)
            b=b-k;
            else break;
            k++;
            h2++;
            
            if(r-k>=0)
            r=r-k;
            else break;
            k++;
            h2++;
        }

        cout<<h1<<"  "<<h2; 

        return h1>h2?h1:h2;
        
    }
};