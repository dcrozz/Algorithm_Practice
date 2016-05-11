def quickSelect(k,lst):
	if len(lst) == 1: return lst[0]
	if k > len(lst) or k < 0: return -1
	i = 0
	j = len(lst)-1
	base = lst[i]
	while(i<j):
		while(lst[j] >= base and j>i):
			j-=1
		lst[i],lst[j] = lst[j],lst[i]
		while(lst[i] <= base and j>i):
			i+=1
		lst[i],lst[j] = lst[j],lst[i]
	if k>i+1:
		return quickSelect(k-i-1,lst[i+1:])
	else:
		return quickSelect(k,lst[:j+1])
