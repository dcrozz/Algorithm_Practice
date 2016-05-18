def SelectSort(lst):
	i = 0
	while (i<len(lst)-1):
		#range(a,b) from a to b-1
		for j in range(i+1,len(lst)):
			if lst[j]<= lst[i+1]:
				lst[i+1],lst[j] = lst[j],lst[i+1]
		i += 1
	return lst

def ShellSort(lst):
	i = 0
	leap = len(lst)//3

