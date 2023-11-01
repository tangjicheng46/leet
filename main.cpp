#include <iostream>
#include <vector>

// void backtrack(int start, const std::vector<int>& nums, std::vector<std::vector<int>>& result,
//                std::vector<int>& current) {
//   if (start >= nums.size()) {
//     result.push_back(current);
//     return;
//   }

//   std::vector<int> current0(current);
//   std::vector<int> current1(current);
//   current1.push_back(nums[start]);
//   backtrack(start + 1, nums, result, current0);
//   backtrack(start + 1, nums, result, current1);
// }

// std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
//   std::vector<std::vector<int>> result;
//   std::vector<int> start_vec;
//   backtrack(0, nums, result, start_vec);
//   return result;
// }

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> subset;
    generateSubsets(nums, 0, subset, result);
    return result;
}

void generateSubsets(const std::vector<int>& nums, int index, std::vector<int>& subset, std::vector<std::vector<int>>& result) {
    result.push_back(subset); // 将当前子集添加到结果中

    for (int i = index; i < nums.size(); ++i) {
        subset.push_back(nums[i]); // 将当前元素添加到子集中
        generateSubsets(nums, i + 1, subset, result); // 递归生成子集
        subset.pop_back(); // 回溯，移除最后一个元素
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = subsets(nums);

    // 打印结果
    for (const auto& subset : result) {
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
