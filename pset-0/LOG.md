# Author
Josh Bialkin
jsb245

# Estimate of time to complete assignment
2 hours

# Actual time to complete assignment
| Date | Time Started | Time Spent | Work Completed |
| :--: | -----------: | ---------: | :------------- |
| 1/25 |       1:30am |       0:30 | created functional program
| 1/25 |      10:40pm |       0:30 | implemented make file, adjusted code, and updated LOG
| 1/26 |       9:00pm |       1:00 | made program stop if no name was entered

Total time spent:
2 hours

# Collaboration
None

# Discussion
One issue I ran into while completing this assignment was printing names with spaces in them. I solved this issue by using "%[\n]s" in my scanf implementation, because this looks for the end of the input rather than whitespace. I also had an issue where the program would sometimes not show a new line character after succesfully executing, and I fixed this by adjusting the position of "return 0" to the bottom of my main function.

The biggest issue I had was making the program not print "Hello, " when there was no name entered. I solved this by including an if statement with the implementation of scanf. I had trouble realizing that scanf returns the number of arguments included, so once I understood that, I made the program execute if there were more than 0 inputs.