class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n) {
            ret++;
            n &= (n - 1);
        }
        return ret;
    }
};
