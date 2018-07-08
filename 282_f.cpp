class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    if(num.empty())
      return res;
    for(int i = 0; i < num.size() - 1; i++) {
      if()
    }
    
  }

  std::string genStr(string left, string num, std::vector<string>& to_cal) {
    if(num.size() == 1)
      return num;
    to_cal.push_back(left + num[0] + "+" + num.substr(1));
    to_cal.push_back(left + num[0] + "-" + num.substr(1));
    to_cal.push_back(left + num[0] + "*" + num.substr(1));
    return 
  }

  int calOp(string func) {
    int num = 0;
    std::vector<char> stack;
    std::vector<int> stack_p;
    std::vector<std::pair<int, bool>> post;
    for(int i = 0; i < func.size(); i++) {
      if(func[i] <= '9' && func[i] >= '0')
        num = num * 10 + func[i] - '0';
      else {
        post.push_back({num, false});
        switch(func[i]) {
          case '*': stack.push_back('*'); break;
          case '+':
          case '-': {
            while(!stack.empty()) {
              post.push_back({stack.back(), true});
              stack.pop_back();
            }
            stack.push_back(func[i]);
          } break;
        }
      }
      if(i == func.size() - 1) {
        post.push_back({num, false});
        while(!stack.empty()) {
          post.push_back({stack.back(), true});
          stack.pop_back();
        }
      }
    }
    for(int i = 0; i < post.size(); i++) {
      if(!post[i].second)
        stack_p.push_back(post[i].first);
      else {
        switch(post[i].first) {
          case '+': {
            auto first = stack_p.back();
            stack_p.pop();
            auto second = stack_p.back();
            stack_p.pop();
            stack_p.push_back(first + second);
          } break;
          case '-': {
            auto first = stack_p.back();
            stack_p.pop();
            auto second = stack_p.back();
            stack_p.pop();
            stack_p.push_back(first - second);
          } break;
          case '*': {
            auto first = stack_p.back();
            stack_p.pop();
            auto second = stack_p.back();
            stack_p.pop();
            stack_p.push_back(first * second);
          } break;
        }
      }
    }
    return stack_p.back();
  }
};
























