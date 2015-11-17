##Skycast

Gaurav is a 12 year old student who’s fractured his leg and lower back in a bicycle accident and is on a bed rest for the next 2 months. He keeps himself busy by watching television on his Skycast DTH. While watching the television, one day he decided to play a small game, where he has to identify the minimum number of clicks required to surf a given set of channels in a sequence. He quickly decided that it makes for an interesting problem to solve using a software program, (oh, forgot to tell you that he likes to code when he is not busy with his school work).

Your task is to write the software program (using any of the programming language choices given), before Gaurav can do it himself, we think he is going to take 2 hours, so you think you can beat the 12 year old in solving this, we think so! Your time starts now!
 
Obviously the program has to take the following instructions and constraints into account. 

### Instructions
 
There are 13 buttons on his remote: 10 buttons for the numbers  (0-9), an "Up Channel" button, a "Down Channel" button, and a "Back" button:
 
* The number buttons allow you to jump directly to a specific channel.  (Ex: to go to channel 63 by typing “6”, “3”.)
* The "Up Channel" button increments the current channel to the next higher viewable channel, unless the current channel is the highest viewable channel, in which case it rolls over to the lowest viewable channel. 
* The "Down Channel" button decrements to the next lower viewable channel, unless the current channel is the lowest viewable channel, in which case it rolls over to the highest viewable channel.
* The "Back" button reverts to whatever channel was on the television before the current channel. (Ex:  If channel 1 is viewed, then channel 100, then when Back is pressed, the television will go to channel 1.)
 
Gaurav can get from one channel to the next in one of the two ways:

* Clicking any combination of "Up Channel", "Down Channel", and "Back" buttons.
* Keying in the numbers  to the channel. Gaurav will never combine "Back" and number buttons when moving from one channel to the next.

Gaurav’s parents have set some parental control on some channels on Gaurav's television.  These channels are not viewable, so they are skipped by the "Up Channel" and "Down Channel" buttons. 

Given a list of channels to view, the lowest channel, the highest channel, and a list of blocked
channels, your program should return the minimum number of clicks necessary to get
through all the shows that Gaurav would like to watch.

### Input

Your program has to take 3 inputs for each test case, the first input will contain two space delimited numbers, these will form the lowest channel and the highest channel. The next input will contain the number of blocked channels followed by sequence of blocked channels (again space delimited). The first number in the input will contain the number of inputs  The last input is the sequence of channels that Gaurav must view (in order). Again, the first number will contain the number of inputs

### Notes:

Unit tests are mandatory, so please ensure that the code you submit has automated unit tests and you adopt TDD principles (as it applies to this problem statement)

### Sample Input

####Test Case #1

1 20

2 18 19

5 15 14 17 1 17

 

####Test Case #2

103 108

1 104

5 105 106 107 103 105

 

####Test Case #3

1 100

4 78 79 80 3

8 10 13 13 100 99 98 77 81

 

#### Test Case #4

1 200

0

4 1 100 1 101

 

#### Sample Output

 

Output for Test Case #1:  7

Output for Test Case #2: 8

Output for Test Case #3:  12

Output for Test Case #4: 7

 

### Constraints

The lowest channel on the television will be greater than 0, and less than or equal to 10,000.
The highest channel on the television will be greater than or equal to lowest channel, and less than or equal to 10,000.
The list of channels that are blocked on Gaurav's television. All the channels in this list  will be valid channels (greater than or equal to lowest channel, less than or equal to highest channel).  Duplicates may be ignored. The blocked list can be maximum of 40 channels.
The sequence that Gaurav must view contains between 1 and 50 elements, inclusive. All channels in this sequence are not in the blocked list and are between lowest channel and highest channel, inclusive. 
