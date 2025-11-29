# Bird Computing Contest 1 P2 - Geese Game
> Did you know that *Branta canadensis*, better known as the Canadian goose, have a population of approximately 7 million in North America? <br>
This means that if a war broke out between Torontonians and the geese, each person would have to fight three geese. <br>
Pick your fights wisely.

Just like how children play games such as tag or manhunt, geese also enjoy spending their free time engaging in physical activities. One such pastime is a game called as the **Geese Game**.

The game takes place on a triangular field made up of hexagonal tiles. The ~i^{th}~ row contains ~i~ hexagon, forming a total of ~N~ hexagons arranged in a triangular shape. Each hexagon is numbered ~1, 2, .. N~ starting from the top of the triangle.

For example, when ~N = 10~ this is how the playground would look like:
<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/c6840260-3d60-4855-99f3-3bfe15a97355.png" alt="Example" width="200"/></div>

The game is played between two participants - a runner and a chaser.

The runner begins on a specific hexagon ~A~, while the chaser starts on another hexagon ~B~. The game proceeds in turns: during each turn, first the runner moves to an adjacent hexagon (sharing a edge), and then the chaser moves twice, each move also to an adjacent hexagon.

The runner's goal is to survive for as many turns as possible, while the chaser's goal is to catch the runner- that is, to land on the same hexagon as the runner - in as few turns as possible.

Assuming both the runner and the chaser play optimally, determine on which turn will the chaser catch the runner.

## Input Specification

On a single line there will be ~3~ single spaced integers ~N~, ~A~, and ~B~, representing number of hexagons, position of the runner, and position of the chaser.

It is guaranteed that ~N~ is a triangular number, i.e. ~N = \frac{n(n+1)}{2}~ for some integer ~n \ge 1~, ensuring the formation is a triangle

## Output Specification

On a single line, output the turn number in which the chaser will catch the runner.

## Constraints

~1\le N\le 10^6~

~N = \frac{n(n+1)}{2}~ for some integer ~n \ge 1~ (triangular number)
 
~1\le A,B \le N~

### Subtasks 1 [10%]
~1\le N \le 10^3~

### Subtasks 1 [20%]
~1\le N \le 10^5~

### Subtasks 2 [70%]
No additional constraints.

## Sample Input 1
```
21 5 13
```
## Output for Sample Input 1
```
2
```
## Explanation of Output for Sample Input 1
Given the runner is on the green hexagon and the chaser is on the red hexagon, here is an image showing what the initial setup looks like:

<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/e1039b88-e232-4cb0-9640-7c59a47565ea.png" alt="Initial Condition" width="250"/></div>

The following images shows a series of turns in which both the runner and chaser move optimally.

Turn ~1~. Runner goes to hexagon ~2~ and the chaser goes to hexagon ~4~:
<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/4015d3d1-eec4-49d7-a30d-4924a25c0ee3.png" alt="Turn1" width="250"/></div>

Turn ~2~. Runner goes to hexagon ~3~ and the chaser goes to hexagon ~3~ to catch the runner:
<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/2eff8144-575f-4c87-8009-abbfd12a9d09.png" alt="Turn2" width="250"/></div>

On turn ~2~ the runner gets caught.

## Sample Input 2
```
5050 420 67
```
## Output for Sample Input 2
```
17
```
