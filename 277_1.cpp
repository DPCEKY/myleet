// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
  int findCelebrity(int n) {
    if(n == 0)
      return -1;
    else if(n == 1)
      return 0;

    std::list common;
    for(int i = 1; i < n; i++) {
      if(knows(0, i))
        common.push_back(i);
    }
    if(common.empty())
      return check_celerity(0);

    int i;
    for(i = 1; i < n; i++) {
      if(common.empty())
        return -1;
      for(auto it = common.begin(); it != common.end(); ) {
        if(i == it || knows(i, it)) {
          it++;
          continue;
        }
        it = common.erase(it);
      }
    }

    for(auto it : common) {
      if(check_celerity(it) != -1)
        return it;
    }
    return -1;
  }

  int check_celerity(int celerity) {
    for(int i = 0; i < n; i++) {
      if(i != celerity && knows(celerity, i))
        return -1;
    }

    for(int i = 0; i < n; i++) {
      if(i != celerity && !knows(i, celerity))
        return -1;
    }
    return celerity;
  }
};
