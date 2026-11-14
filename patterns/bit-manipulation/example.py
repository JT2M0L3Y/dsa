def single_number(nums):
    result = 0
    for x in nums:
        result ^= x
    return result

if __name__ == "__main__":
    print(single_number([2, 2, 3, 3, 5]))
