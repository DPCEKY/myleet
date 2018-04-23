class Solution {
public:
  Solution(){
    for(int i = 0; i < 50000; i++){
      hash[i] = -99999;
      index[i] = -1;
    }
  }
  bool enhash(int element, int position){
    if(element < 0) {
      int i = 0;
      while(true) {
        if(hash[i] == -99999) {
          hash[i] = element;
          index[i] = position;
          return true;
        }
        i++;
      }
    }
    if(hash[element % 50000] == -99999){
      hash[element % 50000] = element;
      index[element % 50000] = position;
      return true;
    }
    int i = 1;
    while(true) {
      int value = (element + i) % 50000;
      if(hash[value] == -99999) {
        hash[value] = element;
        index[value] = position;
        return true;
      }
      i++;
      if(i > 99) {
        std::cout << "Space not enough! Resize needed!" << std::endl;
        return false;
      }
    }
  }
  
  int find_hash(int element) {
    if(element < 0) {
      for(int i = 0; i < 99; i++) {
        if(hash[i] == element)
          return index[i];
      }
      return -1;
    }
    if(hash[element % 50000] == element)
      return index[element % 50000];
    int i = 1;
    while(true) {
      int value = (element + i) % 50000;
      if(hash[value] == -99999)
        return -1;
      else if(hash[value] == element)
        return index[value];
      else
        i++;
      if(i > 99)
        return -1;
    }
  }
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer;
    int i = 0;
    for(auto& element : nums) {
      int pre_index = find_hash(target - element);
      if(pre_index != -1) {
        answer.push_back(pre_index);
        answer.push_back(i);
        return answer;
      }
      enhash(element, i);
      i++;
    }
    return answer;
  }
private:
  int hash[50000];
  int index[50000];
};

