// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
  Solution() : rd_num(0) {}

  int read(char *buf, int n) {
    int res = 0;
    int bn = 0;
    char b[5];

    if(n <= rd_num) {
      for(int i = 0; i < n; i++) {
        buf[i] = rd_buf[i];
      }
      buf[n] = '\0';
      for(int i = 0; i < rd_num - n; i++) {
        rd_buf[i] = rd_buf[n + i];
      }
      rd_num -= n;
      return n;
    }
    else if(rd_num != 0) {
      for(int i = 0; i < rd_num; i++) {
        buf[i] = rd_buf[i];
      }
      buf += rd_num;
      res += rd_num;
      n -= rd_num;
      rd_num = 0;
    }

    while(n > 0) {
      if(n <= 4) {
        bn = read4(b);
        if(bn > n) {
          rd_num = bn - n;
          for(int i = 0; i < rd_num; i++) {
            rd_buf[i] = b[i + n];
          }
        }
        bn = min(bn, n);
        for(int i = 0; i < bn; i++) {
          buf[i] = b[i];
        }
        res += bn;
        break;
      }
      
      bn = read4(b);
      for(int i = 0; i < bn; i++) {
        buf[i] = b[i];
      }
      res += bn;
      
      if(bn < 4) {
        break;
      }
      
      n -= 4;
      buf += 4;
    }
    
    buf[bn] = '\0';
    return res;
  }

private:
  char rd_buf[4];
  int rd_num;
};

