class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    if(stones.size() <= 1) {
      return 0;
    }

    int row_num = 0, col_num = 0;
    for(auto stone_row: stones) {
      row_num = max(row_num, stone_row[0]);
      col_num = max(col_num, stone_row[1]);
    }

    col_num += 1;
    row_num += 1;
    
    std::vector<int> my_stone_row(col_num, 0);
    std::vector<std::vector<int>> my_stones(row_num, my_stone_row);
    
    int count = 1;
    for(auto stone_row: stones) {
      my_stones[stone_row[0]][stone_row[1]] = count++;
    }

    count = 0;
    for(int i = 0; i < row_num; i++) {
      for(int j = 0; j < col_num; j++) {
        count += find_unions(my_stones, i, j, row_num, col_num);
      }
    }
  
    return stones.size() - count;
  }

  int find_unions(std::vector<std::vector<int>>& my_stones, int i, int j, int row_num, int col_num) {
    if(i < 0 || i >= row_num || j < 0 || j >= col_num || my_stones[i][j] == 0) {
      return 0;
    }

    my_stones[i][j] = 0;

    int i0 = i, j0 = j;
    if(i > 0) {
      while(i > 0 && my_stones[i][j] == 0)
        i--;
      find_unions(my_stones, i, j, row_num, col_num);
    }

    i = i0;
    if(i < row_num - 1) {
      while(i < row_num && my_stones[i][j] == 0)
        i++;
      find_unions(my_stones, i, j, row_num, col_num);
    }

    i = i0;
    if(j > 0) {
      while(j > 0 && my_stones[i][j] == 0)
        j--;
      find_unions(my_stones, i, j, row_num, col_num);
    }

    j = j0;
    if(j < col_num - 1) {
      while(j < col_num && my_stones[i][j] == 0)
        j++;
      find_unions(my_stones, i, j, row_num, col_num);
    }

    return 1;
  }
};



















