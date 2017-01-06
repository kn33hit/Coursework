# file: hw8.py
# author: Neh Patel 
# date: 11/6/2013
# section: 17
# email: npatel10@umbc.edu 
# description: reads a cipher file, then a regular file. And according to the 
#              user input in the main menu converts the reuglar file into a 
#              translated file from the cipher file. also lets the user choose 
#              whichever file they want to display 
#------------------------------------------------------------------------------

# printGreeting(): prints the greeting, the main menu basically 
# no input or output 
def printGreeting():
    print("This is a cipher program")
    print("a.) load cipher input (to be used later)")
    print("b.) convert regualr text to ciphered (cipher MUST be loaded)")
    print("c.) display cipher to screen") 
    print("d.) display regular text to screen")
    print("e.) display current results.txt to screen")
    print("f.) Quit")


# validateFileLength(): validates and checks if the cipher file is 26 lines 
#                       long 
# input: none
# output: list if the cipher file is 26 line long and false if not  
def validateFileLength():
    cipherList = []
    numOfLine = 0
    cipher = open("cipher.txt" , "r")
    for line in cipher:
        # to count the number of lines
        if line[0].isalpha() == True:
            numOfLine += 1 
        line= line.strip()
        # appended a line from the file to the cipherList
        cipherList.append(line)
    if numOfLine == 26:
        return cipherList
    else:
        cipher.close()
        return False 
    

# validateCipher(): validates and checks if the cipher has some letters that 
#                   repeat
# input:
# output: returns true if repeated, and false if file is good
def validateCipher(cipherList):
    listOfCipherOnly = []
    splitStringList = []
    for i in range(len(cipherList)):
        splitStringList = cipherList[i].split()
        if splitStringList[1] in listOfCipherOnly:
            print("The cipher has repetitive letters")
            return True
        else:
            listOfCipherOnly.append(splitStringList[1])
    return False

# printResults(): prints the results from the results file  
# no input or output
def printResults():
    inFile = open("results.txt","r")
    for line in inFile:
        print(line.strip())
    inFile.close()
    return 

# printCipher(): prints the cipher 
# input: list of ciphers made from the cipher file 
# no output
def printCipher(cipherList):
    for i in range(len(cipherList)):
        print(cipherList[i], "\n")

# printRegularTextFile(): prints the regualr text file the user wants to modify
# no input or output
def printRegularTextFile():
    fileName = ""
    flag = True 
    while(flag):
        try:
            fileName = input("What regular file would you like to display: ")
            inFile = open(fileName, "r")
            flag = False
        except IOError:
            print("Sorry, file not found.")
        except FileNotFoundError:
            print("Sorry, file not found") 
    for line in inFile:
        print(line.strip())
    inFile.close()
    return

# convertToCipher(): converts the regualr file using the cipher file and
#                    creates a new file with the translation
# input: list of ciphers made from the cipher file 
# output: a file with translated text of the regular file using the cipher file
def convertToCipher(cipherList):
    flag = True
    isAlpha = False
    fileName = ""
    stringLine = ""
    letter = ''
    finalString = ""
    letterIndex = 0
    onlyCipherList = []
    
    #opened the results file
    outFile = open("results.txt" , "w")
    
    #opening the file that the user wants to convert 
    while(flag):
        try:
            fileName = input("Please enter the name of the file you wish to \
open for CONVERSION: ")
            inFile = open(fileName, "r")
            flag = False
        except IOError: 
            print("invalid file name, please try again")
        except FileNotFoundError:
            print("invalid file name, please try again")
    
    for i in range(len(cipherList)):
        splitString = cipherList[i].split()
        onlyCipherList.append(splitString[1])

    for line in inFile: 
        for i in range(len(line)):
            isAlpha = line[i].isalpha()
            if isAlpha == True:
                upperOrLower = ord(line[i])
                letter = line[i].upper()
                letterIndex = ord(letter) - 65
                for j in range(len(onlyCipherList)):
                    if j == letterIndex:
                        if upperOrLower > 96:
                            finalString += onlyCipherList[j].lower()
                        else:
                            finalString += onlyCipherList[j]
            else:
                finalString += line[i]
    outFile.write(finalString)
    outFile.close()
    inFile.close()
    return 
 


def main():
    #DECLARING VARIABLES 
    menuOptions = ["a","b","c","d","e","f"]
    flag = True
    menuInput = ""
    optionASelected = False
    noDuplication = True
    
    while(menuInput != "f"):
        printGreeting()
        #INPUT FOR MENU
        menuInput = input("Enter a menu option: ")
        #validation
        while(flag):
            menuInput = menuInput.lower()
            if menuInput in menuOptions:
                flag = False
            else:
                menuInput = input("Invalid menu option. Enter again: ")
        
        #OPTION A
    
        if menuInput == "a":
            # to make sure option a was selected before optinn b
            cipherList = validateFileLength()
            if cipherList != False:
                optionASelected = True
                print("cipher loaded, thank you")
            else:
                print("the file is not 26 lines long")
        
        # OPTION B 
        elif menuInput == "b":
            if optionASelected == True:
                noDuplication = validateCipher(cipherList)
                if noDuplication == False: 
                    newFile = convertToCipher(cipherList)
                    print("File converted, please check results.txt for your \
encrypted file")
            else:
                print("You need to load the cipher first. choose option A \
first")
        
        #OPTION C
        elif menuInput == "c":
            if optionASelected == True:
                printCipher(cipherList)
            else:
                print("You need to load the cipher first")

        #OPTION D
        elif menuInput == "d":
            printRegularTextFile()
        
        #OPTION E
        elif menuInput == "e":
            printResults()
            
        # don't need option F since the while loop is running on the menuInput 
        # not being option F 
        # if option F was selected the loop will stop
            
main()
