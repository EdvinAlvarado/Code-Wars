from itertools import count, takewhile

X, Y = 6, 7
DIRS = ((0, 1), (1, 0), (1, 1), (-1, 1))

def who_is_winner(move_list):

	def insideAndEqual(y, x):
		return (0 <= y < Y) and (0 <= x < X) and (board[y][x] == player)

	def countAligned(dy, dx):
		return 1 + sum(sum(takewhile(bool, (insideAndEqual(y + dy*axis_dir*n, x + dx*axis_dir*n) for n in count(1)))) for axis_dir in (1, -1))

	def isWinner():
		return any(countAligned(*dir) >= 4 for dir in DIRS)

	board = [[0 for _ in range(X)] for _ in range(Y)]

	for move in move_list:
		y = ord(move[0]) - 65
		player = move[2]
		x = board[y].index(0)

		board[y][x] = player

		print(board)

		if isWinner():
			return move[2:]
	return "Draw"