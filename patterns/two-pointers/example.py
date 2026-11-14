def pair_sum_target(nums, target):
    left, right = 0, len(nums) - 1
    while left < right:
        current = nums[left] + nums[right]
        if current == target:
            return (left, right)
        if current < target:
            left += 1
        else:
            right -= 1
    return None

if __name__ == "__main__":
    nums = [1, 3, 4, 7, 10, 12]
    print(pair_sum_target(nums, 11))
