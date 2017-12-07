class Tree(object):
    def __init__(self, left, right, data):
        self.left = left
        self.right = right
        self.data = data

pointer = 0
def buildTree(s):
	global pointer
	# print pointer
	tempPointer = pointer
	pointer += 1
	if s[tempPointer] == 2:
		return Tree(buildTree(s), buildTree(s), [])
	elif s[tempPointer] == 1:
		return Tree(buildTree(s), None, [])
	else:
		# print "HELLO", pointer
		return Tree(None, None, [[1, 1], [0, 0], [0,0]]) #g, r, b

def printTree(t):
	if t == None:
		# print None
		None
	else:
		print t.data
		printTree(t.left)
		printTree(t.right)

def solve(t):
	if t.data:
		return t.data
	# if t.left == None:
	# 	return t.data
	elif t.right == None:
		left = solve(t.left)
		t.data.append([max(left[1][0], left[2][0])+1, min(left[1][1], left[2][1])+1])
		t.data.append([max(left[0][0], left[2][0]), min(left[0][1], left[2][1])])
		t.data.append([max(left[0][0], left[1][0]), min(left[0][1], left[1][1])])
		return t.data
	else:
		left = solve(t.left)
		right = solve(t.right)

		t.data.append([max(left[1][0]+right[2][0], left[2][0]+right[1][0])+1, min(left[1][1]+right[2][1], left[2][1]+right[1][1])+1])
		t.data.append([max(left[0][0]+right[2][0], left[2][0]+right[0][0]), min(left[0][1]+right[2][1], left[2][1]+right[0][1])])
		t.data.append([max(left[0][0]+right[1][0], left[1][0]+right[0][0]), min(left[0][1]+right[1][1], left[1][1]+right[0][1])])
		return t.data





tc = int(raw_input())
for test in range(tc):
	inp = [int(x) for x in raw_input()]
	pointer = 0
	root = buildTree(inp)
	# printTree(root)
	big = 0
	little = 1000000
	# print root.data
	out = solve(root)
	for i in out:
		if i[0] > big:
			big = i[0]
		if i[1] < little:
			little = i[1]
	print big, little




