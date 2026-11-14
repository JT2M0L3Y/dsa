def first_true(nums):
    left, right = 0, len(nums) - 1
    ans = -1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid]:
            ans = mid
            right = mid - 1
        else:
            left = mid + 1
    return ans

if __name__ == "__main__":
    nums = [False, False, True, True, True]
    print(first_true(nums))
