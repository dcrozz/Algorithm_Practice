#解法1 使用mergeSort 复杂度o（nlogn）
from collections import deque

global COUNT
COUNT=0
def MergeSort(lst):
	if len(lst)<=1: return lst
	global COUNT
	def Merge(left,right):
		global COUNT
		merged,left,right = deque(),deque(left),deque(right)
		while left and right:
			if left[0]<=right[0]:
				merged.append(left.popleft())
			else:
				merged.append(right.popleft())
				COUNT += len(left)

		merged.extend(right if right else left)
		return list(merged)

	mid = len(lst)//2
	left = MergeSort(lst[:mid])
	right = MergeSort(lst[mid:])
	return Merge(left,right)

