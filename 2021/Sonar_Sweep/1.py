def Sonar_Sweep(file):
    fopen = open(file,'r')
    count = 0
    previous_item = None
    for line in fopen:
        line = int(line)

        if previous_item != None and line > previous_item:
            count += 1

        previous_item = line
    return count