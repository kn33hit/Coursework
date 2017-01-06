# File : hw5.py
# Author : Neh Patel 
# Date : 10/9/2013
# Section : 17
# Email : npatel10@umbc.edu 
# Description : this program first gives a choice to user on a menu to what
#               they want to ( one of four choices) : binary to decimal,
#               decimal to binary, decimal to hexadecimal, or quit
#               the user chooses one, and the program runs accordingly
#------------------------------------------------------------------------------


# printGreeting() : explains the program to user
# input : none
# output : some print lines
def printGreeting():
    print("This program will convert values")
    print("[A] - Convert from decimal to binary")
    print("[B] - Convert from decimal to hexadecimal")
    print("[C] - Convert from binary to decimal")
    print("[D] - QUIT")



# decToHex(): takes a decimal number, and converts it to a 
#              hexadecimal number
# input : decimal number as an integer 
# output : hexadecimal number as a string  
def decToHex(number):
    # the variable that will be returned 
    finalAnswer = ""
    # this list will be the output, and it will be compared to the modulus 
    # output, and whichever position is the same will be added to 
    # finalAnswer
    hexVal=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
    while(number > 15):
        remainder = number % 16
        numberAsStr = str(remainder)
        for a in range(hexVal):
            if numberAsStr == hexVal[a]:
                finalAnswer = finalAnswer + hexVal[a]
        number = number / 16 
    return finalAnswer



# decToBin() : takes a binary number, and converts it to a
#               decimal number 
# input : decimal number as an integer 
# output : binary number as a string 
def decToBin(decNumber):
    finalAnswer = ""
    while(decNumber > 1):
        remainder = decNumber % 2
        finalAnswer = finalAnswer + str(remainder)
        decNumber = decNumber / 2
    finalAnswer = finalAnswer[::-1]
    return finalAnswer



# binToDec() : takes a binary number, and converts it to a 
#               decimal number 
# input : binary number as a string
# output: decimal number as an integer 
def binToDec(binNumber):
    finalAnswer = 0
    # just making sure it is a string 
    binNumber = str(binNumber)
    #switched the string  backwards so the power starts from 0 in the for loop 
    # instead of starting from 8 and then going backwards 
    binNumber = binNumber[::-1]
    #reverse the number string first instead of doing it afterwards same thing 
    for i in range(len(binNumber)):
        if(binNumber[i] == "1"):
            finalAnswer = finalAnswer + (2 ** i)
    return finalAnswer



def main():
#GREETING
    printGreeting() 

#DECLARING VARIABLES
    # flag = used in the frist while loop for input (validation)
    flag = True
    menuInput = 0  # the input in the menu (A, B, C, D)
    numInput = 0   # the input when the number to converted, is entered
    finalAnswer = 0
    # QUIT is 68 since the ascci value for "D" is 68 
    QUIT = 68
    BITLENGTH = 8

#INPUT
    menuInput = input("What is your choice? ")
    while(flag):
        if len(menuInput) == 1:
            menuInput = menuInput.upper()
            menuInput = ord(menuInput)
        else:
            menuInput = input("Invalid number, try again: ")
        # the for statement is to check the input with the list 
        # if it doesn't, then the input is asked for again in the 
        # else statement 
        try:
            if menuInput > 64 and menuInput < 69: 
                    flag = False
            else:
                    menuInput = input("Invalid number, try again: ")
        except NameError:
            menuInput = input("Invalid input, try again: ")    
        except ValueError:
            menuInput = input("Invalid input, try again: ")
        except TypeError:
            menuInput = input("Invalid input, try again: ")

    # set flag back to true to use it again later 
    flag = True
    # these if, and elif statements hekp figure out what function to call
    # according to the input in the main menu
    # when A is picked
    if menuInput == 65:
        inputNum = input("Enter the number: ")
        while(flag):
            try:
                inputNum = int(inputNum)
                # the range is from 0-250
                if inputNum >= 0 and inputNum <= 255: 
                   flag = False 
                else:
                    inputNum = input("Invalid number, try again: ")
            except TypeError:
                inputNum = input("Invalid number, try again: ")
            except ValueError:
                inputNum = input("Invalid number, try again: ")
            except NameError:
                inputNum = input("Invalid number, try again: ")
        # set inputNum back to a string as we are going to pass it
        # to the function as a string 
        finalAnswer = decToBin(inputNum)
        flag = True 
    # when B is picked 
    elif menuInput == 66:
        #could've made a function for the input of the number ot be 
        # converted but already typed everything out, then realized
        inputNum = input("Enter the number: ") 
        while(flag):
            try:
               inputNum = int(inputNum) 
              # the range is from 0 to 250 
               if inputNum >= 0 and inputNum <= 255:
                   flag = False
               else:
                   inputNum = input("Invalid number, try again: ")
            except TypeError:
               inputNum = input("Invalid number, try again: ")
            except ValueError:
               inputNum = input("Invalid number, try again: ")
            except NameError:
                inputNum = input("Invalid number, try again: ")
        finalAnswer = decToHex(numInput)
        flag = True
    # when C is picked 
    elif menuInput == 67:
        inputNum = input("Enter the number: ")
        while(flag):
            if len(inputNum) == BITLENGTH:
                for item in range(len(inputNum)):
                    # so it only excepts the number in 0s and 1s 
                    if inputNum[item] == "0" or inputNum[item] == "1":
                        flag= False
                    else:
                        inputNum = input("Invalid input, try again: ")
            else:
                inputNum = input("Invalid bit pattern, must be 8 digits long, try again: ")
        finalAnswer = binToDec(numInput) 

#   OUTPUT
    # have the if statement to avoid a print statement when the user
    # wants to quit 
    if menuInput != QUIT:
       print("Your number converted: ", finalAnswer)
    

main() 
