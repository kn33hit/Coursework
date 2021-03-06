# lab12.py
# Neh Patel
# 11/12/2103
# Section 17
# npatel10@umbc.edu
#-----------------------------------------------------------------------------

import sys
import string

# getListOfStrings() opens a file, reads each line of the file, strips
# any leading or trailing whitespace, creates a list of the strings,
# closes the file and returns the list of strings
#
# Input:  the name of the file to open
# Output: the list of strings read from the file
def getListOfStrings(filename):

    origList = []
    infile = open(filename, 'r')
    
    for line in infile:
        myStr = line.strip()
        origList.append(myStr)

    infile.close()
    return origList

# purgeString() takes a string and makes a new string which has been
# purged of all the non-alphabetic characters.  The purged string is
# in all capitals
#
# Input:  a string
# Output: an all-caps string of letters that were in the string passed in
def purgeString (myStr):

    purged = ''
    
    myStr = myStr.upper()

    for ch in myStr:
        if(ch >= 'A' and ch <= 'Z'):
            purged = purged + ch
    
    return purged

# isPalindrome() determines whether the string passed in is a palindrome.
# This is a recursive function.
#
# Inputs: tempStr, the all-caps, purged string
#         left, the left index
#         right, the right index
# Output: True or False
def isPalindrome (word, left, right):

#    print("This is a stub for isPalindrome() and it returns True")
#    return True
    leftSide = word[left]
    rightSide = word[right]
    if left > right:
        return True
    if leftSide == rightSide:
        return isPalindrome(word, left+1, right-1)
    else:
        return False



def main():
    strPalindrome = False

    # find number of command-line arguments
    if len(sys.argv) == 2:
    # if the number is not correct print instructions
    # for running the program and exit
        inFileName = sys.argv[1]



    # call getListOfStrings to get the origList
        origList = getListOfStrings(fileName)


        print("The palindromes in the file are:")

    # for each of the strings in origList
        for i in range(len(origList)):
        # make a tempStr by calling purgeString()
            tempStr = purgeString(origList[i])
        # tempStr will be in all uppercase with non-letters removed


        # determine if tempStr is a palindrome by calling isPalindrome()
            strPalindrome = isPalindrome(tempStr,0, (len(tempStr)-1))
            # if it is, print the original string tempStr was made from
            if strPalindrome == True:
                print("%s is a palindrome" % (origList[i]))
            else:
                print("%s is not a palindrome" %(origList[i]))
    else:
        print("Need to have two arguments in the command-line \
for example: python lab11.py strings.dat")

main()
