#stupid part: can't pick only part of a bush

tc = int(raw_input())
for test in range(tc):
	[n, k] = [int(x) for x in raw_input().split()]
	bushes = [int(x) for x in raw_input().split()]
	dp = [[[0, 0] for x in range(n+1)] for y in range(k+1)] #dp[weight][bush][not take/take]
	for weight in range(1,k+1):
		for bush in range(1,n+1):
			dp[weight][bush][0] = max(dp[weight][bush-1][0], dp[weight][bush-1][1])
			if bushes[bush-1] > weight:
				dp[weight][bush][1] = dp[weight][bush][0]
			else:
				dp[weight][bush][1] = dp[weight - bushes[bush-1]][bush-1][0]+bushes[bush-1]
	print ("Scenario #" + str(test + 1) + ":"), max(dp[-1][-1][0], dp[-1][-1][1])