class Solution {
public:
  const int THOUSAND = 1000;
  const int MILLION = 1000000;
  const int BILLION = 1000000000;
  std::unordered_map<int, std::string> map;
  
  void init_map(void) {
    map.emplace(0, "Zero ");
    map.emplace(1, "One ");
    map.emplace(2, "Two ");
    map.emplace(3, "Three ");
    map.emplace(4, "Four ");
    map.emplace(5, "Five ");
    map.emplace(6, "Six ");
    map.emplace(7, "Seven ");
    map.emplace(8, "Eight ");
    map.emplace(9, "Nine ");
    map.emplace(10, "Ten ");
    map.emplace(11, "Eleven ");
    map.emplace(12, "Twelve ");
    map.emplace(13, "Thirteen ");
    map.emplace(14, "Fourteen ");
    map.emplace(15, "Fifteen ");
    map.emplace(16, "Sixteen ");
    map.emplace(17, "Seventeen ");
    map.emplace(18, "Eighteen ");
    map.emplace(19, "Nineteen ");
    map.emplace(20, "Twenty ");
    map.emplace(30, "Thirty ");
    map.emplace(40, "Forty ");
    map.emplace(50, "Fifty ");
    map.emplace(60, "Sixty ");
    map.emplace(70, "Seventy ");
    map.emplace(80, "Eithty ");
    map.emplace(90, "Ninty ");
  }
  string numberToWords(int num) {
    std::string res;
    init_map();
    if(num == 0)
      return "Zero";

    if(num / BILLION != 0) {
      res += sub_num(num / BILLION, "Billion ");
    }
    num %= BILLION;
    if(num / MILLION != 0) {
      res += sub_num(num / MILLION, "Million ");
    }
    num %= MILLION;
    if(num / THOUSAND != 0) {
      res += sub_num(num / THOUSAND, "Thousand ");
    }
    num %= THOUSAND;
    res += sub_num(num, "");

    if(res.back() == ' ')
      res.pop_back();
    return res;
  }

  string sub_num(int num, std::string str) {
    if(num == 0)
      return "";
    std::string res;
    if(num / 100 != 0) {
      res = res + map[num / 100] + "Hundred ";
      num %= 100;
    }
    if(num / 10 != 0) {
      if(num / 10 == 1) {
        if(num % 10 == 0) {
          res = res + "Ten ";
        }
        else
          res += map[num];
        res += str;
        return;
      }
      res += map[num - num % 10];
      num = num % 10;
    }
    if(num != 0) {
      res += map[num];
    }
    res += str;
    return;
  }
};


























