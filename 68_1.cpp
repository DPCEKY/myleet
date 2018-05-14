class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    if(words.empty()) {
      string tmp;
      string.append(macwidth, ' ');
      res.push_back(string);
      return res;
    }

    for(auto it = words.begin(); it != words.end(); ) {
      string tmp;
      int cur_width = 0;
      auto start = it;
      int num = 0;
      while(it != words.end() && cur_width + it.size() <= maxWidth) {
        if(it.size() + cur_width < maxWidth) {
          num++;
          cur_width = cur_width + it.size() + 1;
          it++;
        }
        else
          break;
      }

      if(it == words.end()) {
        cur_width = 0;
        do{
          tmp = tmp + start + ' ';
          cur_width = cur_width + start.size() + 1;
          start++;
          num--;
        }while(num > 0);
        tmp.append(maxWidth - cur_width, ' ');

        res.push_back(tmp);
        return res;
      }
      else {
        if(num == 1) {
          tmp = start.append(maxWidth - cur_width, ' ');
        }
        else {
          cur_width -= num;
          int even_space_num = (maxWidth - cur_width) / (num - 1);
          tmp = start.append((maxWidth - cur_width)  % (num - 1) + even_space_num, ' ');
          num--;
          start++;
          while(num > 1) {
            tmp += start.append(even_space_num, ' ');
            num--;
            start++;
          }
          tmp += start;
        }
        res.push_back(tmp);
      }

    }
    return res;
  }
};
