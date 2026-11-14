def find_missing_number(nums):
    i = 0
    while i < len(nums):
        correct = nums[i]
        if nums[i] < len(nums) and nums[i] != nums[correct]:
            nums[i], nums[correct] = nums[correct], nums[i]
        else:
            i += 1
    for i, value in enumerate(nums):
        if value != i:
            return i
    return len(nums)

if __name__ == "__main__":
    print(find_missing_number([0, 1, 3, 4]))
