/**
* // This is the robot's control interface.
* // You should not implement it, or speculate about its implementation
* class Robot {
*   public:
*     // Returns true if the cell in front is open and robot moves into the cell.
*     // Returns false if the cell in front is blocked and robot stays in the current cell.
*     bool move();
*
*     // Robot will stay in the same cell after calling turnLeft/turnRight.
*     // Each turn will be 90 degrees.
*     void turnLeft();
*     void turnRight();
*
*     // Clean the current cell.
*     void clean();
* };
*/
class Solution {
public:
  void cleanRoom(Robot& robot) {
    dfs(robot, 0, 0, 0);
    return;
  }

  int get_next_x(int x, int facing_side) {
    return x + (facing_side % 4 == 3) * 1 + (facing_side % 4 == 1) * (-1);
  }

  int get_next_y(int y, int facing_side) {
    return y + (facing_side % 4 == 0) * 1 + (facing_side % 4 == 2) * (-1);
  }

  void dfs(Robot& robot, int x, int y, int facing_side) {
    if(check(x, y)) {
      return;
    }
    add(x, y);
    robot.clean();
    
    // 0 degree
    if(robot.move()) {
      dfs(robot, get_next_x(x, facing_side), 
          get_next_y(y, facing_side), facing_side);
      move_back(robot);
    }
    
    // 90 degree left ~ 270 left
    for(int i = 0; i < 3; i++) {
      robot.turnLeft();
      facing_side += 1;
      if(robot.move()) {
        dfs(robot, get_next_x(x, facing_side), 
            get_next_y(y, facing_side), facing_side);
        move_back(robot);
      }
    }

    robot.turnLeft();
    facing_side += 1;
  }
  
  void move_back(Robot& robot) {
    robot.turnLeft();
    robot.turnLeft();
    robot.move();
    robot.turnLeft();
    robot.turnLeft();
  }

  std::map<int, std::set<int>> cleaned_areas;
  bool check(int x, int y) {
    return !(cleaned_areas.count(x) == 0 || cleaned_areas[x].count(y) == 0);
  }

  void add(int x, int y) {
    cleaned_areas[x].insert(y);
  }
};











