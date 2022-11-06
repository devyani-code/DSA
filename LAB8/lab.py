
class Sorting():
    def __init__(self,arr):
        self.inp_array=arr

    def insertion_sort(self,start,end):
        for j in range(start+1,end+1):
            curr=self.inp_array[j]
            i=j
            while(i>start and curr<self.inp_array[i-1]):
                self.inp_array[i]=self.inp_array[i-1]
                i=i-1
            self.inp_array[i]=curr
    
    def partition_function(self,start,end):
        pivot=end
        pin=start
        for i in range(start,end):
            if(self.inp_array[i]<self.inp_array[pivot]):
                self.inp_array[i],self.inp_array[pin]=self.inp_array[pin],self.inp_array[i]
                pin=pin+1
        self.inp_array[pin],self.inp_array[end]=self.inp_array[end],self.inp_array[pin]
        return pin

    def quick_sort(self,start,end):
        if start<end:
            pivot_posn=self.partition_function(self.inp_array,start,end)
            self.quick_sort(self,start,pivot_posn-1)
            self.quick_sort(self,pivot_posn+1,end)

    def quick_insert_sort(self,start,end,threshold):
        while start<end:

            if end-start+1<threshold:
                self.insertion_sort(start,end)
                break
            
            else:
                pivot_posn= self.partition_function(start,end)
                if pivot_posn-start<end-pivot_posn:
                    self.quick_insert_sort(start, pivot_posn-1,threshold)
                    start = pivot_posn + 1
                else:
                    self.quick_insert_sort(pivot_posn+1,end,threshold)
                    end=pivot_posn-1
        print(*self.inp_array)
input_lis=[int(x) for x in input().split()]
length=input_lis[0]
thresh=input_lis[1]
output=Sorting(input_lis[2:])
output.quick_insert_sort(0,length-1,thresh)



        
