  vector<int> save(vector<vector<int> >& network, vector<int> initial_machines) {
    int N = network.size();
    vector<int> group(N, 0);
    vector<int> group_size(N, 1);
    for(int i = 0; i < N; i++)
      group[i] = i;
    std::unordered_map<int, int> map;
    for(int i = 0; i < N; i++) {
      for(int j = i + 1; j < N; j++) {
        if(network[i][j] == 1)
          uni(group, group_size, i, j);
      }
    }
    for(int i = 0; i < initial_machines.size(); i++) {
      int aff = initial_machines[i];
      int p = find(group, i);
      if(map.find(p) != map.end())
        map[aff] = 0;
      else
        map[aff] = group_size[p];
    }
    vector<int> res(2);
    int saved = -1, index = INT_MAX;
    for(auto it : map) {
      if(it.second > saved) {
        res[0] = it.first;
        res[1] = it.second;
        index = it.first;
      }
      else if(it.second == saved && it.first < index) {
        index = it.first;
        res[0] = it.first;
      }
    }
    return res;
  }

  void uni(vector<int>& group, vector<int>& group_size, int i, int j) {
    int pi = find(group, i);
    int pj = find(group, j);
    if(pi == pj)
      return;
    group[pi] = pj;
    group_size[pj] += group_size[pi];
    return;
  }

  int find(vector<int>& group, int i) {
    if(group[i] == i)
      return i;
    int p = find(group, group[i]);
    group[i] = p;
    return p;
  }

