# file: lab7.py
# author : neh patel
# date: 10/17/2013
# section: 17
# email : npatel10@umbc.edu
# description: this lab only has a couple of functions added to it which 
#              help calculate the total score for a students grades  
FILE_LEN = 26
LAB_POINTS_POSSIBLE = 36

def finalLabScore(rawLabScore):
    rawLabScore = rawLabScore[FILE_LEN-1]  
    rawScore = (rawLabScore * 100)/LAB_POINTS_POSSIBLE
    return rawScore

def findCourseScore(courseDataList):
    i = 0
    grade = 0
    score = 0 
    while(i < FILE_LEN - 2):
        weight = courseDataList[i]
        i = i+1
        grade = courseDataList[i]
        i = i+1
        score += grade * weight 
    score += finalLabScore(courseDataList)
    return score 

def findLetterGrade(courseScore):
    if courseScore >= 90.0:
        letterGrade = "A"
    elif courseScore >= 80.0:
        letterGrade = "B"
    elif courseScore >= 70.0:
        letterGrade = "C"
    elif courseScore >= 60.0:
        letterGrade = "D"
    else:
        letterGrade = "E"
    return letterGrade


def main():
    
    # DO NOT CHANGE MAIN!!
    # DO NOT CHANGE MAIN!!

    # courseDataList needs to be initialized
    courseDataList = []
    

    #gather name, which is the first item on Lisa.txt
    name = input()

    #create a list from the file Lisa.txt
    for i in range(FILE_LEN):
        
	 #grab the rest of the values from the file and place into my list
         courseDataList.append(float(input()))

    courseScore = findCourseScore(courseDataList)

    letterGrade = findLetterGrade(courseScore)

    print("%s: %.2f - %c" % (name, courseScore, letterGrade))

main()
