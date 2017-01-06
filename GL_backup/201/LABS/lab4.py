# file : lab4.py 
# name : Neh Patel 
# date : 9/26/2013
# section : 17
# email : npatel10@umbc.edu 
# description : lab 4 , cipher. Encoding/Decoding a string.
#               use this as example for our homework in a few weeks!

def main():

    SHIFT = 13
    newString = ""
    # input 

    yourString = input("Enter a string: ")
  
    #process  
    string = yourString.upper()
    for character in string: 
        if character != ' ':
           asciiValue = ord(character)
           asciiValue = asciiValue + SHIFT 
           if asciiValue > 90:
              asciiValue = asciiValue - 26
           character = chr(asciiValue)
           newString = newString + character  
    
    #output 
    print(newString)

main()
