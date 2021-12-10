# COMP-2710-Software-Construction
# AUBURN CS/SE STUDENTS - DO NOT LOOK AT THIS. This Repo is for my personal storage and showcase. You learn nothing from cheating and it will only hurt you in the long run.


Project 1: You have just purchased a stereo system that cost $1000 on the following credit plan: no 
down  payment,  an  interest  rate  of  18%  per  year  (and  hence  1.5%  per  month),  and 
monthly payments of $50. The monthly payment of $50 is used to pay the interest, and 
whatever is left is used to pay part of the remaining debt. Hence, the first month you pay 
1.5% of $1000 in interest. That is $15 in interest. The remaining $35 is deducted from your 
debt, which leaves you with a debt of $965.00. The next month you pay interest of 1.5% 
of $965.00, which is $14.48. Hence, you can deduct $35.52 (which is $50–$14.48) from 
the amount you owe.
 
Write a program that will tell you how many months it will take you to pay off this loan in 
particular and any loan in general. Your program also needs to calculate the total amount 
of interest paid over the life of any loan. Use a loop to calculate the amount of interest 
and  the  size  of  the  debt  after  each  month.  Your  program  must  output  the  monthly 
amount of interest paid and remaining debt. Use a variable to count the number of loop 
iterations and hence the number of months until the debt is zero. You may want to use 
other variables as well. The last payment may be less than $50 if the debt is small, but do 
not forget the interest. If you owe $50, then your monthly payment of $50 will not pay 
off your debt, although it will come close. One month’s interest on $50 is only 75 cents.
Grade: 100/100


Project 2: In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument over which one of 
them was the greatest puzzle-solver of all time.  To end the argument once and for all, 
they agreed on a duel to the death (this makes sense?). Aaron was a poor shooter and 
only hit this target with a probability of 1/3. Bob was a bit better and hit his target with 
a probability of 1/2. Charlie was an expert marksman and never missed. A hit means a 
kill and the person hit drops out of the duel. 
 
To compensate for the inequities in their marksmanship skills, the three decided that 
they would fire in turns, starting with Aaron, followed by Bob, and then by Charlie. The 
cycle would repeat until there was one man standing. That man would be remembered 
for all time as the Greatest Puzzle-Solver of All Time. 
 
An obvious and reasonable strategy is for each man to shoot at the most accurate 
shooter still alive, on the grounds that this shooter is the deadliest and has the best 
chance of hitting back. 
 
Write a program to simulate the duel using this strategy. Your program should use 
random numbers and the probabilities given in the problem to determine whether a 
shooter hits his target. You will likely want to create multiple functions to complete the 
problem. My solution had only one function to simulate the duels and it passed in the 
odds and the three guys as pass-by-reference parameters.  Once you can simulate a duel, 
add a loop to your program that simulates 10,000 duels. Count the number of times that 
each contestant wins and print the probability of winning for each contestant (e.g., for 
Aaron your might output "Aaron won 3612/10000 duels or 36.12%).  
 
Strategy 2: An alternative strategy for Aaron is to intentionally miss on his first shot. 
Write a function to simulate Strategy 2. Your program will determine which strategy is 
better for Aaron.
Grade: 100/100

Project 3: Write a program that merges the numbers in two files and writes all the numbers into a 
third file. Your program takes input from two different files and writes its output to a 
third file. Each input file contains a list of numbers of type int in sorted order from the 
smallest to the largest. After the program is run, the output file will contain all the 
numbers in the two input files in one longer list in sorted order from smallest to largest.
Grade: 97/100

Project 4: In	this	homework	assignment,	you	will	write	a	simple	trivia	quiz	game.	Your program	first	allows	
players	to	create	their	trivia	questions	and	answers.	Multiple	questions	should	be	organized	and	
managed	 using	a	linked	 data	 structure;	 no	array	is	allowed	in	 this	 homework	assignment.
Then,	your	program	asks	a	question	 to	 the	player,	input	 the	player’s	answer,	and	check	if	 the	
player’s	answer	matches	 the	actual	answer.	If	 so,	award	the	player	 the	award	points	 for	 that	
question.	If	the	player	enters	the	wrong	answer	your	program	should	display	the	correct	answer.	
When	all	questions	have	been	asked, display	the	total award	points that	the	player	has	won.
Grade: 100/100

Project 5: Read the source code and the rest comments, try to understand the function of each line of code, 
the basic usage of `pthread` library function and semaphore from the example code of producer 
and from the main function. 
Follow the instructions in the comments and insert proper code into the rest 7 blocks to implement 
a producer/consumer model.  
Grade: 100/100
