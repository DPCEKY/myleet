class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    std::unordered_map<string, vector<string>> map;
    for(auto path : paths) {
      int pos = path.find_first_of(' ');
      auto dir = path.substr(0, pos);
      while(true) {
        int new_pos = path.find_first_of(' ', pos + 1);
        std::string file;
        if(new_pos != string::npos)
          file = path.substr(pos + 1, new_pos - pos - 1);
        else
          file = path.substr(pos + 1);
        auto pos_content = file.find_first_of('(');
        auto content = file.substr(pos_content + 1);
        content.pop_back();
        auto full_path = dir + '/' + file.substr(0, pos_content);
        if(map.find(content) == map.end()) {
          vector<string> tmp = {full_path};
          map.emplace(content, tmp);
        }
        else
          map[content].push_back(full_path);
        pos = new_pos;
        if(new_pos == std::string::npos)
          break;
      }
    }
    vector<vector<string>> res;
    for(auto pair : map) {
      auto path_all = pair.second;
      if(path_all.size() > 1)
        res.push_back(path_all);
    }
    return res;
  }
};

