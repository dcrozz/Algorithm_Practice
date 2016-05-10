def quickSort(lst):
	i = 0
	j = len(lst) -1 
	base = lst[i]
	while(i<j):
		while(lst[j] >= base and i<j):
			j -= 1
		if i<j:
			lst[j],lst[i] = lst[i],lst[j]
		while(lst[i] <= base and i<j):
			i += 1 
		if i<j:
			lst[i],lst[j] = lst[j],lst[i]
	if j>0 :lst[:j+1] = quickSort(lst[:j+1])
	if i<len(lst)-1: lst[i+1:] = quickSort(lst[i+1:])
	return lst
