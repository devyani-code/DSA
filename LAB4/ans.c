max_size=int(input())
class Queues():
    def __init__(self):
        self.max_size=max_size
        self.inp=[]
        self.l=[0 for i in range(self.max_size)]
        self.l1=[]
        self.items=0
        self.front=-1
        self.rear=0
    def call(self):
        if self.inp[0]==1:
            self.enqueue()
        if self.inp[0]==2:
            self.items=self.max_size-self.l.count(0)
            if self.inp[1]>self.items:
                print("underflow")
            else:
                self.dequeue()
        if self.inp[0]==3:
            self.peek_rear()
    def input_funct(self):
        inp=list(map(int, input().split()))
        if inp[0]!=-1:
            self.inp=inp
            self.call()
            self.input_funct()
        else:
            exit
    def enqueue(self):
        if self.l.count(0)==0:
            print("overflow")
        else:
            for i in range(2,len(self.inp)):
                if self.front!=-1:
                    self.rear=(self.rear+1)%self.max_size
                    self.l[self.rear]=self.inp[i]
                if self.front==-1:
                    self.front=0
                    self.rear=0
                    self.l[0]=self.inp[2]
            for i in self.l:
                print(i,end=' ')
            print(end='\n')
    def dequeue(self):
        if self.max_size-self.l.count(0)<self.inp[1]:
            print('underflow')
        elif(self.max_size-self.l.count(0)>self.inp[1]):
            for i in range(self.inp[1]):
                self.l[self.front]=0
                self.front=(self.front+1)%self.max_size
            for i in self.l:
                print(i,end=' ')
            print(end='\n')
        else:
            for i in range(self.inp[1]):
                self.l[self.front]=0
                self.front=(self.front+1)%self.max_size
            for i in self.l:
                print(i,end=' ')
            print(end='\n')
            self.front-=1
            self.rear-=1
            
    def peek_rear(self):
        print(self.l[self.front],self.front)
        print(self.l[self.rear],self.rear)
        if self.rear<self.front:
            print(self.max_size-(self.front-self.rear)+1)
        else:
            print(self.rear-self.front+1)
        for i in self.l:
            print(i,end=' ')
        print(end='\n')
                
        
x=Queues()
x.input_funct()