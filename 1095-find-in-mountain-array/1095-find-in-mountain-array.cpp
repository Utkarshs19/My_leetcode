/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n=mountainArr.length();

        int l=0,r=n-1;
        int peak;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int mid=mountainArr.get(m);
            int left=m==0?-1:mountainArr.get(m-1);
            int right=m==n-1?-1:mountainArr.get(m+1);

            if(mid>left && mid>right)
            {
                peak=m;
                break;
            }
            else if(mid>left && mid<right)
            l=m+1;
            else
            r=m-1;
        }

        l=0,r=peak;

        while(l<=r)
        {
            int m=l+(r-l)/2;
             int mid=mountainArr.get(m);
            if(mid==target)return m;
            else if(mid<target)l=m+1;
            else
            r=m-1;
        }
        
        l=peak,r=n-1;

        while(l<=r)
        {
            int m=l+(r-l)/2;
            int mid=mountainArr.get(m);
            if(mid==target)return m;
            else if(mid<target)r=m-1;
            else
            l=m+1;
        }
        return -1;
    }
};