def count_ways_to_climb_stairs(height, max_steps):
    dp = [0] * (height + 1)
    dp[0] = 1  # There's one way to climb a staircase of height 0 (no steps).

    for i in range(1, height + 1):
        for j in range(1, max_steps + 1):
            if i - j >= 0:
                dp[i] += dp[i - j]

    return dp[height]

height = int(input())
max_steps = int(input())
ways = count_ways_to_climb_stairs(height, max_steps)
print(ways)
