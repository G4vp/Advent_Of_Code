


def Part_A(file):
    fhand = open(file,'r')
    horizontal = 0
    depth = 0

    for line in fhand:
        direc, x = line.strip().split()

        if direc == "forward":
            horizontal += int(x)
        elif direc == "down":
            depth += int(x)
        elif direc == "up":
            depth -= int(x)

    return horizontal * depth

def Part_B(file):
    fhand = open(file,'r')
    horizontal = 0
    depth = 0
    aim = 0

    for line in fhand:
        direc, x = line.strip().split()

        if direc == "forward":
            horizontal += int(x)
            depth += int(x) * aim
        elif direc == "down":
            aim += int(x)
        elif direc == "up":
            aim -= int(x)
    return horizontal * depth



