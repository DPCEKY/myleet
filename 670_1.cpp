class Solution {
public:
  int maximumSwap(int num) {
    std::string number = std::to_string(num);
    if(number.size() < 2)
      return num;
    int first = -1, second = -1;
    char prev = number[0];
    for(int i = 1; i < number.size(); i++) {
      if(prev < number[i]) {
        if(first == -1) {
          first = i - 1;
          second = i;
        }
      }
      if(second != -1 && number[second] <= number[i]) {
        second = i;
      }
      prev = number[i];
    }
    if(first == -1)
      return num;
    for(int i = 0; i < first + 1; i++) {
      if(number[i] < number[second]) {
        auto tmp = number[i];
        number[i] = number[second];
        number[second] = tmp;
        break;
      }
    }
    return std::stoi(number);
  }
};

