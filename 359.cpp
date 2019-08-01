class Logger {
public:
  std::unordered_map<string, int> logs;
  /** Initialize your data structure here. */
  Logger() {

  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if(logs.count(message) == 0) {
      logs[message] = timestamp;
      return true;
    }
    else {
      if(logs[message] + 10 <= timestamp) {
        logs[message] = timestamp;
        return true;
      }
      return false;
    }
  }
};

/**
* Your Logger object will be instantiated and called as such:
* Logger* obj = new Logger();
* bool param_1 = obj->shouldPrintMessage(timestamp,message);
*/
