class Solution {
public:
  int hammingDistance(int x, int y) {
    unsigned int z = (x ^ y);
    int res = 0;
    for(int i = 0; i < 32; i++) {
      if(z & 1 == 1)
        res++;
      z = z >> 1;
    }
    return res;
  }
};
