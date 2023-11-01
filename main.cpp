#include <iostream>
#include <vector>

void backtrack(int start, const std::vector<int>& nums, std::vector<std::vector<int>>& result,
               std::vector<int>& current) {
  if (start >= nums.size()) {
    result.push_back(current);
    return;
  }

  std::vector<int> current0(current);
  std::vector<int> current1(current);
  current1.push_back(nums[start]);
  backtrack(start + 1, nums, result, current0);
  backtrack(start + 1, nums, result, current1);
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> start_vec;
  backtrack(0, nums, result, start_vec);
  return result;
}

int main() {
  std::cout << "Hello\n";

  return 0;
}
