#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(std::vector<std::vector<int>>& result, int start, std::vector<int>& current,
               const std::vector<int>& nums) {
  result.push_back(current);
  for (int i = start; i < nums.size(); i++) {
    if (i > start && nums[i] == nums[i - 1]) {
      continue;
    }
    current.push_back(nums[i]);
    backtrack(result, i + 1, current, nums);
    current.pop_back();
  }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::sort(nums.begin(), nums.end());
  std::vector<int> start_vec;
  backtrack(result, 0, start_vec, nums);
  return result;
}

int main() {
  std::vector<int> nums = {1, 2, 2, 3};
  std::vector<std::vector<int>> result = subsetsWithDup(nums);

  // 打印结果
  for (const auto& subset : result) {
    for (int num : subset) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
