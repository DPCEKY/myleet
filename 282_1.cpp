class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    if(num.empty())
      return res;

    for(int i = 1; i < num.size() + 1; i++) {
      auto sub = num.substr(0, i);
      if(sub[0] == '0' && sub.size() != 1) {
        break;
      }
      long val = stol(sub);
      BT(num, target, res, i, sub, val, val);
    }
    return res;
  }

  void BT(string num, int target, vector<string>& res, int pos, string path, long prev_val, long final_val) {
    if(pos == num.size()) {
      if(final_val == target) {
        res.push_back(path);
      }
      return;
    }
    for(int i = pos; i < num.size(); i++) {
      auto sub = num.substr(pos, i - pos + 1);
      if(sub[0] == '0' && i != pos)
        return;
      long val = stol(sub);

      BT(num, target, res, i + 1, path + '+' + sub, val, final_val + val);
      BT(num, target, res, i + 1, path + '-' + sub, -val, final_val - val);
      BT(num, target, res, i + 1, path + '*' + sub, prev_val * val, final_val - prev_val + prev_val * val);
      
    }
    return;
  }
};

