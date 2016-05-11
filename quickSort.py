#original method
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
	if j>0 :lst[:j] = quickSort(lst[:j])
	if i<len(lst)-1: lst[i+1:] = quickSort(lst[i+1:])
	return lst
#method told by Mr.Wang
def quickSort1(lst):
	i = 0
	j = len(lst) -1 
	base = lst[i]
	while(i<j):
		while(lst[j] > base and i<j): j-=1
		while(lst[i] < base and i<j): i+=1
		#ensure the i is greater than j
		if i<=j: 
			lst[i],lst[j] = lst[j],lst[i]
			i+=1
			j-=1
	if j>0 :lst[:j+1] = quickSort1(lst[:j+1])
	if i<len(lst)-1: lst[i:] = quickSort1(lst[i:])
	return lst
