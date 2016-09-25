class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i, j, k;
	for(i = m - 1, j = n + m - 1; i >= 0; --i, --j) nums1[j] = nums1[i];
	for(i = j + 1, j = 0, k = 0; i < n + m && j < n; ) {
	    if(nums1[i] < nums2[j]) {
		nums1[k] = nums1[i];
		++i;
	    }
	    else {
		nums1[k] = nums2[j];
		++j;
	    }
	    ++k;
	}
	while(i < m + n) nums1[k++] = nums1[i++];
	while(j < n) nums1[k++] = nums2[j++];
    }
};
