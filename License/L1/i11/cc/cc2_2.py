a=int(input())
b=int(input())
c=int(input())
if  a>b  and  a>c:
   if  b>c :
      print(c)
   else:
      print(b)
elif  a<=b :
   if  a>c :
      print(c)
   else:
      print(a)
else:
    print(b) 