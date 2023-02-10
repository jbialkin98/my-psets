# Author
Josh Bialkin 
jsb245

# Estimate of time to complete assignment
4 hours

# Actual time to complete assignment
| Date | Time Started | Time Spent | Work completed |
| :--: | -----------: | ---------: | :------------- |
| 2/07 |       2:40pm |       1:20 | read README and assembled project files. Got user inputs in main.c and printed initial line after the inputs |
| 2/07 |      10:30pm |       1:30 | Added functions to life.c |
| 2/08 |      10:00pm |       2:00 | Got program working, began working on input checks and failsafes |
| 2/09 |       6:00pm |       1:30 | Finished failsafes, fixed bugs, tested code. Added more comments and made code more readable |
| 2/10 |       3:00pm |       1:00 | Fixed problem where the array wasn't printing on line 34 |

Total time: 7:20

# Collaboration
N/A

# Discussion
The biggest obstacle I faced in this pset was understanding how the game worked itself. I should have started with more pseudocode rather than just jumping right into programming something I didn't fully understand. When I finally did understand it, I could understand why I was experiencing some bugs. Most of this came from my advanceTime function, where I was not using the isAlive and shouldDie functions to their maximum usefulness. I needed to restructure this a few times to cut down on conditional statements and make the program more readable.

I also started with most of my logic in my main.c function, so everything became easier to read and work with when I started separating out the functions in my life.c file, resulting in a cleaner main file.