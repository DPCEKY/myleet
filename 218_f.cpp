class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> res;
    for(int i = 0; i < buildings.size(); i++) {
      addBuilding(res, buildings[i]);
    }
    return res;
  }

  void addBuilding(vector<pair<int, int>>& skyline, vector<int>& building) {
    int left = building[0];
    int right = building[1];
    int h = building[2];
    cout << "left = " << left << ", right = " << right << ", h = " << h << endl;
    if(skyline.empty()) {
      skyline.push_back({left, h});
      skyline.push_back({right, 0});
      return;
    }
    else if(skyline.back().first <= left) {
      if(skyline.back().first == left) {
        if(h != skyline[skyline.size() - 2].second)
          skyline.back().second = h;
        else
          skyline.pop_back();
      }
      else if(skyline.back().first < left)
        skyline.push_back({left, h});
      skyline.push_back({right, 0});
      return;
    }
    
    int i = 0;
    for(i = 0; i < skyline.size(); i++) {
      auto pair = skyline[i];
      if(pair.first >= left) {
        break;
      }
    }
    if(skyline[i - 1].second < h) {
      if(left == skyline[i].first) {
        if(h > skyline[i].second)
          skyline[i].second = h;
      }
      else {
        skyline.insert(skyline.begin() + i, {left, h});
      }
    }

    cout << "i = " << i << endl;
    int pre_h = skyline[i - 1].second;
    while(i < skyline.size()) {
      if(skyline[i].first >= right) {
        if(skyline[i].first == right) {
          if(h > skyline[i].second && i != skyline.size() - 1)
            skyline[i].second = h;
          return;
        }
        if(skyline[i - 1].second < h) {
          skyline[i - 1].second = h;
          skyline.insert(skyline.begin() + i, {right, pre_h});
        }
        return;
      }

      if(skyline[i].second < h) {
        if(skyline[i - 1].second != h) {
          pre_h = skyline[i].second;
          skyline[i].second = h;          
        }
        else {
          skyline.erase(skyline.begin() + i);
          continue;
        }
      }
      i++;
    }

    skyline.back().second = h;
    skyline.push_back({right, 0});
  }
};

