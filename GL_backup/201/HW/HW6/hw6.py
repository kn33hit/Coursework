# file : hw6.py
# author : Neh Patel
# date : 10/22/2013
# section : 17
# email: npatel10@umbc.edu 
# description: a mini game, "P" is the position of the player, and "K" is the
#              key, the player needs to get to. If the player is not allowed  
#              to get near the order of the board. and the program keeps
#              running until the plater gets a position next to the key. 
#------------------------------------------------------------------------------

# printBoard: just prints out the board by taking in the positions 
#             of the player, and the key 
# input: X and Y coordinate of the player( playerX, playerY)(2,4)
#        X and Y coordinate of the key ( keyX, keyY) (3,6)
# output: prints out the new updated board  
def printBoard(playerX, playerY, keyX, keyY):
    boardAsString = ""
    # I could've used a for loop to create the matrice, but this helped me 
    # visualize the board and code accordingly 
    board = [[".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."], \
             [".",".",".",".",".",".",".","."]] 
    board[playerX][playerY] = "P"
    board[keyX][keyY] = "K"
    # printing the board with the border
    # the top and bottom borders are added outside the for loop 
    # inside the for loop : the array of dots is put together as a string
    # with the side borders 
    print("------------")
    for i in range(8):
        boardAsString = ""
        for j in range(8):
            boardAsString = boardAsString + board[i][j]
        print("|",boardAsString,"|")
    print("------------")
    return 


# updatePosition: takes the direction entered by the player, and updates the 
#                  board 
# input: direction (entered by the user) and the position of Player (playerX,
#        playerY) 
# output: updated position values (playerX, playerY)   
def updatePosition(direction, playerX, playerY):
    # the hw document said to call offBoard in here (figure it out) 
    onBorder = False
    onBorder = offBoard(playerX,playerY)
    # moving south 
    if onBorder == True:
        print("You're not allowed to go past the border. Game reset!")
        playerX = 2
        playerY = 4
        return playerX,playerY
    if direction == "south":
        playerX = playerX + 1 
    # moving north 
    if direction == "north":
        playerX = playerX - 1
    # moving west 
    if direction == "west":
        playerY = playerY - 1
    #moving east 
    if direction == "east":
        playerY = playerY + 1 
    return playerX, playerY


# offBoard: takes the player's new position and returns True if near the border
#           or false if they're not 
# input: (pX, pY) position of the player 
# output: Boolean ( True or False )
def offBoard(pX, pY):
    offBoard = False
    # left and right border 
    if pX <= 0 or pX >= 7:
        offBoard = True
    # top and bottom border
    if pY <= 0 or pY >= 7:
        offBoard = True 
    return offBoard  


# reachedKey: returns True if the player is near the key 
# input: position of player, and key (playerX, playerY, keyX, keyY) 
# output: boolean (True or False)
def reachedKey(playerX, playerY, keyX, keyY):
    reachedKey = False 
    if playerX == (keyX - 1) and playerY == keyY:
        reachedKey = True 
    if playerX == (keyX + 1) and playerY == keyY:
        reachedKey = True 
    if playerX == keyX and playerY == (keyY - 1):
        reachedKey = True 
    if playerX == keyX and playerY == (keyY + 1):
        reachedKey = True
    return reachedKey 


def main():
#   DECLARING VARIABLES 
    # these two constants set the default position for the player (2,4) 
    PLAYER_X = 2 
    PLAYER_Y = 4
    # two more variables that store the new updated values of the player
    playerX = PLAYER_X
    playerY = PLAYER_Y
    # these two constants set the default positions for the key (3,6)
    KEY_X = 3
    KEY_Y = 6 
    direction = "" #input 
    flag = True 
    # list are the proper inputs 
    properDirections = ["north","south","east","west"]
    keyReached = False  

    #GREETING 
    print("Welcome to the Loops HW. Get to the key!!!")

    # while loop to run game until the player reaches the key 
    while(keyReached == False):
       #PRINTS THE BOARD BY CALLING THE printBoard() FUNCTION 
        printBoard(playerX,playerY, KEY_X, KEY_Y) 
        
        #calling key reached here
        keyReached = reachedKey(playerX,playerY,KEY_X,KEY_Y)
        
        # doing this so position is asked and updated only if the player 
        # still needs to be moved.This code under the if will not run if
        # the player has reached the key and will also exit the loop
        # once keyReached is set to True
        if keyReached == False:
           #INPUT 
            direction = input("North, South, East, or West?")
           
           #VALIDATION FOR THE INPUT 
            while(flag):
                direction = direction.lower()
                if direction in properDirections:
                    flag = False 
                else:
                    direction = input("Invalid input. North, South, East or \
West?") 
            flag = True
        #UPDATING POSITION OF THE PLAYER
        playerX, playerY = updatePosition(direction,playerX,playerY)
        
    # print statement. does not need a condition 
    # the code only ends when it exits the loop, by reaching the key.
    # so once it reaches it. it will print out the code 

    print("You've reached the key")


main() 
