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

Total time (part 2): 0:40

# Collaboration
N/A

# Discussion
I had a lot of little issues here that took a long time to fix. My sorting algorithm wasn't looping correctly, the insert function was looping indefinitely until it crashed, and other issues like these. These types
of issues ended up coming down to a very small error, but fixing them was difficult. Working with opaque structs helped me to understand them better, both in how to work with them and why they are useful. I followed
along in class, but actually working with them deepened my understanding of them, and I now feel that I can actually use them.