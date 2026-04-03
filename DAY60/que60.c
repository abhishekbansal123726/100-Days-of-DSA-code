n = int(input())
arr = list(map(int, input().split()))

flag = True

for i in range(n):
    l = 2*i + 1
    r = 2*i + 2
    
    if l < n and arr[i] > arr[l]:
        flag = False
        break
    if r < n and arr[i] > arr[r]:
        flag = False
        break

print("YES" if flag else "NO")
