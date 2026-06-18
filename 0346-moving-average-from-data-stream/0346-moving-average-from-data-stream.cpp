class MovingAverage {
public:
    int i=0,j=0;
    vector<double > v;
    int size;
    double sum=0.0;

    MovingAverage(int size) {
        this->size=size;

    }
    
    double next(int val) {

        sum+=val;

        v.push_back(val);
        if(j-i+1>size)
        {
            sum=sum-v[i];
            i++;
        }
        
        double ans= (double)sum/(j-i+1);
        j++;
        return ans;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */