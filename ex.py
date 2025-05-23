def max_subsequences(s):
    d = s.count('-')
    u = s.count('_')
    if d < 2 or u < 1:
        return 0
    return u * (d * (d - 1)) // 2

# Example usage:
s =input()
print(max_subsequences(s))  # Output: 27