# file : hw7.py
# author : Neh Patel
# date : 10/31/2013
# section : 17
# email: npatel10@umbc.edu 
# description : hangman game, with 4 incorrect guesses. has the option if the
#               the user wants to play again. The words are choosen from a 
#               file 
#------------------------------------------------------------------------------
# NEED TO IMPORT RANDOM FUNCTION TO USE IT 
from random import randrange

# printGreeting: prints a greeting 
# No input or output 
def printGreeting():
    print("$ python hw7.py")
    print("----------------------------------------------------------------")
    print("H A N G M A N")
    print("----------------------------------------------------------------")
    return 

# readWords: this function reads a file and returns a list of strings
# input: a file 
# output: a list of strings  
def readWords(fileName):
    words = []
    wordsInLine = []
    inFile = open(fileName, "r")
    for line in inFile:
        # makes a list of strings for the line only
        wordsInLine = line.split()
        # adds the lines list of string to the entire words list 
        words = words + wordsInLine
    inFile.close()
    return words

# playGame: takes the list of words, calls getRandomWord(), and 
#           loops until the game is either won or lost
# input: list of words
# output: none really, homie 
def playGame(words):
    numMissedLetters = 4
    correctLetters = []
    secretWord = ""
    allGuessedLetters = []
    gameWon = False
    gameLost = False
    guess = ""
    gameDone = False 
    
    # calling to get the secret random word 
    secretWord = getRandomWord(words)
    while(gameDone == False):
            # displays the game basically 
            displayTurn(numMissedLetters,correctLetters,secretWord)
            # validation for guess inside the getGuess function 
            guess = getGuess(allGuessedLetters)
            if guess in secretWord:
                correctLetters.append(guess)
                print("There is a " , guess)
            else:
                print("Sorry, no " , guess)
                numMissedLetters = numMissedLetters - 1  
            gameWon = wonGame(correctLetters,secretWord)
            gameLost = lostGame(numMissedLetters,secretWord)
            # once game won/lost the game will stop
            if (gameWon == True) or (gameLost == True):
                gameDone = True
    return

# getRandomWords: this function reads the list of strings and picks a random
#                 string 
# input: a list of strings recieved from the file 
# output: a random word from the list of strings 
def getRandomWord(words):
    secretWord = ""
    number= 0
    length = len(words)
    # the number determines a random number between 0 (included) and the 
    # length of the list ( random(x,y) works perfect for list)
    number = randrange(0,(length))
    secretWord = words[number]
    return secretWord

# displayTurn: displays the game ( missed letters, correct letters, 
#              by comparing it with the secret word)
# input: number of missed letters, correct letters, and the secret word
# no output 
def displayTurn(numMissedLetters,correctLetters,secretWord):
    displayString = ""
    for j in range(len(secretWord)):
        char = secretWord[j]
        if char in correctLetters:
            # adding the chr to the list of dashes if guess is correct 
            displayString = displayString + " " + char + " "
        else: 
            # keeps the dashes
            displayString = displayString + " _ "
    # printing the game 
    print(displayString , "\t incorrect guesses left: ",numMissedLetters)
    return 

# getGuess: takes a list of all the guessed letters (correct/incorrect)
#           Gets letter input from user, checking for its validation 
#           looping until a valid guess as been made and returns the guess 
# input: list of guessed letters 
# output: letter guessed by the user 
def getGuess(allGuessedLetters):
    guess = ""
    flag = True 
    while(flag):
        # INPUT of GUESS 
        guess = input("Guess a letter: ")
        guess = guess.lower()
        # making sure guess is only 1 letter
        if len(guess) == 1:
            # making sure the guess is an alphabet 
            isAlpha = guess.isalpha()
            if isAlpha == True:
                # making sure the guess was not guessed before 
                if guess in allGuessedLetters:
                    print("You already guessed the letter.Choose again")
                else:
                    # if all 3 conditions met, then the gues is added to 
                    # guesses list and exits out the loop 
                    allGuessedLetters.append(guess)
                    flag = False 
            else:
                print("Please enter a LETTER")
        else:
            print("Must enter a single letter") 
        
    return guess
 
# wonGame: takes list of correct guesses and teh secret word,returns if the 
#          game is lost or won 
# input: list of correct letters
# output: boolean if the game is won or not (true or false) 
def wonGame(correctLetters,secretWord):
    gameWon = False 
    secretWordCaps = secretWord.upper()
    count = 0
    # checks if the correct guesses list match the secret word alphabets 
    # if it does, then the user wins
    for j in range(len(secretWord)):
        if secretWord[j] in correctLetters:
            count = count + 1 
    if count == len(secretWord):
        gameWon = True
        print("You won! The word is " , secretWordCaps)
    return gameWon

# lostGame: takes in number of incorrect guesses and returns if the game is
#           lost or not 
# input: number of incorrect guesses 
# output: boolena if the game is lost or not (true or false)
def lostGame(numMissedLetters,secretWord):
    gameLost = False
    # once the counter hits to 0 guesses left then the user loses
    if numMissedLetters == 0:
        gameLost = True 
        print("Sorry you're out of guesses, the word was ", secretWord)
    return gameLost

# againPlay: prompts the user if they want to play again 
# input: from the user 
# output: booelan 
def againPlay():
    playAgain = "n"
    flag = True
    playAgainBool = False
    playAgain = input("Play again (y/n): ")
    # validating for only Y/N, noithing else
    while(flag):
        playAgain = playAgain.lower()
        if playAgain == "y" or playAgain == "n":
            flag = False 
        else: 
            playAgain = input("invalid input try again (Y/N): ") 
    # playAgainBool only changes when playAgain is Y, as it was already 
    # set to False in the beginning of the loop 
    if playAgain == "y":
        playAgainBool = True 
    return playAgainBool


def main():
    # Decalring Variables
    playAgain = True
    gameDone = False 
    words = []
    filename = "" 
    flagForFile = True 
    
    #GREETING 
    printGreeting()
    
    # file name input with validation 
    while(flagForFile):
        try:
            filename = input("Enter the name of file holding words: ")
            # when you open a file, and it is not opened it is sent to the 
            # except so it will run again,
            # but if it does open then the flag is set to false and 
            # validation stops 
            inFile = open(filename,"r")
            flagForFile = False
            inFile.close()
        except FileNotFoundError:
            print("This file does not exist")

    # reading the words from the files 
    words = readWords(filename)

    while(playAgain):
        playGame(words)
        playAgain = againPlay()
    # its good to see such a short main() lol
main()
