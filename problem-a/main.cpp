#include <algorithm>
#include <iostream>
#include <set>

using std::string;
using std::cin;
using std::cout;

int main() {
  string j, s;
  cin >> j >> s;

  std::set<char> j_set(j.begin(), j.end());

  int result = 0;
  for (const char ch : s) {
    result += j_set.count(ch) == 0 ? 0 : 1;
  }

  cout << result;

  return 0;
}