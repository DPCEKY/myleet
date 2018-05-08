class Solution {
public:
  string countAndSay(int n) {
    string target;
    target.push_back('1');
    
    if(n == 1) {
      return target;
    }

    string res;
    for(int i = 1; i < n; i++) {
      unsigned char counter = '0';
      unsigned char last = ' ';
      for(int j = 0; j < target.size(); j++) {
        if(last == target[j]) {
          counter++;
        }
        else if(last == ' ') {
          counter++;
          last = target[0];
        }
        else {
          res.push_back(counter);
          res.push_back(last);
          last = target[j];
          counter = '1';
        }
      }
      res.push_back(counter);
      res.push_back(last);
      target = res;
      res.clear();
    }
    return target;
  }
};
