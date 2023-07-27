def max_symmetric_substring_length(S):
    n = len(S)
    max_len = 0
    for i in range(n):
        for j in range(i+1, n+1):
            substring = S[i:j]
            if len(substring) % 2 == 0:
                left_half = substring[:len(substring)//2]
                right_half = substring[len(substring)//2:]
                if '?' in left_half:
                    left_half = left_half.replace('?', '<')
                if '?' in right_half:
                    right_half = right_half.replace('?', '>')
                if left_half.count('<') == len(left_half) and right_half.count('>') == len(right_half):
                    max_len = max(max_len, len(substring))
    return max_len

s="<<?"
print(max_symmetric_substring_length(s))