#include <iostream>
#include <vector>

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> subset;
  std::sort(nums.begin(), nums.end());  // 先对数组排序以处理重复元素
  generateSubsets(nums, 0, subset, result);
  return result;
}

void generateSubsets(const std::vector<int>& nums, int index, std::vector<int>& subset,
                     std::vector<std::vector<int>>& result) {
  result.push_back(subset);  // 将当前子集添加到结果中

  for (int i = index; i < nums.size(); ++i) {
    // 处理重复元素，跳过重复元素
    if (i > index && nums[i] == nums[i - 1]) {
      continue;
    }

    subset.push_back(nums[i]);                     // 将当前元素添加到子集中
    generateSubsets(nums, i + 1, subset, result);  // 递归生成子集
    subset.pop_back();                             // 回溯，移除最后一个元素
  }
}

int main() {
  std::vector<int> nums = {1, 2, 2};
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
