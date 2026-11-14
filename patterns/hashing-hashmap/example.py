def count_frequencies(words):
    freq = {}
    for word in words:
        freq[word] = freq.get(word, 0) + 1
    return freq

if __name__ == "__main__":
    print(count_frequencies(["apple", "banana", "apple", "cherry"]))
