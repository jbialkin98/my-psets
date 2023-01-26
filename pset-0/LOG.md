# Author
Josh Bialkin
jsb245

# Estimate of time to complete assignment
2 hours

# Actual time to complete assignment
| Date | Time Started | Time Spent | Work completed |
| :--: | -----------: | ---------: | :------------- |
| 1/25 |       1:30am |       0:30 | created functional program |
| 1/25 |     10:40pm |        0:30 | implemented make file, fixed code, and finished LOG

# Collaboration
None

# Discussion
One issue I ran into while completing this assignment was printing names with spaces in them. I solved this issue by using "%[\n]s" in my scanf implementation, because this looks for the end of the input rather than whitespace. I also had an issue where the program would sometimes not show a new line character after succesfully executing, and I fixed this by adjusting the position of "return 0" to the bottom of my main function.

Another adjustment I needed to make in my code was the size of "char name". Originally, I implemented it with a size of 128, but after discussing the null char at the end of a string in class, I changed the length of name to 129 to allow for a 128 character name. 