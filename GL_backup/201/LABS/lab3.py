# File: lab3.py
# Author: Neh Patel
# Date: 9/19/2013
# Section: 17
# Email: npatel10@umbc.edu
# Description: Lab 3, i/o and Math Operation 

def main():
    
    #declaring variables 
    number1 = 0
    number2 = 0
    number3 = 0
    total = 0

    #3 input values
    # the int in fornt of tghe input cast the string into a number  
    number1 = int(input("Enter the first integer value: "))
    number2 = int(input("Enter the second integer value: "))
    number3 = int(input("Enter the third integer value: "))

    #process 
    number1 = number1 ** 2
    total = number2 + number3
   
    # output 
    print("The first value squared is ", number1)
    print("The second and third value added equal: " , total)

main()
