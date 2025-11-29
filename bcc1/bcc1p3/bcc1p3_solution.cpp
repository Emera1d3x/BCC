#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> competition_map(M+1, vector<int>(N+1, 0));
  // 0 = water
  // 1 = unclaimed land
  // >1 = landmass id 

  for (int m = 1; m <= M; m++){
    string row; cin >> row;
    for (int n = 1; n <= N; n++){
      competition_map[m][n] = (row[n-1] == '#') ? 0 : 1;
    }
  }

  // Store owner of landmass id, owner's name and size 
  unordered_map<int, pair<string, int>> landmass;
  int id_num = 2;

  // For each query
  // If the bird lands on water, fail
  // If the bird is claiming unclaimed land, bfs and claim it
  // If the bird is on claimed land, replace the name of the owner (no bfsing the same thing)
  for (int i = 0; i < Q; i++){
    string bird_name; int x_coord, y_coord;
    cin >> bird_name >> x_coord >> y_coord;
    if (competition_map[y_coord][x_coord] == 0){
      continue;
    } else if (competition_map[y_coord][x_coord] == 1){
      int landmass_size = 0;
      queue<pair<int, int>> bfs_visitor;
      bfs_visitor.push(make_pair(y_coord, x_coord));
      competition_map[y_coord][x_coord] = id_num;
      while (!bfs_visitor.empty()){
        int y_bfs = bfs_visitor.front().first;
        int x_bfs = bfs_visitor.front().second;
        bfs_visitor.pop();
        landmass_size++;
        if (0 < y_bfs-1 && y_bfs-1 <= M && 0 < x_bfs && x_bfs <= N && competition_map[y_bfs-1][x_bfs] == 1){ bfs_visitor.push(make_pair(y_bfs-1, x_bfs)); competition_map[y_bfs-1][x_bfs] = id_num;}
        if (0 < y_bfs+1 && y_bfs+1 <= M && 0 < x_bfs && x_bfs <= N && competition_map[y_bfs+1][x_bfs] == 1){ bfs_visitor.push(make_pair(y_bfs+1, x_bfs)); competition_map[y_bfs+1][x_bfs] = id_num;}
        if (0 < y_bfs && y_bfs <= M && 0 < x_bfs-1 && x_bfs-1 <= N && competition_map[y_bfs][x_bfs-1] == 1){ bfs_visitor.push(make_pair(y_bfs, x_bfs-1)); competition_map[y_bfs][x_bfs-1] = id_num;}
        if (0 < y_bfs && y_bfs <= M && 0 < x_bfs+1 && x_bfs+1 <= N && competition_map[y_bfs][x_bfs+1] == 1){ bfs_visitor.push(make_pair(y_bfs, x_bfs+1)); competition_map[y_bfs][x_bfs+1] = id_num;}
      }
      landmass[id_num] = {bird_name, landmass_size};
      id_num++;
    } else {
      landmass[competition_map[y_coord][x_coord]] = {bird_name, landmass[competition_map[y_coord][x_coord]].second};
    }
  }

  // A single bird may own multiple landmasses, this gets all the birds with a landmass
  // and adds up the areas
  unordered_map<string, int> final_list;
  for (auto z : landmass){
    string bird_name = z.second.first;
    int landmass_size = z.second.second;
    if (final_list.count(bird_name) != 0){
      final_list[bird_name] = final_list[bird_name] + landmass_size;
    } else {
      final_list[bird_name] = landmass_size;
    }
  }

  // Output (order does not matter)
  for (auto z : final_list){
    string bird_name = z.first;
    int landmass_size = z.second;
    cout << bird_name << " " << landmass_size << endl;
  }

  return 0;
}
