# file: HW1.py
# author: Neh Patel
# date: September 10, 2014
# email: npatel10@umbc.edu
# description: 
#------------------------------------------------------------------------------

def main():
    # read a text file 
    # take each word or number and figure what it is
    # then accordingly tell
       # all data that are prime number less than 10,000
       # Any three-chracter long data, as long as all the characters are in 
       #        english language 
       # any data that starts with L and ends with letter E 
       # any data that follows a number between 4 and 9 digits long
    # then at the end have the data printed out in an alphabetical order 
    
    # Few Variables 
   # fileName = "" 
    flag = True
    wordsInLine = []
    ListOfWords = [] 
    # keep running until an existing file is the input 
    while(flag):
        try:
            fileName = input("Enter the filename: ")
            #opening the file 
            inFile = open(fileName, "r")
            # set flag to false so that we come out of the loop 
            flag = False
        except IOError:
            print("invalid file name, please try again")
        except NameError:
            print("This is not working for some reason")
    for line in inFile:
         # makes a list of strings for the line only
        wordsInLine = line.split()
        # adds the lines list of string to the entire words list
        ListOfWords = ListOfWords + wordsInLine

    #closing the file 
    inFile.close()
    
    # at this point I have all the words in an array 

main() 
