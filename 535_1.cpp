class Solution {
public:

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    urls.push_back(longUrl);
    return std::to_string(urls.size() - 1);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    int index = stoi(shortUrl);
    return urls[index];
  }
private:
  std::vector<std::string> urls;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
