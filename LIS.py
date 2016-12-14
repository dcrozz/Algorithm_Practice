"""
This file is created on 12 Dec 2016. Learning Longest Increasing Sequence
Q:  
1. Strictly Increasing
2. Can be not connected
"""
def solution1(A):
    """this solution consumes time complexity o(n^2) by using DP"""
    length = len(A)
    #L
    L = [1] * length
    for i in range(length):
        for j in range(i):
            if A[j] <= A[i]:
                #A[:i]的LIS为max（之前小于A[i]的LIS+1 , L[i] （默认为1））
                L[i] = max(L[j]+1,L[i])
    return max(L)

"""
Using binary search
"""
def solution2(A):
    """this solution consumes time complexity o(nlog(n))"""
    l = len(A)
    L = []
    L.append(A[0])
    for i in range(1,l):
        if A[i] < L[0]:
            L[0] = A[i]
        elif A[i] > L[-1]:
            L.append(A[i])
        else:
            lo,hi = 0,len(L)
            mid = (lo+hi)/2
            while lo != hi:
                if A[i] > L[mid]: lo = mid+1
                else: hi = mid
                mid = (lo+hi)/2
            L[mid] = A[i]
    return len(L)

