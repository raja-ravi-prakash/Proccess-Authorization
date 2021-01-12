import psutil
#print('Module imported')
f=open('blacklist.txt','r')
#print('Blacklist imported')
l=list()
for i in f:
	l.append(i.strip('\n'))
#print(l)
while(True):
	for proc in psutil.process_iter():
		try:
			if(proc.name() in l):
				#print('Process Encountered and Terminating')
				proc.kill()
		except(psutil.NoSuchProcess,psutil.AccessDenied,psutil.ZombieProcess):
			#print('Passing')
			pass
