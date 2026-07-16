class Solution {
public:
      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0,
        h1 = n-1, h2 = m-1, mid1, mid2, mid = (m+n)/2+1;

        while(mid--) {
            
            mid2 = mid1;
            if(i < n && j < m) {
                if(nums1[i] < nums2[j]) {
                    mid1 = nums1[i++];
                } else {
                    mid1 = nums2[j++];

                }
            } else if (i < n){
                mid1 = nums1[i++];
            } else {
                mid1 = nums2[j++];
            }
        }
        cout<<mid1<<" "<<mid2<<endl;
        if((n+m)%2) {
            return mid1;
        } 

        return (double(mid1+mid2)/2);
    }
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size(), m = nums2.size(), l1 = 0, l2 = 0,
    //     h1 = n-1, h2 = m-1, mid1, mid2, mid = (m+n)/2;

    //     while(l1<=h1 && l2<= h2) {
    //         mid1 = (l1+h1)/2;
    //         mid2 = (l2+h2)/2;
    //         cout<<l1 <<" "<< l2<<endl;
    //         if(nums1[mid1] < nums2[mid2]) {
    //             if(mid1)
    //             mid -= mid1 - 1;
    //             l1 = mid1;
    //         } else {
    //             if(mid2)
    //             mid -= mid2-1;
    //             l2 = mid2;
    //         }
    //         if(mid <= 0) break;
    //     }

    //     cout<<l1 <<" "<< l2<<endl;

    //     return 0;
    // }
};
