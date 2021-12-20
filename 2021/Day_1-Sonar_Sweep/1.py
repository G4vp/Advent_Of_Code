def Part_A(file):
    fopen = open(file,'r')
    fhand = fopen.readlines()
    count = 0
    
    for i in range(len(fhand)-1):
        if int(fhand[i]) < int(fhand[i+1]):
            count += 1
    return count
    

def Part_B(file):
    fopen = open(file,'r')
    fhand = fopen.readlines()
    count = 0
    
    for i in range(0,len(fhand)):
        previ_item = int(fhand[i-1]) + int(fhand[i-2])+ int(fhand[i-3])
        next_item = int(fhand[i-1]) + int(fhand[i-2]) + int(fhand[i])
        if next_item > previ_item: count += 1
    
    return count
