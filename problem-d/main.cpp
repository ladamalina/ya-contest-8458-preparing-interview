#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Node {
  std::string prefix;
  int braces_opened;
  int braces_closed;
};

std::vector<Node> getNextNodes(const Node& root, int n) {
  std::vector<Node> next_permutations;
  if (root.prefix.size() == n * 2) {
    return {};
  }
  if (root.braces_opened == root.braces_closed) {
    next_permutations.push_back({root.prefix + "(",
                                 root.braces_opened + 1,
                                 root.braces_closed});
    return next_permutations;
  }
  // braces_opened > braces_closed
  if (root.braces_opened < n) {
    next_permutations.push_back({root.prefix + "(",
                                 root.braces_opened + 1,
                                 root.braces_closed});
  }
  next_permutations.push_back({root.prefix + ")",
                               root.braces_opened,
                               root.braces_closed + 1});
  return next_permutations;
}

std::vector<std::string> generatePermutations(int n) {
  std::vector<std::string> permutations;
  Node init_node{"", 0, 0};
  std::queue<Node> nodes_queue;
  nodes_queue.push(init_node);
  while(!nodes_queue.empty()) {
    auto root = nodes_queue.front();
    nodes_queue.pop();
    auto next_nodes = getNextNodes(root, n);
    if (next_nodes.empty()) {
      permutations.push_back(root.prefix);
    } else {
      for (const auto& next_node : next_nodes) {
        nodes_queue.push(next_node);
      }
    }
  }
  std::sort(permutations.begin(), permutations.end());

  return permutations;
}

int main() {
  int n;
  std::cin >> n;

  if (n == 0) {
    return 0;
  }
  std::vector<std::string> permutations = generatePermutations(n);
  for (int i = 0; i < permutations.size(); ++i) {
    std::cout << permutations[i] << "\n";
  }

  return 0;
}