# file: lab5.py
# author: Neh Patel
# date: 10/3/2013
# section : 17
# email : npatel10@umbc.edu
# description : this program determines whether a number is perfect or not 
  



def main():

#   declaring variables    
    total = 0
    divisor = 0
    flag = True 
    num = 0

#   input 
    while (flag):
         try:
           
             num = int(input("Enter a number that is not a decimal, and greater than 0:"))        
             if num > 1:
                   flag = False
             else: 
                   print("input was invalid. Please try again")
         except ValueError:
                print("numbers only please")
         except NameError:
                print("numbers only please") 
      
    
    
#   process
    for i in range(1,num): 
       divisor = num % i
       if divisor == 0:
          total = i + total
       
     
#   output 
    if total == num: 
       print("The number you entered is a perfect number")
    else:
       print("The number is not a perfect number")

main()
