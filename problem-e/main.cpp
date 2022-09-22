#include <algorithm>
#include <iostream>
#include <string>


int main() {
  std::string str1, str2;
  std::cin >> str1 >> str2;

  if (str1.empty() && str2.empty()) {
    std::cout << 1;
    return 0;
  }

  if (str1.size() != str2.size()) {
    std::cout << 0;
    return 0;
  }

  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());

  std::cout << (str1 == str2 ? 1 : 0);
  return 0;
}