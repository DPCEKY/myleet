class Solution {
public:
  int numFriendRequests(vector<int>& ages) {
    vector<int> age(120, 0);
    for(int i = 0; i < ages.size(); i++) {
      age[ages[i]]++;
    }
    int lower_age = 120 * 0.5 + 8;
    int people = 0;
    for(int i = 120; i >= lower_age; i--) {
      people += age[i];
    }
    int res = 0;
    for(int i = 120; i > 14; i--) {
      people -= age[i];
      if(i % 2 == 1)
        people += age[--lower_age];
      res += age[i] * people + (age[i] * age[i - 1]) / 2;
    }
    return res;
  }
};
