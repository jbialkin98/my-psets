# Author
Josh Bialkin 
jsb245

# Estimate of time to complete assignment
10 hours

# Actual time to complete assignment
| Date | Time Started | Time Spent | Work completed |
| :--: | -----------: | ---------: | :------------- |
| 2/20 |       5:00pm |       1:00 | read readme and start working on pirate_list.c |
| 2/21 |       2:30pm |       0:45 | add more functions to pirate_list.c |
| 2/21 |       8:00pm |       1:00 | finished basic implementation of functions in pirate_list.c and started hookbook.c. Have errors in pirate_list currently. |
| 2/21 |       9:45pm |       0:30 | went to OH to fix some issues. Changed collection_of_pirates in my implementation struct to type **, which fixed most errors. |
| 2/22 |      12:20pm |       0:20 | started to fix sorting algorithm, switched to using fgets in hookbook |
| 2/22 |      10:00pm |       1:30 | try to fix bug in OH where pirate was being overwritten instead of being added to list. 
                                   | Switched to strcopy rather than using = and malloc space for name of pirate in addition to just the pirate itself |
| 2/23 |      11:00am |       1:00 | work out some bugs and formatting, start to work on sorting algorithm again now that the list is working properly |
| 2/23 |       6:30pm |       2:00 | fixed sorting algorithm and recognized spacing bugs |
| 2/24 |      10:30am |       0:20 | fixed spacing bugs and fixed duplicates inserted in list |
| 2/24 |      12:15pm |       0:20 | fixed insert function bug so it should now allow for elements placed at any index |
| 3/5  |       3:00pm |       1:00 | improve comments and adjust part 1 to style guidelines |

| 3/5  |       5:30pm |       0:40 | go over part 2 README and start implementing strtok to separate string at ":" |
| 3/5  |      10:50pm |       1:00 | create fields in pirate struct and allow program to read them in and add them to the pirate in the list |
| 3/6  |      11:00pm |       1:00 | fix segmentation fault with inserting pirate to list, format the terminal printing of the pirates |
| 3/7  |       2:30pm |       0:30 | start implementing skills for pirates |
| 3/7  |      11:00pm |       1:10 | finish skill functionality, including printing with asterics and sorting. Implement sorting functionality from input argument |
| 3/8  |       8:50pm |       2:40 | finish implementing outputs including captains, program is fully functional and matches test cases. Start working on freeing memory. |
| 3/9  |       2:30pm |       3:00 | correctly free all memory. Added a new file called pirates.c that contains functions for the pirates. Removed functions I improperly added to pirate_list.h and pirate_list.c due to the specification, moving them to either hookbook.c or pirate.c. Added more comments and organized code. Went back to part 1 to make some formatting adjustments due to the specification.

Total time (part 2): 10:00

# Collaboration
N/A

# Discussion
I had a much easier time with part 2 of this pset, even though I took a long time with it. The biggest issue I had was due to my misunderstanding of the specification regarding pirate_list.h. I had previously implemented many functions in the pirate_list.c file, but I could not add functions to pirate_list.h, so I needed to change my code around. While I'm sure there is a much shorter implementation than the one I ended up using, these changes resulted in a much longer main file than I would have liked. 