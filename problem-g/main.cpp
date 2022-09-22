#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

struct City {
  int x = 0;
  int y = 0;
};

size_t operator-(const City& lhs, const City& rhs) {
  return std::abs(lhs.x - rhs.x) + std::abs(lhs.y - rhs.y);
}

bool is_road_available(const City& source, const City& target, size_t max_fuel) {
  return max_fuel >= target - source;
}

int getShortestPath(const std::vector<City>& cities, int source_id, int target_id, size_t max_fuel) {
  if (source_id == target_id) {
    return 0;
  }
  std::vector<std::vector<int>> roads(cities.size());
  for (int i = 0; i < cities.size(); ++i) {
    roads[i].reserve(cities.size());
    for (int j = 0; j < cities.size(); ++j) {
      if (i != j && is_road_available(cities[i], cities[j], max_fuel)) {
        roads[i].push_back(j);
      }
    }
  }

  std::vector<bool> visited_ids(cities.size(), false);
  visited_ids[source_id] = true;
  std::vector<int> roads_num_to_reach(cities.size(), 0);

  std::queue<int> city_ids_queue;
  city_ids_queue.push(source_id);
  while (!city_ids_queue.empty()) {
    auto current_city_id = city_ids_queue.front();
    city_ids_queue.pop();

    for (const int next_city_id : roads[current_city_id]) {
      if (visited_ids[next_city_id]) {
        continue;
      }
      if (next_city_id == target_id) {
        return roads_num_to_reach[current_city_id] + 1;
      }
      visited_ids[next_city_id] = true;
      city_ids_queue.push(next_city_id);
      roads_num_to_reach[next_city_id] = roads_num_to_reach[current_city_id] + 1;
    }
  }

  return -1;
}

void TestGetShortestPath() {
  {
    std::vector<City> cities{{0,0},{0,2},{2,2},{0,-2}, {2,-2},{2,-1},{2,1}};
    size_t max_fuel = 2;
    int source_city_id = 0;
    int target_city_id = 2;
    int min_roads_path = getShortestPath(cities, source_city_id, target_city_id, max_fuel);
    assert(min_roads_path == 2);
  }
  {
    std::vector<City> cities{{0,0},{1,0},{0,1},{1,1}};
    size_t max_fuel = 2;
    int source_city_id = 0;
    int target_city_id = 3;
    int min_roads_path = getShortestPath(cities, source_city_id, target_city_id, max_fuel);
    assert(min_roads_path == 1);
  }
  {
    std::vector<City> cities{{0,0},{2,0},{0,2},{2,2}};
    size_t max_fuel = 1;
    int source_city_id = 0;
    int target_city_id = 3;
    int min_roads_path = getShortestPath(cities, source_city_id, target_city_id, max_fuel);
    assert(min_roads_path == -1);
  }
  {
    std::vector<City> cities{{0,0},{0,2},{3,3},{3,2},{3,1}};
    size_t max_fuel = 5;
    int source_city_id = 0;
    int target_city_id = 2;
    int min_roads_path = getShortestPath(cities, source_city_id, target_city_id, max_fuel);
    assert(min_roads_path == 2);
  }
  std::cerr << "TestGetShortestPath OK" << std::endl;
}

int main() {
  // TestGetShortestPath();

  int n_cities;
  std::cin >> n_cities;

  std::vector<City> cities;
  cities.reserve(n_cities);
  for (int i = 0; i < n_cities; ++i) {
    int x, y;
    std::cin >> x >> y;
    cities.push_back({x, y});
  }

  size_t max_fuel;
  std::cin >> max_fuel;

  int source_city_id, target_city_id;
  std::cin >> source_city_id >> target_city_id;
  --source_city_id;
  --target_city_id;

  int min_roads_path = getShortestPath(cities, source_city_id, target_city_id, max_fuel);
  std::cout << min_roads_path;

  return 0;
}
