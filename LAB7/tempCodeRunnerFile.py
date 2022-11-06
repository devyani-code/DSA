heap_array = []

def input_function(n):

    if(n  == 1):
        length = int(input())


        some_array=list(map(int,input().split()))
        for i in some_array:
            heap_array.append(i)
        build_min_heap_tree(heap_array)
        
    if(n==2):

        n=int(input())

        insert_node(n)

    if(n==3):

        n=int(input())

        delete_node(n)
    

def heapify(arr,index):

    n=len(arr)

    minimum=index

    left_child = 2*index+1

    right_child = 2*index+2

    if(n > left_child and arr[minimum] > arr[left_child]):

          minimum = left_child

    if(n > right_child and arr[minimum] > arr[right_child]):

        minimum = right_child

    if minimum != index:

        temp = arr[minimum]

        arr[minimum] = arr[index]

        arr[index] = temp
        heapify(arr,minimum)
    
def build_min_heap_tree(arr):
 
    length = len(arr)
 
    index=length//2 -1
 
    for i in range(index,-1,-1):

        heapify(arr,i)

    print(heap_array)
                
def insert_node(n):

    if len(heap_array)==0:

        print("Heap does not exist")

        return

    heap_array.append(n)
    
    build_min_heap_tree(heap_array)

def delete_node(n):
    if len(heap_array!=0):
        
        for i in range(len(heap_array)):
            if heap_array[i]==n:
                heap_array[i],heap_array[len(heap_array)-1]=heap_array[len(heap_array)-1],heap_array[i]
                heap_array.pop()

        if n not in heap_array:
            print("Integer not found")
            return
        build_min_heap_tree(heap_array)
    else:
        print("Heap does not exist")

if __name__=="__main__":

    num = int(input())

    while(num != -1 ):

        input_function(num)
