# Command Line Pente Game
# Author: Javeria Khan

import os
import sys
import re
import random

# Draw 15x15 Pente Board
def DrawBoard(rowNumber = 3,colNumber = 3):
    #global Board
    os.system('clear')

    print '   ',
    for col in range(1,colNumber+1):
        print "%2d "%col,

    #First Border
    print '\n  ',
    print("+---"*colNumber+"+")

    for row in range(1,rowNumber+1):
        print "%2d"%row,

        #Print Board pieces
        for piece in range(0,colNumber):
            print "|",
            if Board[row-1][piece] == 'X':
                print('\x1b[1;32;40m'+"%s"%Board[row-1][piece]+'\x1b[0m'),
            elif Board[row-1][piece] == 'O':
                print('\x1b[1;31;40m'+"%s"%Board[row-1][piece]+'\x1b[0m'),
            else:
                print('\x1b[1;32;40m'+"%s"%Board[row-1][piece]+'\x1b[0m'),
        print '|'

        #Print Horizontal Borders
        print '  ',
        print("+---"*colNumber+"+")

    #Print Moves History
    print "\nMoves by X:"
    for move in X_moves:
        print "(%s) "%move,

    print "\n\nMoves by O:"
    for move in O_moves:
        print "(%s) "%move,

    return

def O_play():
   x_cor = random.randint(1,15)
   y_cor = random.randint(1,15)

   #log all valid moves for player-X
   O_moves.append(str(x_cor)+','+str(y_cor))
   Board[x_cor-1][y_cor-1] = 'O'

if __name__ == "__main__":

    # Size of board is configurable, currently set to 15x15
    size = "15x15"
    sizeList = []
    global Board

    #Maintaining history for valid player moves
    X_moves = []
    O_moves = []

    if "x" or "*" in size:
        sizeList = (str(size).replace("x","*")).split("*")
    else:
        sizeList.append(size)

    colNumber = -1
    rowNumber = -1
    if len(sizeList) == 2:
        colNumber = int(sizeList[1])
        rowNumber = int(sizeList[0])
    elif len(sizeList) == 1:
        colNumber = int(sizeList[0])
        rowNumber = colNumber
    
    # Initialize Board
    Board = [[' ' for i in range(1,rowNumber+1)] for j in range(1,colNumber+1)]

    #Take input
    while True:
        #Redraw Board
        O_play()
        DrawBoard(rowNumber,colNumber)
        print "\n\nEnter q to quit"
        coordinates = raw_input("\nPlayer turn. Enter location to place piece (x,y): ")
        if coordinates.lower() == 'q':
          print('\x1b[1;31;40m' + '\n\nEnding Game....\n\n' + '\x1b[0m')
          sys.exit(0)
        elif re.match("^[0-9]{1,2},[0-9]{1,2}$", coordinates, re.M|re.I):

            #Update Board with X's latest move
            coor_list = (coordinates.split(","))
            x_cor = int(coor_list[0])
            y_cor = int(coor_list[1])

            if x_cor < 16 and y_cor < 16:
                #log all valid moves for player-X
                X_moves.append(coordinates)
                Board[x_cor-1][y_cor-1] = 'X'
            else:
                raw_input("Input out of range [1-15].. try again...")

        else:
            raw_input("Invalid Input.. try again...")


