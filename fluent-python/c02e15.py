weird_board = [['_'] * 3] * 3
# Essentially, this creates 3 references to 1 list
print(weird_board)
weird_board[1][2] = 'O'
print(weird_board)
