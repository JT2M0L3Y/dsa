def activity_selection(intervals):
    intervals = sorted(intervals, key=lambda x: x[1])
    chosen = []
    last_end = -1
    for start, end in intervals:
        if start >= last_end:
            chosen.append((start, end))
            last_end = end
    return chosen

if __name__ == "__main__":
    print(activity_selection([(1, 3), (2, 4), (3, 5), (5, 7)]))
