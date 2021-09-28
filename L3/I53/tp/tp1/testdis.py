import dis
import time

#############################################
#Ex1
def elem(ch):
	return dis.dis(ch)

#############################################
#Ex2

def ex2():
	a=5
	b=3
	c=4
	if a>b:
		print("hmmm")
	elif b>c:
		print("hmmm")
		print("hmmm")
	else:
		print("test")
#############################################
#Ex3

def Comp_loop():
	k=1
	n=1000000000
	clk=time.CLOCK_MONOTONIC
	a=time.clock_gettime(clk)
	for i in range(n):
		k=0
	b=time.clock_gettime(clk)
	print("for = ",a-b)
	i=0
	a=time.clock_gettime(clk)
	while i<n:
		k=0
		i+=1
	b=time.clock_gettime(clk)
	print("while = ",a-b)

#############################################
#Ex4
def List_nul(n):
	i1=time.time
	l=[]
	for i in range(n):
		l=l+[i]
	i2=time.time
	print(i1-12)

def List_more(n):
	i1=time.time
	l=[]
	for i in range(n):
		l+=[i]
	i2=time.time

def List_append(n):
	i1=time.time
	l=[]
	for i in range(n):
		l.append(i)
	i2=time.time

def List_appendmore(n):
	i1=time.time
	l=[i for i in range(n)]
	i2=time.time

#############################################
#while(True):
	#ch=input("dis of")
	#print(elem(ch))
	
#print(dis.dis(ex2))
#Comp_loop()
#dis.dis(List_nul)
#print("###########################")
#dis.dis(List_more)
#print("###########################")
#dis.dis(List_append)
#print("###########################")
#dis.dis(List_appendmore)
