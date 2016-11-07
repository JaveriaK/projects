# Command Line Pente Game
# Author: Javeria Khan

import os
import sys

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
            print('\x1b[1;32;40m'+"%s"%Board[row-1][piece]+'\x1b[0m'),
            #%s"%Board[row-1][piece],
        print '|'

        #Print Horizontal Borders
        print '  ',
        print("+---"*colNumber+"+")

    return

if __name__ == "__main__":

    # Size of board is configurable, currently set to 15x15
    size = "15x15"
    sizeList = []
    global Board
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

    
    DrawBoard(rowNumber,colNumber)


    #Take input
    while True:
        print "\nEnter q to quit"
        coordinates = raw_input("\nPlayer turn. Enter location to place piece (x,y): ")
        if coordinates.lower() == 'q':
          print('\x1b[1;31;40m' + '\n\nEnding Game....\n\n' + '\x1b[0m')
          sys.exit(0)
        else:

            coor_list = (coordinates.split(","))
            x_cor = int(coor_list[0])
            y_cor = int(coor_list[1])

            print "x: %s"%x_cor
            print "y: %d"%y_cor
            Board[x_cor-1][y_cor-1] = 'X'

            DrawBoard(rowNumber,colNumber)


