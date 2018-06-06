// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
  int read(char *buf, int n) {
    int res = 0;
    if(n <= 4) {
      res = read4(buf);
      return min(n, res);
    }
    res = read4(buf);
    if(res <= 3) {
      return res;
    }
    else {
      return 4 + read(buf + 4, n - 4);
    }
  }
};
