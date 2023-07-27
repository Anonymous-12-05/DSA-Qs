def sum_rows_equal (lst, candidate):
    sumprev = 0
    sumnext = 0
    for i in range (0, candidate):
        sumprev += sum (lst[i])
    for i in range (candidate+1, len(lst)):
        sumnext += sum(lst[i])
    return sumprev == sumnext

def sum_cols_equal (lst, candidate):
    sumprev = 0
    sumnext = 0
    for i in range (0, candidate):
        sumprev += sum ([row[i] for row in lst])
    for i in range (candidate+1, len(lst[0])):
        sumnext += sum ([row[i] for row in lst])
    return sumprev == sumnext
    
def solution (A):
    N = len (A)
    M = len (A[0])
    count = 0
    for i in range (1, N-1):
        for j in range (1, M-1):
            if sum_rows_equal (A, i) and sum_cols_equal (A, j):
                #print (i, j)
                count += 1 
    return count
    
lst = [[2, 7, 5], [3, 1, 1], [2, 1, -7], [0, 2, 1], [1, 6, 8]]

print (solution(lst))
