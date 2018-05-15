// no so good with two stacks.
class Solution {
public:
  string simplifyPath(string path) {
    if(path == "/")
      return path;

    std::stack<string> pre;

    while(!path.empty()) {
      string dir;
      int pos = 0;
      do {
        pos = path.find_first_of("/", 1);
        if(pos != std::string::npos) {
          dir = path.substr(1, pos - 1);
          path = path.substr(pos);
        }
      } while(pos == 1);
      
      if(pos == std::string::npos) {
        dir = path.substr(1);
        path.clear();
      }

      if(dir == ".")
        continue;
      else if(dir == "..") {
        if(pre.empty())
          continue;
        else
          pre.pop();
      }
      else if(dir != "")
        pre.push(dir);
    }

    std::stack<string> sec;
    while(!pre.empty()) {
      auto str = pre.top();
      sec.push(str);
      pre.pop();
    }

    std::string res = "/";
    while(!sec.empty()) {
      res = res + sec.top() + "/";
      sec.pop();
    }
    if(res.size() != 1)
      res.pop_back();

    return res;
  }
};

