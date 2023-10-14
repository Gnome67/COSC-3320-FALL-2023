def isSafe(temp, i, start):
    # If "i" column contains a chess piece (#)
    for j in range(start):
        if temp[j] == i:
            return False
    return True

def req_function(arr, temp, n, k, start, count):
    # If you have already placed k pieces, return 1
    if count == k:
        return 1
    # If start is n, then there is no row to place pieces
    if start == n:
        return 0

    totalWays = 0

    # Start placing in "start" row
    for i in range(n):
        # If # exists and position is safe
        if arr[start][i] == '#' and isSafe(temp, i, start):
            temp[start] = i
            # Call recursively to place pieces in the further rows
            totalWays += req_function(arr, temp, n, k, start + 1, count + 1)
            # Backtrack and remove i from position[start]
            temp[start] = -1

    # We are not placing any piece in the "start" row
    totalWays += req_function(arr, temp, n, k, start + 1, count)

    return totalWays

def main():
    n, k = map(int, input().split())
    arr = [input() for _ in range(n)]
    temp = [-1] * n

    solution = req_function(arr, temp, n, k, 0, 0)
    print(solution)

if __name__ == "__main__":
    main()

