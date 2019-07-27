/**
* // This is the Master's API interface.
* // You should not implement it, or speculate about its implementation
* class Master {
*   public:
*     int guess(string word);
* };
*/
class Solution {
public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    vector<string> mywords = wordlist;
    for(int i = 0; i < 10; i++) {
      string word = mywords[0];
      int num = master.guess(word);
      if(num == 6)
        return;
      vector<string> next_round;
      for(auto& myword : mywords) {
        if(num == diff(myword, word)) { 
          next_round.push_back(myword);
        }
      }
      mywords.swap(next_round);
    }
  }

  int diff(string a, string b) {
    int res = 0;
    for(int i = 0; i < 6; i++) {
      res += a[i] == b[i];
    }
    return res;
  }
};
