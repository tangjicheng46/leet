#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(const std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& current,
               std::vector<std::vector<int>>& result) {
  if (current.size() == nums.size()) {
    result.push_back(current);
    return;
  }

  for (int i = 0; i < nums.size(); ++i) {
    // 如果该元素已经被使用，或者是重复元素且前一个相同元素未被使用，跳过
    if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
      continue;
    }

    current.push_back(nums[i]);
    used[i] = true;

    backtrack(nums, used, current, result);

    current.pop_back();
    used[i] = false;
  }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> current;
  std::vector<bool> used(nums.size(), false);

  // 首先对输入数组进行排序，以便在回溯过程中处理重复元素
  std::sort(nums.begin(), nums.end());

  backtrack(nums, used, current, result);

  return result;
}

int main() {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> result = permuteUnique(nums);

  // 打印结果
  for (const auto& subset : result) {
    for (int num : subset) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
