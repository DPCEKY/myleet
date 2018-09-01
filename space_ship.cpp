int calMinTime(int n, int x) {
  int N = n * 2;
  std::vector<bool> visited(N, false);
  std::queue<int> q;
  q.push(x);
  
  int res = 0;
  while(!q.empty()) {
    int size = q.size();
    for(int i = 0; i < size; i++) {
      auto j = q.front();
      q.pop();
      if(j == n)
        return res;
      else if(visited[j] == true)
        continue;
      else {
        if(j + 1 < N && visited[j + 1] == false) {
          visited[j + 1] = true;
          q.push(j + 1);
        }
        if(j - 1 >= x && visited[j - 1] == false) {
          visited[j - 1] = true;
          q.push(j - 1);
        }
        if(j * 2 < N && visited[j * 2] == false) {
          visited[j * 2] = true;
          q.push(j * 2);
        }
      }
    }
    res++;
  }
}
