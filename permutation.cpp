#include <iostream>
#include <vector>
using namespace std;

vector<int> findPermutation(string s) {
  /*
  IIDIDD
  1234567
  1243765
  */
  
  vector<int> res(s.size() + 1, 0);
  int pos = 0;
  for(int i = s.size() - 1; i >= 0; ) {
    if(s[i] == 'D') {
      pos = i + 1;
      i--;
      int k = 1;
      while(i >= 0 && s[i] == 'D') {
        k++;
        i--;
      }
      for(int j = pos; j >= i + 1; j--) {
        res[j] = pos - j + 1;
      }
    }
    else {
      i--;
    }
  }
  for (unsigned int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < s.size(); ) {
    if(s[i] == 'I') {
      pos = i++;
      int k = 1;
      while(i < s.size() && s[i] == 'I') {
        k++;
        i++;
      }
      for(int j = pos; j <= pos + k; j++) {
        res[j] = max(j - pos + 1, res[j]);
      }
    }
    else {
      i++;
    }
  }

  return res;
}


// To execute C++, please define "int main()"
int main() {
  // 1 2 3 1 3 2 1
  auto res = findPermutation("IIDIDD");
  for (unsigned int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}

