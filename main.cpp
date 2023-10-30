#include <iostream>
#include <vector>

void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
  if (start == nums.size()) {
    result.push_back(nums);
    return;
  }

  for (int i = start; i < nums.size(); ++i) {
    std::swap(nums[start], nums[i]);
    backtrack(nums, start + 1, result);
    std::swap(nums[start], nums[i]);
  }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  backtrack(nums, 0, result);
  return result;
}

int main() {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> permutations = permute(nums);

  for (const auto& permutation : permutations) {
    for (int num : permutation) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
