
lis = [int(x) for x in input().split()]
N=lis[0]
m=lis[1]
hash_array=[]
for i in range(N):
    hash_array.append([])
lis.pop(0)
lis.pop(1)
modulo=[i*m for i in lis]
for i in lis:
    ind=int(modulo[i])
    (hash_array[ind]).append(lis[i])
    
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key

    