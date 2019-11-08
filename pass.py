
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
	
import random
 
correctPassword = "1234"
wrongPasswords = []
password = ""
length = 4
chars = "12e4567890"
run = True
 
while run:
    password = ""
    
    for i in range(length):
        password += random.choice(chars)
 
    if password not in wrongPasswords:
        if password != correctPassword:
            print(password)
            wrongPasswords.append(password)
        else:
            run = False
            break
 
print(password + " is correct")
