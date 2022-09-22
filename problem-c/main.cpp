#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  if (n == 0) {
    return 0;
  }

  std::vector<int> nums;
  nums.reserve(n);
  int num;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    nums.push_back(num);
  }

  int last_unique_idx = 0;
  for (int i = 1; i < n; ++i) {
    if (nums[i] != nums[i-1]) {
      ++last_unique_idx;
      nums[last_unique_idx] = nums[i];
    }
  }
  nums.resize(last_unique_idx + 1);

  for (int i = 0; i < nums.size(); ++i) {
    std::cout << nums[i];
    if (i + 1 < nums.size()) {
      std::cout << "\n";
    }
  }

  return 0;
}