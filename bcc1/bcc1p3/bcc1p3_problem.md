# Bird Computing Contest 1 P3 - Crow Colonization

> Did you know that *Corvus orru*, better known as crows, are highly territorial and will fiercely defend their nesting areas from intruders? <br>
A mate pair can cover up to 320 acres in territory, and aerial battles often break out when rivals cross the boundary.

The annual **Crow Colonizing Competition** (CCC) has begun! Across a vast region of islands and seas, competitor crows take turns landing in the region to try to claim territories. 

The map of the region the CCC organizers has allocated for the competition can be given as an ~N\times M~ grid (~N~ **columns**, ~M~ **rows**), where each cell is represeting either (`#`) - water, or (`.`) - land. The top-left cell of the map has coordinates ~(1,1)~, and the bottom-right has ~(N,M)~ (**Column #** ~N~, **Row #** ~M~). 

Throughout the contest, ~Q~ events unfold. Each event describes a bird attempting to claim a landmass. The information given is:
- The bird's name, spaceless string ~B_i~
- The coordinates of the landing spot, integers ~X_i~ and ~Y_i~. (~X_i~ is the column, ~Y_i~ is the row)

When a bird lands on a land cell (`.`), it claims the entire connected landmass - all `.` cells that can be reached by moving up, down, left, or right. If another bird already owns the landmass, they are kicked out of the landmass and the new bird takes over. If the bird lands on water (`#`), the bird fails to claim a landmass.

At the end of the contest the organizors would like you to compile a list of all bird that own land, along with how many units of land they control.

## Input Specification

The first line will contain the ~3~ single spaced integers ~N~, ~M~, and ~Q~ - the number of columns, rows, and events.

The next ~M~ lines will contain a string where each ~N~ characters are either `.` or `#`, describing cell on the map.

The next ~Q~ line will describe an event and will contain a spacelesss string ~B_i~ - representing the bird's name, and integers ~X_i~ and ~Y_i~ - representing it's landing coordinates, all of which are seperated by one space. The same bird may appear in different events.

## Output Specification

For each bird that owns at least one unit of land at the end of the contest, print on a single line, single spaced, their name and the total landmass units owned.

(The permutation of outputted lines does not matter, as long as compiled list is correct.)

## Constraints

~1\le N,\space M\le 10^3~

~1\le Q \le 10^6~

~1\le X_i \le N~

~1\le Y_i \le M~

### Subtasks 1 [20%]
~1\le N,\space M \le 10^2~

~1\le Q \le 10^3~
### Subtasks 2 [80%]
No additional constraints.

## Sample Input 1
```
9 9 7
#...##...
.....##..
...###..#
#.#######
###.###.#
#...###..
...##....
#.##.....
####....#
Coco 3 3
Kiwi 8 3
Sunny 2 1
Tweety 7 8
Birb 6 7
Coco 2 6
Zippy 5 3
```
## Output for Sample Input 1
```
Kiwi 7
Sunny 12
Coco 8
Birb 16
```
## Explanation of Output for Sample Input 1
First, Coco lands at ~(3,3)~ and claims the cells ~[(3,3),(2,3), (3,2),(2,2),(2,4),(1,3),(1,2),(2,1),(3,1),(4,1),(4,2),(5,2)]~.

Next, Kiwi lands at ~(8,3)~ and claims the cells ~[(8,3),(7,3), (8,2),(9,2),(9,1),(8,1),(7,1)]~.

Next, Sunny lands at ~(2,1)~ and claims the cells ~[(2,1),(3,1),(4,1),(1,3),(1,2),(4,2),(5,2),(2,2),(2,4),(3,3),(3,2),(2,3)]~.

Next, Tweety lands at ~(7,8)~ and claims the cells ~[(7,8),(8,5),(8,6),(9,6),(9,7),(9,8),(8,7),(8,8),(8,9),(7,9),(6,9),(5,9),(5,8),(6,8),(7,7),(6,7)]~.

Next, Birb lands at ~(6,7)~ and claims the cells ~[(6,7),(8,8),(8,9),(7,9),(8,5),(8,6),(6,8),(7,7),(9,6),(9,7),(6,9),(9,8),(8,7),(5,9),(7,8),(5,8)]~.

Next, Coco lands at ~(2,6)~ and claims the cells ~[(2,6),(3,6),(4,6),(4,5),(2,7),(1,7),(3,7),(2,8)]~.

Finally, Zippy attempts to lands at ~(5,3)~, but due to the cell being water, Zippy fails to claim anything.

In the end, Coco has ~8~ cells, Kiwi has ~7~, Sunny has ~12~, and Birb has ~16~. 

Green cells represent land (`.`) and blue cells represent water (`#`). The string in the cell shows who owns it. Here is what the map looks like when the competition ends: <br>
<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/74a38834-8529-4ae0-8022-4059cbe20f56.png" alt="End Result" width="350"/></div>
