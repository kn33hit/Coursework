# file : lab8.py 
# author : Neh Patel 
# date : 10/24/2013 
# section : 17 
# email : npatel10@umbc.edu 
# description : inventory fo snacks 


# greeting() : only prints a line 
def greeting():
    print("Welcome to the vending machine")

# getValidInt : check if the value is between 1 and 9 for item 
#               and 1 and  for the amount and keeps prompting 
#               the user plugs in the correct value 
# input : a string, and the item index and amount 
# output : just returns the values
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

# displayInventory : displays the inventory by calling the other disploay 
#                    functions
# input : list created or updated    
def displayInventory(list1, item, amount): 
# the if function make sure a certain spot is called for and calls the 
# function accordingly 
    if item >= 1 and item <= 3:
        displayDrinks(list1,amount)
    if item >= 4 and item <= 6:
        displayCutlery(list1,amount)
    if item >= 6 and item <= 9:
        # this one is the only one that still needs the item to be passed 
        # since it has more subdivisiosn into it 
        displaySnacks(list1,item,amount)

# displayDrinks : displays the drinks 
# input : list and the amount of drinks ordered 
# output : returns the new modified list index assigned for the drinks 
def displayDrinks(list1,amount):
    return 


# displayCutlery  : displays the cutlery
# input : list and the amount of cutlery ordered 
# output : returns the new modified list index assigned for the cutlery  
def displayCutlery(list1,amount):
    return


# displayDrinks : displays the chips and gums and calls their functions
# input : list and the amount of chips and gums ordered 
# output : returns the new modified list index assigned to chips and gums 
def displaySnacks(list1,item,amount):
    if item == 7 or item == 8:
        displaChips(list1,amount)
    else:
        displayGum(list1,amount)
    return
 
# displayChips : displays the Chips  
# input : list and the amount of chips ordered 
# output : returns the new modified list index assigned for the chips 
def displayChips(list1,amount):
    return 

# displayChips : displays the gums  
# input : list and the amount of gums ordered 
# output : returns the new modified list index assigned for the gums 
def displayGum(list1,amount):
    return 


def changeInventory(list1, option, amount):
    list1[option] = list1[amount]
    

def main():
    list1 = [5,5,5,5,5,5,5,5,5]
    greeting()
    item = getValidInt("Please enter option",1,9)
    amount = getValidInt("Please enter the amount to buy",1,5)
    changeInventory(list1, item, amount)
    displayInventory()

main()
