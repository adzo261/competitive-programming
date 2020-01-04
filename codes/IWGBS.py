
from sys import stdin,stdout

n=int(stdin.readline())
a=[0 for x in range(n+1)]
b=[0 for x in range(n+1)]
a[0]=b[0]=1
for i in range(1,n+1):
	#stdout.write(str(i)+"\n")
	b[i]+=a[i-1]
	b[i]+=b[i-1]
	a[i]+=b[i-1]


stdout.write(str(a[n-1]+b[n-1]))