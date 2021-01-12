f=open('blacklist.txt','a')
print('Enter the names of the processes that needs to be blacklisted (Enter to give and input \'q\' to quit')
while(True):
	n=input()
	if(n=='q'):
		f.close()
		break
	f.write(n+'\n')
print('Your Processes are being blacklisted and are not be able to open')

