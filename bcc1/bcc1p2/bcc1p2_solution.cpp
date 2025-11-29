#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

  double hexs, runner, chaser;
  cin >> hexs >> runner >> chaser;

  // Think of the weird triangle data structure to this:
  /* 
    X
    X X
    X X X
    X X X X
    X X X X X 
    X X X X X X
  */
  // just a half grid.
  // Convert the hexagonal adjacency to this:
  // runner can move like this in 1 turn (where R is the position of the runner):
  /*
    1 1 0
    1 R 1
    0 1 1
  */
  // chaser can move like this in 1 turn (where C is the position of the chaser):
  /*
    1 1 1 0 0
    1 1 1 1 0
    1 1 C 1 1
    0 1 1 1 1
    0 0 1 1 1
  */
  // This simplifies the problem a lot
  // This makes it so you don't need to 

  double n = ceil((-1 + sqrt(1 + 8.0 * hexs)) / 2.0);

  double runner_row = ceil((-1 + sqrt(1 + 8.0 * runner)) / 2.0);
  double runner_col = runner - ((runner_row * runner_row - runner_row) / 2.0);

  double chaser_row = ceil((-1 + sqrt(1 + 8.0 * chaser)) / 2.0);
  double chaser_col = chaser - ((chaser_row * chaser_row - chaser_row) / 2.0);

  // Loop thorugh literally each cell. The turn at which the 
  // runner gets caught when both players move optimally is maximum of  
  // the shortest path of from the chasers start to the ending cell
  // while being less than the shortest path of where the runner starts to 
  // the ending cell.
  double ans = 0.0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= i; j++){
      int runner_dist = 0;
      double chaser_dist = 0;
      // To calculate the distances from runner/chaser start to the ending cell
      // if the ending cell is to the top-left/bottom-right relative to the player, its chebyshev dist
      // if the ending cell is to the top-right/bottom-left relative to the player, its manhatten dist
      if ((i <= runner_row && j <= runner_col) || (i >= runner_row && j >= runner_col)){
        runner_dist = max(abs(runner_row - i), abs(runner_col - j));
      } else {
        runner_dist = abs(runner_row - i) + abs(runner_col - j);
      }
      if ((i <= chaser_row && j <= chaser_col) || (i >= chaser_row && j >= chaser_col)){
        chaser_dist = max(fabs(chaser_row - i), fabs(chaser_col - j));
      } else {
        chaser_dist = abs(chaser_row - i) + abs(chaser_col - j);
      } chaser_dist = ceil(chaser_dist/2);
      // If runner can get there first, 
      if (runner_dist < chaser_dist){
        // Get the maximum of the chaser's distance
        ans = max(ans, chaser_dist);
      }
    }
  }
  cout << (int)ans << endl;
  return 0;
}
