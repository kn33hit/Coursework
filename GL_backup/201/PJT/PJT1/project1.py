# project1.py
# Neh Patel
# November 14, 2013
# Section 17
# npatel10@umbc.edu
# Autofill project 
#------------------------------------------------------------------------------
# printGreeting: prints a greeting
def printGreeting():
    print("THIS IS THE AUTOFILL PROGRAM!")

# readFile: reads the file and counts the number of rows and columns
# input: name of the file as a string 
# output: returns the row and columns the grid in the file has 
def readFile(filename):
    row = 0
    column = 0
    inFile = open(filename, "r")
    for line in inFile:
        row += 1
    column = len(line.strip())
    inFile.close()
    return row,column 

# modifyMatrix: takes in the whatever matrix is passed to it and modifies it
# input: a matrix
# output: a new matrix 
def modifyMatrix(matrix,filename):
    # passed i into the function since i can not have more than 9 lines of
    # code in a function 
    i = 0
    inFile = open(filename, "r")
    for line in inFile:
        string = line.strip()
        for j in range(len(string)):
            matrix[i][j] = string[j]
        i += 1
    inFile.close()
    return matrix

# printMatrix: prints the matrix that is passed to this function 
def printMatrix(matrix):
    for i in range(len(matrix)):
        string = ""
        for j in range(len(matrix[0])):
            string += matrix [i][j]
        print(string)
        
# validateX: checks the X entered and returnd the int x & true if everythin 
#            is valid           
# input: a string as x coordinate  
# output: returns x as an int and a boolean  
def validateX(xCoord,row,flagX,x):
    if xCoord.isalpha() == False:
        x = int(xCoord)
        if x > -1 and x < (row):
            flagX = True
        else:
            print("X-coordinate is out of range")
    else:
        print("x is not a number please enter a number") 
    return x, flagX

# validateY: checks the Y entered and returnd the int y & true if everything
#            is valid
# input: a string as Y coordinate   
# output: returns y as an int and a boolean  
def validateY(yCoord,column,flagY,y):
    if yCoord.isalpha() == False:
        y = int(yCoord)
        if y > -1 and y < (column):
            flagY = True
        else:
            print("y-coordinate is out of range")
    else:
        print("y is not a number please enter a number")
    return y, flagY


# autofill: a recursive function which fill out and basically paint the grid
#           in the file. The X is considered a border, so teh paint will not
#           pass through it and only paint the area on the coordinates side
# input: x and y coordinate the user wanted, and the matrix that looks like 
#        the grid in the file 
# output: returns the new modified-autofilled matrix  
def autoFill(x,y,listOne):
    if listOne[x][y] == ".":
        listOne[x][y] = "x"
    else:
        return

        # right 
    if y < (len(listOne[0]) - 1):
        y = y + 1
        if listOne[x][y] == ".":
            autoFill(x,y,listOne)
  
       # down 
    if x < (len(listOne) - 1):
        x = x + 1
        if listOne[x][y] == ".":
            autoFill(x,y,listOne)

        #left
    if y >= 0:
        y = y - 1
        if listOne[x][y] == ".":
            autoFill(x,y,listOne) 

    #up
    if x >= 0:
        x = x - 1 
        if listOne[x][y] == ".":
            autoFill(x,y,listOne)    

def main():
    
    # DECLARING VARIABLES 
    flag = True 
    fileFlag = True 
    fileName = ""
    row = 0
    column  = 0
    flagForCoord = True 
    coordinates = ""
    flagX = False
    flagY = False
    coordInList = []
    x = 0
    y = 0

    # GREETING 
    printGreeting() 
    
    while(flag):
        # INPUT OF THE FILE WITH VALIDATION 
        while(fileFlag):
            try:
                fileName = input("Please pick a file to read, or type 'quit\
' to exit:")
                if fileName == "quit":
                    fileFlag = False
                    # THIS STOPS THE ENTIRE PROGRAM
                    flag = False
                else:
                    inFile = open(fileName, "r")
                    fileFlag = False
                    inFile.close()
            except FileNotFoundError:
                print("File not found")
            except IOError:
                print("File not found")
        
        if fileName != "quit":
        # READING THE FILE AND DETERMINING THE NUMBER ROWS AND COLUMNS 
            row,column = readFile(fileName)

        # USING THE ROW AND COLUMN NUMBER TO MAKE AN EMPTY MATRIX
            matrix = [0] * row 
            for w in range(row):
                matrix[w] = [0] * column 
            
        # TAKING THE EMPTY MATIX TO MODIFY IT TO LOOK LIKE THE FILE 
            modifiedMatrix = modifyMatrix(matrix,fileName) 
            print("The file chosen looks like this before autofill: ")
    
        #PRINTING THE MATRIX IN THE FILE
            printMatrix(modifiedMatrix)
    
            while(flagForCoord):
        # INPUT OF THE COORDINATES 
                    coordinates = input("Please select x and y coordinate \
to satrt the autofill: ")
        # split the coordinates into two and stored it in a list 
                    coordInList = coordinates.split()
                    if len(coordInList) == 2:
                        # validating for x and y in different functions to 
                        # minimize the line of code in the functions
                        # plus passed 0 as x and y in both function to shorten
                        # the line of code in it by one line 
                        x,flagX = validateX(coordInList[0],row,flagX,0)
                        y,flagY = validateY(coordInList[1],column,flagY,0)
                        if flagX == True and flagY == True:
                            flagForCoord = False
                        # did this otherwise you would only need to two invalid
                        # inputs to break the code 
                        flagX = False
                        flagY = False
                    else:
                        print("There is only one coordinate, need two")
    
        # CALLING THE RECURSION FUNCTION 
            autoFill(x,y,modifiedMatrix)
    
            print("After autofill, starting at <",x,",",y,"> the result\
s are:")
            printMatrix(modifiedMatrix)
            # did this so when it starts over again it makes sure to do the 
            # whole program again 
            fileFlag = True 
            flagForCoord = True  
    # once it quits the loop that has the whole programs body it prints this 
    print("Thank you. Program complete") 


main()
