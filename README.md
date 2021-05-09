# Friend Book

A Friends Recommendation System

## How to Compile

To compile the code run the command "gcc *.c" in your terminal.

You can run the executable file to run the program

## Commands

- [1] Register a new user
- [2] Unregister an existing user
- [3] Recommend friends to existing user
- [4] Add friend to existing user
- [5] Check friendship status
- [6] Print user details
- [0] Exit

### [1] Register a new user

Type "1" in the terminal to execute this command

Once executed, it provides the minimum positive integer which is not currently in use as ur unique ID

Enter details of user(prompts like "Enter your name: " would be shown)

After registering, recommendations will be shown based on common paramaters, enter "y" to add any friends from the recommendations and "n" to abort

if adding friends, specify the number of friends you would like to add and their user IDs

### [2] Unregister an existing user

Type "2" in the terminal to execute this command

Enter the user ID of the user you wish to unregister

### [3] Recommend friends to existing user

Type "3" in the terminal to execute this command

Enter the user ID of the user you want recommendations for

recommendations will be shown based on friends list, enter "y" to add any friends from the recommendations and "n" to abort

if adding friends, specify the number of friends you would like to add and their user IDs

### [4] Add friend to existing user

Type "4" in the terminal to execute this command

Enter the user IDs of A and B where B will be added as a friend of A.

### [5] Check friendship status

Type "5" in the terminal to execute this command

Enter the user IDs of A and B, function will check whether B is a friend of A or not.

### [6] Print user details

Type "6" in the terminal to execute this command

Enter the user ID of the user whose details need to be printed

### [0] Exit

Type "0" in the terminal to execute this command

Exit the program.

_Note: a test case has been added to the repo with the name testcase.txt, copy the text and paste it in the user interface as an input_

