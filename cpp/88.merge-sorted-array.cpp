class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_write = nums1.size()-1;
        int nums1_read = m-1;
        int nums2_read = n-1;
            
        if (nums2.empty()) return;
        
        while (nums1_write >= m && m >= 0) { 
            if (nums1_read >=0 && nums1[nums1_read] > nums2[nums2_read]) {
                nums1[nums1_write] = nums1[nums1_read];
                nums1_read--;
                m--;
            } else {
                nums1[nums1_write] = nums2[nums2_read];
                nums2_read--;
            }  
            
            nums1_write--;
        }
    }
};
