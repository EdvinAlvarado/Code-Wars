import re

def connectFour_viewer(grid):
	print('--------------')
	for i in range(5, -1, -1):
		for g in grid:
			if g[i] != 0:
				if g[i] == 1:
					print('R', end='|')
				elif g[i] == 2:
					print('Y', end='|')
			else:
				print(" ", end='|')
		print('')
	print('--------------')
	print("A|B|C|D|E|F|G")

# Right checking doens't work because the list doesn't exist at that point
def horizontal_checker(grid, r, c, val, step=1):
	if grid[r][c] == 0:
		return 0
	try:
		print("h\t{} = {}\ts {}".format(val, grid[r][c+step], step))
		if grid[r][c+step] == val:
			return 1 + horizontal_checker(grid, r, c+step, val, step)
		else:
			return 0
	except IndexError:
		return 0

# Right checking doens't work because the list doesn't exist at that point
def vertical_checker(grid, r, c, val, step=1):
	if grid[r][c] == 0:
		return 0
	try:
		print("v\t{} = {}\ts {}".format(val, grid[r+step][c], step))
		if grid[r+step][c] == val:
			return 1 + vertical_checker(grid, r+step, c, val, step)
		else:
			return 0
	except IndexError:
		return 0

# Right checking doens't work because the list doesn't exist at that point
def downUpDiagonal_checker(grid, r, c, val, step=1):
	# if c == 0 or c == 5 or r == 0 or r == 6 or grid[r][c] == 0:
	if grid[r][c] == 0:
		return 0
	try:
		print("du\t{} = {}\ts {}".format(val, grid[r+step][c+step], step))
		if grid[r+step][c+step] == val:
			return 1 + downUpDiagonal_checker(grid, r+step, c+step, val, step)
		else:
			return 0
	except IndexError:
		return 0

# Right checking doens't work because the list doesn't exist at that point
def upDownDiagonal_checker(grid, r, c, val, step=1):
	# if c == 0 or c == 5 or r == 0 or r == 6 or grid[r][c] == 0:
	if grid[r][c] == 0:
		return 0
	try:
		print("ud\t{} = {}\ts {}".format(val, grid[r-step][c+step], step))
		if grid[r-step][c+step] == val:
			return 1 + upDownDiagonal_checker(grid, r-step, c+step, val, step)
		else:
			return 0
	except IndexError:
		return 0

def who_is_winner(pieces_position_list):

	# sideways for easier input.null=True
	grid = [[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

	loc = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G': 6}
	color = {'Red': 1, 'Yellow': 2}

	counter = 1

	for piece_pos in pieces_position_list:
		plist = re.findall(r'[^_]+', piece_pos)
		print(plist)

		row_pos = loc[plist[0]]
		col_pos = grid[loc[plist[0]]].index(0)

		grid[row_pos][col_pos] = (color[plist[1]])

		print('')
		counter += 1
		print(counter)
		connectFour_viewer(grid)

		h = horizontal_checker(grid, row_pos, col_pos, color[plist[1]], -1) + 1 + horizontal_checker(grid, row_pos, col_pos, color[plist[1]])
		v = vertical_checker(grid, row_pos, col_pos, color[plist[1]], -1) + 1 + vertical_checker(grid, row_pos, col_pos, color[plist[1]])
		ud = upDownDiagonal_checker(grid, row_pos, col_pos, color[plist[1]], -1) + 1 + upDownDiagonal_checker(grid, row_pos, col_pos, color[plist[1]])
		du = downUpDiagonal_checker(grid, row_pos, col_pos, color[plist[1]], -1) + 1 + downUpDiagonal_checker(grid, row_pos, col_pos, color[plist[1]])

		print("v:{} h:{} du:{} ud:{}".format(h, v, ud, du))
		if h >= 4:
			return plist[1]
		if v >= 4:
			return plist[1]
		if ud >= 4:
			return plist[1]
		if du >= 4:
			return plist[1]


	print(grid)
	print('')
	connectFour_viewer(grid)
	return "Draw"





x = who_is_winner([ 
"C_Yellow", "E_Red", "G_Yellow", "B_Red", "D_Yellow", "B_Red", "B_Yellow", "G_Red", "C_Yellow", "C_Red",
"D_Yellow", "F_Red", "E_Yellow", "A_Red", "A_Yellow", "G_Red", "A_Yellow", "F_Red", "F_Yellow", "D_Red", 
"B_Yellow", "E_Red", "D_Yellow", "A_Red", "G_Yellow", "D_Red", "D_Yellow", "C_Red"
])

print(x)





from itertools import count, takewhile

X, Y, HALF_DIRS = 6, 7, ((0,1),(1,0),(1,1),(1,-1))


def who_is_winner(lstMoves):
    
    def isWinner(): return any(countAligned(*dirs) >= 4 for dirs in HALF_DIRS)
    
    def isInsideAndSameGuy(a, b): return 0 <= a<X and 0 <= b<Y and board[a][b]==who
    
    def countAligned(dx, dy):
        return 1 + sum(sum(takewhile(bool, (isInsideAndSameGuy(x+dx*swap*n, y+dy*swap*n) for n in count(1))))
                        for swap in (1, -1))
    
    
    board = [[' ']*Y for _ in range(X)]
    xIdx  = [0]*Y
    
    for move in lstMoves:
        y, who      = ord(move[0])-65, move[2]
        x           = xIdx[y]
        board[x][y] = who
        xIdx[y]    += 1
        if isWinner(): return move[2:]
    else:
        return "Draw"