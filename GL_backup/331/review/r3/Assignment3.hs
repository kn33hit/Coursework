{- |
Assignment Name:  Assignment #3
Group Names    :  Person A, Person B, Person C, Person D
Date           :  10/7/2014
-}

import System.IO --Included for user input and output
import Data.List -- Included for permutations
import Data.List.Split.Internals --Included for split

--Main entry point for the program
main = do
    numStudents <- getInteger "Enter the number of students: "
    groupSize <- getInteger "Enter the maximum group size: "
    --Check if the number of students can break into groups of size groupSize evenly
	
	--(NP) I thought the citations were supposed to be formatted to 
	--(NP)MLA format citation?
	
	-- `div` vs \ from http://stackoverflow.com/questions/14656762
    if rem numStudents groupSize == 0 && (numStudents `div` groupSize) > groupSize
    	then do


	--(NP) Did a fairly decent job with explanations on what line is
	--(NP) doing what. 
	--(NP) still looks very complext and annoying to read. 
	--(NP) Maybe spacing out would've worked its charm.


    		--Assigns the output of the easy sort algorithm which generates combinations of students,
    		--inputting a list of the students represented by integers 1-numStudents
    		let projectGroups = easySort [1..numStudents] numStudents groupSize 0 []
    		let projectsList = ["Assignment 1","Assignment 2","Assignment 3","Midterm","Assignment 4","Assignment 5","Assignment 6","Final Exam"]
		
		--(NP) explain what exactly the next line would do. 
		--(NP) Like how Haskell woudl be able to read this and how. 
		--(NP) Is the list of things listed a function or a list
		--(NP) tell the reader which name is a function or data. 
		--(NP) And what it is used for,
		--(NP) also mention why the zero was included  

    		--Print the projects and a group to go with them
    		outputProjectGroup 0 projectGroups projectsList groupSize
    	--If not end early
		else do
			putStrLn ("Cannot pair up " ++ show numStudents ++ " students into groups of " ++ show groupSize ++ " across eight assignments")

-- == Utility functions for handling integers========
--isInteger function to determine input from http://rosettacode.org/wiki/Determine_if_a_string_is_numeric

 --(NP) what in the living world is the next line doing? 
 --(NP) Again explain the reader what the function 
 --(NP) is taking in and outputting or returning. 

isInteger s = case reads s :: [(Integer, String)] of
  [(_, "")] -> True
  _         -> False

-- Takes in a prompt to display to the user before getting their input
getInteger :: String->IO Integer
getInteger getPrompt = do
	putStrLn getPrompt
	userInput <- getLine
	--Validate that input is an integer
	if isInteger userInput
		then do
			--If input is an integer, cast it from a string to an Integer and return
			return (read userInput :: Integer)
		else do
			--If not an Integer, alert the user and repeat
			putStrLn "Invalid input. Must enter an integer!"
			getInteger getPrompt

-- ==Functions for modifying the base student list ========
--This function is exists to go with the map function and create a modified version of the student list so that it
--varies for each project

	 -- (NP) Again need to tell the reader how each one of the integer
	 -- (NP) passed in would affect the functino outcome.
	 -- (NP) Also need give the range of number the Integers that are 
	 -- (NP) passed in, can be between.

modifyStudentList :: Integer->Integer->Integer->Integer->Integer
modifyStudentList iteration numStudents groupSize listEntry = do
	
	-- (NP) Here the reader is supposed to understand the code thoroughly  
	-- (NP) So, according to some Haskell coding conventions for beginners 
	-- (NP) you should be using more of where-bindings, rather than 
	-- (NP) let-bindings. 

	let entryIndex = rem listEntry groupSize
	--Changing the entry to a new number based on its index and the current iteration
	let updatedEntry = listEntry + (entryIndex * iteration * groupSize)
	--Adjusting the number if it is outside of the range of students
	if updatedEntry <= numStudents
		then updatedEntry
		else rem updatedEntry numStudents

--(NP) Again I can't tell what the coder is passing in would be used for 
--A sort for when there are at least eight groups per project
easySort :: [Integer]->Integer->Integer->Integer->[[Integer]]->[[Integer]]
easySort baseList numStudents groupSize iteration allProjectGroups =
	if length allProjectGroups == 8
		then allProjectGroups
		else do
			let newProjectGroup = map (modifyStudentList iteration numStudents groupSize) baseList

			--(NP) why call this now, what arguments you're  
			--(NP) passing in. 
			--(NP) Also what you expect from this fucntion
			easySort baseList numStudents groupSize (iteration+1) (newProjectGroup:allProjectGroups)

--Print the project to output
outputProjectGroup projectNumber projectGroups projectsList groupSize =
	if projectNumber < 8
		then do
			--Split logic from http://hackage.haskell.org/package/split-0.2.1.1/docs/Data-List-Split.html
			let splitGroup = chunksOf (fromIntegral groupSize) $ (projectGroups!!projectNumber)
			let project = projectsList!!projectNumber
			print (project ++ ": " ++ (show splitGroup))
			outputProjectGroup (projectNumber+1) projectGroups projectsList groupSize
		else return()

{-./al3
Enter the number of students:
20
Enter the maximum group size:
4
"Assignment 1: [[9,18,7,4],[13,2,11,8],[17,6,15,12],[1,10,19,16],[5,14,3,20]]"
"Assignment 2: [[5,10,15,4],[9,14,19,8],[13,18,3,12],[17,2,7,16],[1,6,11,20]]"
"Assignment 3: [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16],[17,18,19,20]]"
"Midterm: [[17,14,11,4],[1,18,15,8],[5,2,19,12],[9,6,3,16],[13,10,7,20]]"
"Assignment 4: [[13,6,19,4],[17,10,3,8],[1,14,7,12],[5,18,11,16],[9,2,15,20]]"
"Assignment 5: [[9,18,7,4],[13,2,11,8],[17,6,15,12],[1,10,19,16],[5,14,3,20]]"
"Assignment 6: [[5,10,15,4],[9,14,19,8],[13,18,3,12],[17,2,7,16],[1,6,11,20]]"
"Final Exam: [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16],[17,18,19,20]]"
-}


-- (NP) FINAL REVIEW COMMENTS 
   
   -- should usually have less than 80 characters in a line. So it is more readable. There were a few spots
   -- that need to fixed 

   -- A little bit of too much let-bindings. Should've used a little bit more 
   -- of where-bindings

   -- When the functions were declared should've spaced out between 
   -- arguments that are taken in. It would've given it more clarity 

   -- Haskell is a very complex language to learn(at least in my eyes).
   -- So every time you used certain variables that are  arguments being 
   -- passed into a function. A nice little comment of what was being 
   -- passed in and what outcome was expected of it. Would've made the code 
   -- even more readable. 

   -- Otherwise: Decent comments. Good use of indentations. Decently readable.
   -- Could've done a lot better with comments and spacing. Especially spacing.
   -- When I say spacing, I mean between parameters in function headers, 
   -- Also not using new line\
   efficiently.(See what I did there). Gives some good clarity and 
   -- makes one not hate reviewing Haskell code. 
