import sys

#header

DEBUG = False

#descript
#inputs: indfex value that has been validated, and who
#output: modifies the list 
def enterValue(value, who, listValues):
    
    if(who == True): 
        #then X
        listValues[value] = 'X'
    else:
        listValues[value] = 'O'

#descript: print the game board
#inputs: none
#output: none
def printBoard():
    print("-------------")
    print("| 0 | 1 | 2 |")
    print("| 3 | 4 | 5 |")
    print("| 6 | 7 | 8 |")
    print("-------------")

#descript: print the game board
#inputs: none
#output: none
def printRealBoard(listValues):
    print(listValues)
"""
#   i added the line inder this comment so i dont have to tyoe a lot
    lv = listValues 
    print("-------------")
    print("| ", lv[0] | 1 | 2 |")
    print("| 3 | 4 | 5 |")
    print("| 6 | 7 | 8 |")
    print("-------------")
"""


#descript
#inputs: list of x's and o's
#output: True/false
def checkWin(listValues):
    # check first vertical
    if (listValues[0] == listValues[3] == listValues[6]):
        return True


#descript
#inputs: indfex value that has been validated
#output: True/false
def spotTaken(value, listValues):
    #if spot takes, return True
    if(listValues[value] == 'X' or listValues[value] == 'O'):
        return True

    return False

#descript
#inputs: indfex value that has been validated
#output: True/false
def greeting():
    print("Mr. Lupoli")
    print("This is a tic-tac-toe")

def main():

    greeting()
    
    #create list
    board = ['z','z','z','z','z','z','z','z','z']

    # countert can only up to 9
    counter = 1
    # X is 1, 3, 5, etc...

    #bollean Flag for player
    player = True
    # player if True = X, else O

    # enter a while loop here
    # while loop will run until a winner or TIE
    """
    while(counter < 9):
        printBoard()

        #try for validation
        try:
            index = int(input("Pick a value to enter a character"))
        
            if(index >= 0 and index < 9):
            # valid input
                if(DEBUG):
                    print("input WAS valid")

                #check to see if spot was already taken
                if(spotTaken(index, board) == True):
                    print("That spot has already been taken")
                    # counter should not go up, well kinda
                    printRealBoard(board)
                    counter -= 1
                else:
                    #if successful
            
                    #entered the value
                    enterValue(index, (counter % 2) + 1, board)

                    #print REAL Board
                    printRealBoard(board)

                    winner = checkWin(board)
            else:
                print("intger value was not in range of 0-8")
                

            if(winner == True):
                print("WINNER!!!")
                sys.exit() 
                #since we are REALLY DONE

            counter+=1

        except ValueError:
            print("Dummy")
        except NameError:
            print("dunny")

    # VERIFICATION FOR THE ENTERVALUE() FUNCTION
    testList = []
    testList.append("-")
    testList.append("-")
    testList.append("-")
    testList.append("-")

    enterValue(0, True, testList)
    # X better be at 0
    print("X better be at 0")
    print(testList)
    enterValue(0,False,testList) 
    # O better be at 1
    print("O better be at 0")
    print(testList)
    enterValue(1,True,testList)
    # X better be at 1
    print("X better be at 1")
    print(testList)
    enterValue(1,False, testList)
    # O better be at 1 
    print(" O better be at 1")
    print(testList)
    print("game is done!!")


#   VERIFICATION FOR SPOTTAKEN() FUNCTION 

    testList = ["-","-","X","O"]
    print(testList)
    for j in range(len(testList)):
        if(spotTaken(j,testList) == True):
            print("spot is taken")
        else: 
            print("spot is not taken")

"""

        














main()
