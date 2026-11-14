def range_sum(nums, left, right):
    prefix = [0]
    for value in nums:
        prefix.append(prefix[-1] + value)
    return prefix[right + 1] - prefix[left]

if __name__ == "__main__":
    print(range_sum([1, 2, 3, 4, 5], 1, 3))
