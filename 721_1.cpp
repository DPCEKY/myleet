class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> res;
    std::unordered_map<string, string> name; // {email, name}
    std::unordered_map<string, string> parent; // {email, parent}
    std::unordered_map<string, set<string>> unions;
    for(int i = 0; i < accounts.size(); i++) {
      auto acc_name = accounts[i][0];
      for(int j = 1; j < accounts[i].size(); j++) {
        name.emplace(accounts[i][j], acc_name);
        parent.emplace(accounts[i][j], accounts[i][j]);
      }
    }

    for(int i = 0; i < accounts.size(); i++) {
      auto p = accounts[i][1];
      p = find_parent(p, parent);
      for(int j = 2; j < accounts[i].size(); j++) {
        parent[find_parent(accounts[i][j], parent)] = p;
      }
    }
    
    for(auto it = parent.begin(); it != parent.end(); it++) {
      auto root_p = find_parent(it->first, parent);
      unions[root_p].insert(it->first);
    }

    for(auto it = unions.begin(); it != unions.end(); it++) {
      vector<string> indivi;
      for(auto j = it->second.begin(); j != it->second.end(); j++) {
        indivi.push_back(*j);
      }     
      indivi.insert(indivi.begin(), name[indivi[0]]);
      res.push_back(indivi);
    }
    return res;
  }

  string find_parent(const string s, std::unordered_map<string, string>& p) {
    if(p[s] == s)
      return s;
    else
      return find_parent(p[s], p);
  }
};

