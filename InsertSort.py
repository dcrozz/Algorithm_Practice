def InsertSort(lst):
	for i in range(1,len(lst)):
		j = i - 1
		while lst[i] <= lst[j] and j>=0:
			j -= 1
		if j>=0:
			lst[:i+1] = lst[:j+1] + [lst[i]] + lst[j+1:i]
		else:
			lst[:i+1] = [lst[i]] + lst[:i]
	return lst
				
