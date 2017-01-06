
def printGreeting():
    print("Wassup cuz")

def readFile(filename):
    exam = {} 
    tempList = []
    inFile = open(filename,"r")
    for line in inFile:
        tempList = line.strip().split()
        exam[tempList[0]] = tempList[1]
    return exam 

def findMean(scores):
    total = 0
    average = 0
    counter = 0
    for i in range(len(scores)):
        total += int(scores[i])
        counter += 1
    average = total / counter 
    return average

def main():
    exam = {}
    filename = ""
    average = 0
    printGreeting()
    filename = input("input file name: ")
    exam = readFile(filename) 
    score = list(exam.values())
    score.sort()
    average = findMean(score)
    lowest = score[0]
    length = len(score) - 1
    highest = score[length]
    print("The average score is ", average)
    print("Lowest Score is : ", lowest)
    print("Highest score is: ", highest)
main()
