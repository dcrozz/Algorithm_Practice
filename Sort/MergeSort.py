from collections import deque
def MergeSort(lst):
	if len(lst)<=1: return lst

	def Merge(left,right):
		merged,left,right = deque(),deque(left),deque(right)
		while left and right:
			merged.append(left.popleft() if left[0]<=right[0] else right.popleft())
		merged.extend(right if right else left)
		return list(merged)

	mid = len(lst)//2
	left = MergeSort(lst[:mid])
	right = MergeSort(lst[mid:])
	return Merge(left,right)

