# file: lab10.py
# name : Neh Patel
# date: 11/7/2013 
# section: 17
# email: npatel10@umbc.edu
# description: printing the calendar 
# ----------------------------------------------------------------------------


# some constants
MIN_YEAR = 1900
MAX_YEAR = 2500
 
SUNDAY = 0
MONDAY = 1
TUESDAY = 2
WEDNESDAY = 3
THURSDAY = 4
FRIDAY = 5
SATURDAY = 6
 
def getValidInt(question, min, max):
# use a bad value to enter the loop
    value = max + 1
# compose the prompt
    prompt = question + " (" + str(min) + "-" + str(max) + "): "
# continue to get values until the user enters a valid one
    while value == "" or value < min or value > max:
        value = input(prompt)
        if len(value) != 0:
            value = int(value)
# return a valid value
            return value

def printCalendar(year):
    for i in range(12):
        printMonth(i,year)
    
def printMonth(monthNum,year):
    monName = ""
    monName = monthName(monthNum)
    print(monName, " " , year)
    print(" Su Mo Tu We Th Fr Sa")
    weekday = firstDayOfMonth(monthNum,year)
    indentFirstLine(weekday)
    numOfDays = daysInMonth(monthNum,year)
    for day in range(1, numOfDays + 1):
        print("%2d " % (day), end = '')
        if weekday == SATURDAY:
            print("\n")
        weekday = (weekday + 1) % 7
    if weekday != SUNDAY:
        print("")
    return

def monthName(monthNum):
    name = "October"
    return name

def firstDayOfMonth(monthNumber,year):
    weekdaynumber = 4
    return weekdaynumber

def indentFirstLine(weekdayNumber):
    lineIndent = ""
    weekDayNumber = 4
    for i in range(weekdayNumber):
        lineIndent = "   " + lineIndent 
    print(lineIndent, end = "")
    
def daysInMonth(monthNumber,year):
    numOfDays = 30
    return numOfDays

def main():
 
#    printGreeting()
 
    year = getValidInt("Which year would you like? ", MIN_YEAR, MAX_YEAR )
    printCalendar(year)
 
main()
