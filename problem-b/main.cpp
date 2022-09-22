#include <iostream>
#include <vector>

using std::string;
using std::cin;
using std::cout;

int main() {
  int n;
  cin >> n;

  std::vector<int> nums;
  nums.reserve(n);
  int num;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    nums.push_back(num);
  }

  int longest_len = 0;
  int current_len = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      if (nums[i] == 1) {
        current_len = 1;
        longest_len = 1;
      }
      continue;
    } // i > 0
    if (nums[i] == 1) {
      ++current_len;
      if (current_len > longest_len) {
        longest_len = current_len;
      }
      continue;
    }
    // nums[i] == 0
    if (nums[i-1] == 1) {
      current_len = 0;
      continue;
    }
  }
  if (current_len > longest_len) {
    longest_len = current_len;
  }

  cout << longest_len;

  return 0;
}