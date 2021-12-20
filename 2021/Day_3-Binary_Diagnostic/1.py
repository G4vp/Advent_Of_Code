def Part_A(file):

    fhand = open(file,'r').readlines()

    gamma = ''
    epsilon = ''

    for i in range(len(fhand[0].strip())):
        count = 0
        
        for j in range(len(fhand)):
            if fhand[j][i] == '0':
                count += 1
            else:
                count -= 1

        if count > 0:
            gamma += '0'
            epsilon += '1'
        else:
            gamma += '1'
            epsilon += '0'

    return int(gamma,2) * int(epsilon,2)


from typing import Counter


def bit_criteria(file,j):
    count = 0
    for i in file:
        if i[j] == '0':
            count += 1
        else:
            count -= 1
    if count > 0:
        return '0' , '1'
    return '1' , '0'

def Part_B(file):
    
    fhand = open(file,'r').readlines()

    
    O,CO2 = bit_criteria(fhand,0)
    O_list = [x.strip() for x in fhand if x.startswith(O)]
    CO2_list = [x.strip() for x in fhand if x.startswith(CO2)]
    j = 1

    while len(O_list) > 1:

        if len(O_list) > 1:
            O += bit_criteria(O_list,j)[0]
            O_list = [x.strip() for x in O_list if x.startswith(O)]

        if len(CO2_list) > 1:
            CO2 += bit_criteria(CO2_list,j)[1]
            CO2_list = [x.strip() for x in CO2_list if x.startswith(CO2)]
        
        j += 1

    return  int(O_list[0],2)*int(CO2_list[0],2)


