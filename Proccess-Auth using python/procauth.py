import psutil
f=open('blacklist.txt','r')
while(True):
	for proc in psutil.process_iter():
		try:
			if(proc.name() in f):
				proc.kill()
		except(psutil.NoSuchProcess,psutil.AccessDenied,psutil.ZombieProcess):
			pass
