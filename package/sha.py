from hashlib import sha256
from sys import argv

hashCommand = sha256(argv[1].encode()).hexdigest()
print(hashCommand)
