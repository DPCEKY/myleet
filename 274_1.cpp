class Solution {
public:
  int hIndex(vector<int>& citations) {
    if(citations.empty())
      return 0;

    std::sort(citations.begin(), citations.end());
    int h = 0;
    int num = citations.size();
    for(int i = 0; i < citations.size(); i++) {
      h++;
      if(h > citations[num - i - 1])
        return h - 1;
    }
    return h;
  }
};
