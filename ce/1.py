from sys import argv

f = open(argv[1],'r')

def process(i):
	return 'FB' if (i%C==0) else 'F' if (i%A==0) else 'B' if (i%B==0) else str(i)

for line in f.readlines():
	if line.strip() == '': continue
	A, B, N = map(int,line.split())
	C = A * B
	print(' '.join(process(i) for i in range(1,N+1)))

f.close()



