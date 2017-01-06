# file : lab6.py
# author : Neh Patel
# date : 10/10/2103
# section: 17 
# email : npatel10@umbc.edu
# description : validates a password entered by the user 

def main():
    validInput = False
    valid = False
    asciiVal = [48,49,50,51,52,53,54,55,56,57]
    # 48 - 57 ( ascii value for 0-9)made a list to compare in the for loop
    
    while(not validInput):
        password = input("Enter your password: ") 
        # checks the !,.,? error 
        if "!" in password:
            print("Error cannot have '!'")
            validInput =  
        if "." in password:
            print("Error cannot have '.'")
            validInput = True
        if "?" in password:
            print("Error cannot have '?'")
            validInput = True
        
        #checks if there is a number in the password
        for char in password:
            if ord(char) in asciiVal:
                validInput = True
        if hasNum == False:
            print("You should at least have 1 number")
        
        # checks for the length of the password 
        if len(password) < 5:
            print("Less than 5 characters")
        else:
            validInput = True
           
    if validInput == True:
       print("The password is correct")
                  

main()
