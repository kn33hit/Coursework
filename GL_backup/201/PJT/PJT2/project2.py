# project2.py
# Neh Patel
# November 27
# Section 17
# npatel10@umbc.edu 
# Takes in an equation and solves it in using the correct order of operations 
# and outputs the order(also the what values were adding to what stakcs)
# of operation and the answer
#------------------------------------------------------------------------------

from stack import *
# DEFINING THE TWO PRIORITY DICTIONARIES 
INPUT_PRIORITY = {"+":1,"-":1,"*":2,"/":2,"%":2,"^":5,"(":6,")":None,"$":None\
,"eoe":None} 
STACK_PRIORITY = {"+":1,"-":1,"*":2,"/":2,"%":2,"^":4,"(":0,")":None,"$":None\
,"eoe":None}
 
# printGreeting(): prints greeting to the user 
# no input and does not return anything
def printGreeting():
    print("Welcome to the TI-201 calculator program")
    print("Name: Neh N. Patel")
    print("Section: 17") 

# initializeStacks(): initializes all the stacks and adds and subtracts values 
# input: opStack, valueStack, inputStack
# output: modified stacks 
def initializeStacks(opStack, valueStack,inputStack):
    # initializing the three stacks with just one element in it 
    push(opStack,"$")
    push(valueStack,"$")
    push(inputStack,-1)
    return 


# getInput(): takes in the input form the user and turns it into a list 
# input: input from the user 
# output: list of all the inputs as a character 
def getInput(inputList):
    inputValid = False 
    # this function will either return a list or a boolean
    # depending on the user input
    inputName = input("Enter the equation or 'QUIT': ")
    if inputName == "QUIT":
        # this willl return the value in the main and won't run the main 
        # program as quitProgram is set to true
        quitProgram = True
        return quitProgram
    # is the input is not valid ask repeatedly 
    while(inputValid != True): 
        inputList = inputName.split()
        inputValid = validateEq(inputList)
        if inputValid == False:
            # if the input is wrong
            inputName = input("Invalid characters in equation. Enter again: ")
        if inputName == "QUIT":
            return True
    print("the equation(list) we are looking at is: " , inputList)
    return inputList


# validateEq() : validates the equation(only checks the characters for now)
# input: list of characters from the equation
# output: True if the eq is valid, False if not 
def validateEq(inputList):
    counter = 0
    # the operatorList and numberList are the characters allowed
    # anything except these two will be denied and asked for again
    operatorList = ["+","-","*","^","/","(",")"]
    numberList = ["0","1","2","3","4","5","6","7","8","9"]
    inputValid = False
    for i in range(len(inputList)):
        if inputList[i] in operatorList or inputList[i] in \
numberList:
            counter += 1
    # returns true if input is valid, and false if not 
    if counter == len(inputList):
        inputValid = True
    return inputValid 


# addOperator(): adds the operator 
# input: char, opStack, inputStack, valueStack 
# no output really(prints stuff) 
def addOperator(char, opStack, valueStack, inputStack):
    # also THE CURRENT INPUT PRIORITY 
    charNum = INPUT_PRIORITY[char]
    # This if statement makes sure that there are two values in the inputStack 
    # that can be calculated
    if ((len(valueStack)) > 2):
            # if the preInputPriority is smaller, popAndProcess
        while(top(inputStack) < charNum):
            popAndProcess(opStack,valueStack,inputStack)
            # if the preInputPriority is equal to, popAndProcess
        if(top(inputStack)== charNum):
                popAndProcess(opStack,valueStack,inputStack)
            # if greater do nothing, the values just get add on
            # in the next few lines of code
        if(top(inputStack) > charNum):
            pass
    # adding to opStack
    print(char, " was added to opStack")
    push(opStack, char)
    # adding to inputStack
    print(charNum, " was added to inputStack") 
    push(inputStack, charNum)
    return 


# popAndProcess(): once the end of equation is reached the values left in the 
#                  stacks are taken out one-by-one and added/subtracted/
#                  divided/multiplied 
# input: opStack, valueStack, inputStack
# just like the operator does not really return anyhting (prints stuff)
def popAndProcess(opStack, valueStack, inputStack):
        # popping teh operator
        operator = pop(opStack)
        # popping the inputStack
        i = pop(inputStack)
        # number 2 is popped before number 1 
        number2 = pop(valueStack)
        number1 = pop(valueStack)
        try:
            if operator == "+":
                answer = number1 + number2
            elif operator == "-":
                answer = number1 - number2
            elif operator == "/":
                answer = number1 / number2
            elif operator == "*":
                answer = number1 * number2
            elif operator == "^":
                answer = number1 ** number2
            elif operator == "%":
                answer = number1 % number2
            print("new answer being placed into the VALUE stack is:",answer)
            push(valueStack,answer)
            print(top(valueStack))
        # Error checking if the equation has correct characters, but in the 
        # flase order 
        except ValueError:
            print("ERROR: Unable to solve equation")
        except TypeError:
            print("ERROR: Unable to solve eqaution")
        except UnboundLocalError:
            print("ERROR: Unable to solve equation")
        return 


# addValue() takes in the char as a float and valueStack, then adds the values 
#            to the stacks accordingly 
# input: valueStack, character
# output: none really again lol (modified stacks)
def addValue(char, valueStack):
    # adding a value to teh valueStack
    print("adding a value to valueStack")
    push(valueStack,char)
    return 


# DON'T FORGET TO COPY STACKS.PY AND THEN THE IMPORT STATEMENT 
def main():
    
    #DECLARING VARIABLE 
    opStack = []
    valueStack = []
    inputStack = []
    isNumber = False 
    inputList = []
    
    # GREETING 
    printGreeting()
    
    # program runs until inputList returns true(when the program quits)
    while(inputList != True):
    #INITIALIZING STACKS 
        initializeStacks(opStack,valueStack,inputStack) 
        
        inputList = getInput(inputList)
        if inputList != True:
            # equaiton length, so go throughs every character
            eqLen = len(inputList) 
            # this helps change character spot in the eqaution
            char = 0
            # go through the whole equation
            while(eqLen != 0):
                print("looking at ", inputList[char] , " in the equation")
                # checking if the character is a number
                # if it is set as a float and tell that it is a number
                try: 
                    inputList[char] = float(inputList[char])
                    isNumber = True 
                except ValueError:
                    # do nothing basically
                    pass
                # if the cahracted is an operator or (
                if inputList[char] != ")" and isNumber == False:
                    addOperator(inputList[char],opStack,valueStack,inputStack) 
                # if the character is )
                elif inputList[char] == ")":
                    print("pop and process, found a )")
                    # if there are no ( before ), tell there is an error
                    if "(" in opStack:
                        while top(opStack) != '(':
                            # pop and process till ( if nothing is wrong
                            popAndProcess(opStack,valueStack,inputStack)
                        # making sure we pop the (
                        i = pop(opStack)
                        # this checks if (( are together, if true then print 
                        # error
                        if top(opStack) == "(":
                            print("ERROR: unable to solve equation")
                    else:
                        print("ERROR: Enable to solve equation")
                # if the character is a number just add the value to the 
                # valueStack 
                elif isNumber == True:
                    addValue(inputList[char], valueStack)
                # INCREMENTING THEM TO 
                # stop the loop once every character is checked
                eqLen -= 1    
                # go to the next character
                char += 1
                # so that the next time it checks it does not have the same 
                # result as the previous one
                isNumber = False
            # if there are any more elements in opStack, finish it up 
            while top(opStack) != '$':
                print("END OF EQUATION. So pop and process until $")
                popAndProcess(opStack,valueStack,inputStack)
            # making sure that the three stacks are set empty again
            # if the user decides to run again 
            opStack = []
            valueStack = []
            inputStack = []
                
main()
