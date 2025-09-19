class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        
        int sum=0;

        set<int> st;

        for(auto i:nums){
            st.insert(i);
        sum+=i;
}
int n=nums.size();

cout<<sum<<endl;
        int avg;
            avg=sum/n;
        cout<<avg<<endl;
            avg++;
        if(avg<=0)avg=1;

        while(avg)
        {
            if(!st.count(avg)&&avg>0)
            return avg;

            avg++;
        }


        return -1;

    }
};