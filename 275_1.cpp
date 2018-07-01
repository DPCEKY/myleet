class Solution {
public:
  int hIndex(vector<int>& citations) {
    int num = citations.size();
    if(num == 0)
      return 0;
    else if(num == 1)
      return citations[0] != 0;
    else if(num == 2)
      return citations[1] == 0 ? 0 : citations[0] < 2 ? 1 : 2;

    int h = num / 2;
    int left = 0, right = num;
    while(true) {
      if(h == 0) {
        return (citations[num - 1] != 0);
      }
      else if(h == num - 1)
        return citations[0] >= num? num : num - 1;

      if(h + 1 <= citations[num - 1 - h] && (h + 2) > citations[num - 2 - h])
        return h + 1;
      if(h + 1 <= citations[num - 1 - h]) {
        left = h;
        h = (h + right) / 2;
      }
      else {
        right = h;
        h = (left + h) / 2;
      }
    }
  }
};
