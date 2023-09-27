def printPost(inn, pre, inStrt, inEnd):
    global preIndex, hm
    if (inStrt > inEnd):
        return
    inIndex = hm[pre[preIndex]]
    preIndex += 1
    printPost(inn, pre, inStrt, inIndex - 1)
    printPost(inn, pre, inIndex + 1, inEnd)
    print(inn[inIndex], end = " ")
 
def printPostMain(inn, pre, n):
    for i in range(n):
        hm[inn[i]] = i
    printPost(inn, pre, 0, n - 1)
    
hm = {}
preIndex = 0
n = int(input())
pre = list(map(int, input().split()))
inn = list(map(int, input().split()))
printPostMain(inn, pre, n)
