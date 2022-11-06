heap_array = []

def input_function(n):

    if(n  == 1):
        length = int(input())

        
        
        for i in some_array:

            heap_array.append(i)

        build_min_heap_tree(heap_array)
        
    if(n==2):

        n=int(input())

        insert_node(n)
    
    if(n==3):

        delete_node(heap_array[0])

    if(n==4):

        n=int(input())

        delete_node(n)
    
    if(n == 5):

        sorted_array()

def heapify(arr,index,length):

    n=length

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
        
        heapify(arr,minimum,len(arr))
    
def build_min_heap_tree(arr):
 
    length = len(arr)
 
    index=length//2 -1
 
    for i in range(index,-1,-1):

        heapify(arr,i,len(arr))

    print(heap_array)
                
def insert_node(n):

    if len(heap_array)==0:

        print("Heap does not exist")

        return

    heap_array.append(n)
    
    build_min_heap_tree(heap_array)

def delete_node(n):

    if len(heap_array)!=0:
        
        if n not in heap_array:

            print("Integer not found")

            return
        else:
            
            for i in range(len(heap_array)):
    
                if heap_array[i]==n:
    
                    heap_array[i],heap_array[len(heap_array)-1]=heap_array[len(heap_array)-1],heap_array[i]
    
                    heap_array.pop()
                    
                    break

        build_min_heap_tree(heap_array)

    else:
        
        print("Heap does not exist")

def sorted_array():

    size=len(heap_array)

    while(size>1):

        heap_array[0], heap_array[size-1] = heap_array[size-1], heap_array[0]

        size = size-1
 
        index = size//2 -1
 
        for i in range(index,-1,-1):

            heapify(heap_array,i,size)

    print(heap_array)




if __name__=="__main__":
    
    while(True):
    
        num = int(input())
        
        input_function(num)
        
        if num == -1:
            
            quit()
