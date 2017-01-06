# File:        lab12.py
# Written by: Neh Patel 
# Date:       November 21
# Section:    17
# Email:      npatel10@umbc.edu
# Description: 
#

# Place questions about this project BELOW this line

ROW = 5
COL = 5
ADJVAL = 4 

def multiplyHorizontal(matrix):
    '''
    Need to code:
    Initializing a MAX value
    Out of bounds
    Comparison of the recently multiplied to the CURRENT MAX
    Storing the NEW max value
    '''
    listOne = []
    answer = 1
    maxNum = 0 # change ????
    for i in range(ROW):
        maxNum = 0 
        for j in range(COL - ADJVAL + 1):
           number = matrix[i][j]* matrix[i][j+1]* matrix[i][j+2] * matrix[i][j+3]
           listOne.append(number)
            #condition here!!
    print(listOne)
    for i in range(len(listOne)):
        if listOne[i] > maxNum:
            maxNum = listOne[i]
    return maxNum 

def multiplyVertical(matrix):
    # ONLY START ON THIS WHEN MULTIPLYHORIZONTAL WORKS!!!
    # ONLY START ON THIS WHEN MULTIPLYHORIZONTAL WORKS!!!
    # ONLY START ON THIS WHEN MULTIPLYHORIZONTAL WORKS!!!
    # ONLY START ON THIS WHEN MULTIPLYHORIZONTAL WORKS!!!
    # ONLY START ON THIS WHEN MULTIPLYHORIZONTAL WORKS!!!
    answer = 1
    maxNum = 0
    listOne = []
    for i in range(COL - ADJVAL + 1):
        for j in range(ROW):
            number = matrix[i][j]* matrix[i+1][j]* matrix[i+2][j]* matrix[i][j] * matrix[i+3][j]
            listOne.append(number)
    print(listOne)
    for i in range(len(listOne)):
        if listOne[i] > maxNum:
            maxNum = listOne[i]
    return maxNum

def main():

    # setup
    twoD = [0] * ROW
    for i in range(ROW):
        twoD[i] = [0] * COL

    # enter 25 values individually
    # you can chnage the two lines below if you wish
    twoD[0][0] = 1
    twoD[0][1] = 7
    twoD[0][2] = 3
    twoD[0][3] = 4
    twoD[0][4] = 6
    twoD[1][0] = 8
    twoD[1][1] = 2
    twoD[1][2] = 5
    twoD[1][3] = 9
    twoD[1][4] = 6
    twoD[2][0] = 3
    twoD[2][1] = 2
    twoD[2][2] = 1
    twoD[2][3] = 6
    twoD[2][4] = 7
    twoD[3][0] = 4
    twoD[3][1] = 5
    twoD[3][2] = 8
    twoD[3][3] = 9
    twoD[3][4] = 5
    twoD[4][0] = 1
    twoD[4][1] = 2
    twoD[4][2] = 3
    twoD[4][3] = 4
    twoD[4][4] = 6


    # you have 23 more to go!!
    print(twoD)
    maxHorizontal = multiplyHorizontal(twoD)
    print(maxHorizontal)

    maxVertical = multiplyVertical(twoD)
    print(maxVertical)



main()
