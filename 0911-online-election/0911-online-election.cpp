class TopVotedCandidate {
public:

    map<int,int> m;
    int person=-1;
    int maxi=-1;
    vector<int> times;
    vector<int> v;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        this->times=times;

        for(int i=0;i<times.size();i++)
        {
            m[persons[i]]++;

            if(maxi<=m[persons[i]])
            {
                maxi=m[persons[i]];
                person=persons[i];
            }
            v.push_back(person);
        }

    }
    
    int q(int t) {
        
        auto it=upper_bound(times.begin(),times.end(),t);
        int idx=it-times.begin()-1;

        return v[idx];

    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */