class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {      
        int mini=0;
        int maxi=0;

        
        for(int i=indexDifference;i<nums.size();i++)
        {
           int prev=i-indexDifference;
           if(nums[prev]<nums[mini])mini=prev;
           if(nums[prev]>nums[maxi])maxi=prev;

           if(nums[i]-nums[mini]>=valueDifference)return {i,mini};
           if(nums[maxi]-nums[i]>=valueDifference)return {maxi,i};
           

        }

        return {-1,-1};

    }
};