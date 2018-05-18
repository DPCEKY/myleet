class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pm = m - 1, pn = n - 1;
    int end = m + n - 1;
    while(pm >= 0 && pn >= 0) {
      if(nums1[pm] >= nums2[pn]) {
        nums1[end--] = nums1[pm--];
      }
      else
        nums1[end--] = nums2[pn--];
    }

    while(pn >= 0)
      nums1[end--] = nums2[pn--];

    return;
  }
};
