class Solution:
    def __init__(self) -> None:
        pass

    def part_a(self,file_name) -> int:
        f_open = open(file_name, 'r')
        
        answer = 0
        for line in f_open:
            
            left = 0
            right = len(line)-1
            while left <= right:
                
                if line[left].isdigit() and line[right].isdigit():
                    print(line[left]+line[right])
                    answer += int(line[left]+line[right])
                    break

                if not line[left].isdigit():
                    left += 1
                if not line[right].isdigit():
                    right -= 1
        return answer
    
    def part_b(self, file_name) -> int:
        f_open = open(file_name, 'r')
    
        answer = 0
        for line in f_open:
            
            left = 0
            right = len(line)-1

            left_substr = ''
            right_substr = ''

            while left <= right:
                
                left_substr = left_substr + line[left]
                right_substr = line[right] + right_substr

                left_fnd_subs = self.find_substring(left_substr)
                right_fnd_subs = self.find_substring(right_substr)
                if left_fnd_subs > 0 and right_fnd_subs > 0:
                    answer += int(str(left_fnd_subs) + str(right_fnd_subs))
                    break
                
                if left_fnd_subs == 0:
                    left += 1
                if right_fnd_subs == 0:
                    right -= 1


        return answer

    def find_substring(self,substr):
        if 'one' in substr or '1' in substr:
            return 1
        elif 'two' in substr or '2' in substr:
            return 2
        elif 'three' in substr or '3' in substr:
            return 3
        elif 'four' in substr or '4' in substr:
            return 4
        elif 'five' in substr or '5' in substr:
            return 5
        elif 'six' in substr or '6' in substr:
            return 6
        elif 'seven' in substr or '7' in substr:
            return 7
        elif 'eight' in substr or '8' in substr:
            return 8
        elif 'nine' in substr or '9' in substr:
            return 9
        else:
            return 0
def main():
    answer = Solution()

    print(answer.part_b("input_2.txt"))

if __name__ == '__main__':
    main()