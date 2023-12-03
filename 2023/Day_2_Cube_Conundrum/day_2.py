class Solution:
    def __init__(self) -> None:
        pass

    def part_a(self,file_name) -> int:
        f_open = open(file_name, 'r')
        answer = 0
        for line in f_open:
            game_id, sets_games = line.split(':')
            list_games = sets_games.split(";")
            found_error = False
            for games in list_games:
                gm = games.split(',')
                for i in gm:
                    num, color = i.split()
                    if color == "red" and int(num) > 12:
                        found_error = True
                        break
                    elif color == "green" and int(num) > 13:
                        found_error = True
                        break
                    elif color == "blue" and int(num) > 14:
                        found_error = True
                        break
            if not found_error:
                _, id = game_id.split()
                answer += int(id)
        return answer

    def part_b(self, file_name) -> int:
        f_open = open(file_name, 'r')
        answer = 0
        for line in f_open:
            game_id, sets_games = line.split(':')
            list_games = sets_games.split(";")
            max_red, max_green, max_blue = 0, 0 ,0
            for games in list_games:
                gm = games.split(',')
                for i in gm:
                    num, color = i.split()
                    if color == "red" and int(num) > max_red:
                        max_red = int(num)
                    elif color == "green" and int(num) > max_green:
                        max_green = int(num)
                    elif color == "blue" and int(num) > max_blue:
                        max_blue = int(num)
            answer += (max_red * max_blue * max_green)
        return answer



def main():
    answer = Solution()

    print(answer.part_b("input_1.txt"))

if __name__ == '__main__':
    main()