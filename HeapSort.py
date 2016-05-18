def heapSort(lst):
	def buildMinHeap(lst):
	#min heap
		for i in range(len(lst)//2-1,-1,-1):
			root = i
			child = root*2 +1
			while True:
				if child > len(lst)-1: break
				elif child < len(lst)-1 and lst[child]>=lst[child+1]:
					child += 1
				elif lst[child]<lst[root]:
					lst[root],lst[child]=lst[child],lst[root]
					root = child
					child = root*2 +1

				else:
					break
		return lst
	lst = buildMinHeap(lst)
	tmp =[]
	while lst:
		tmp.append(lst[0])
		if len(lst) == 1:
			return tmp
		lst[0] = lst.pop()
		lst = buildMinHeap(lst)
