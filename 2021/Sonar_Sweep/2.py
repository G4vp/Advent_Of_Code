def Sonar_Sweep(file):
    fopen = open(file,'r')
    count = 0

    previous_sum = None
    present_sum = list()

    for line in fopen:
        line = int(line)

        if len(present_sum) < 3:
            present_sum.append(line)
        else:
            if previous_sum == None or sum(present_sum) > previous_sum:
                count += 1
            print(present_sum)
            
            previous_sum = sum(present_sum)
            present_sum.pop(0)
            present_sum.append(line)

    return count

print(Sonar_Sweep(r'AdventOfCode\2021\Sonar_Sweep\input.txt'))