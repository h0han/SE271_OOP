////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 4: Snake Arena
// Note: You WILL SUBMIT THIS FILE !!!
// Implement your strategy, whatever you want
// You can modify anything as long as it can be compiled with the provided code
// The current implementation simplely rotates the snake every turn
////////////////////////////////////////////////////////////////////////////////

#include "MyPlayer.h"

#include "Commons.h"
#include "Snake.h"
#include "Fruit.h"
#include <algorithm>

namespace snake_arena {
	// Constructor
	MyPlayer::MyPlayer(int map_size) :
		Player(map_size) {

	}

	// Destructor
	MyPlayer::~MyPlayer() {

	}

	// Your function to primarily implement
	bool MyPlayer::LongerThanEn(int mylen, int enlen) {
		if (mylen > enlen) {
			return true;
		}
		else { return false; }
	}
	void MyPlayer::GoFruit1() {
		// If the fruit is above the head
		if (fruit1_pos[1] < myhead[1]) {
			// The fruit is on the right side of the head
			if (fruit1_pos[0] > myhead[0]) {
				fruit_path[0] *= 3;
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit1_pos[0] < myhead[0]) {
				fruit_path[0] *= 3;
				fruit_path[3] *= 3;
			}
			if (fruit1_pos[0] == myhead[0]) {
				fruit_path[0] *= 6; // Weighted Upward Movement
			}
		}
		// If the fruit is below the head
		if (fruit1_pos[1] > myhead[1]) {
			// The fruit is on the right side of the head
			if (fruit1_pos[0] > myhead[0]) {
				fruit_path[1] *= 3;
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit1_pos[0] < myhead[0]) {
				fruit_path[1] *= 3;
				fruit_path[3] *= 3;
			}
			if (fruit1_pos[0] == myhead[0]) {
				fruit_path[1] *= 6; // Weighted to move downward
			}
		}
		// 오른쪽에 있는 경우
		if (fruit1_pos[0] > myhead[0]) {
			// 위쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
				fruit_path[2] *= 3;
			}
			// 아래쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
				fruit_path[2] *= 3;
			}
			if (fruit1_pos[1] == myhead[1]) {
				fruit_path[2] *= 6; // Weighted to move downward
			}
		}
		// 왼쪽에 있는 경우
		if (fruit1_pos[0] < myhead[0]) {
			// 위쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
				fruit_path[3] *= 3;
			}
			// 아래쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
				fruit_path[3] *= 3;
			}
			if (fruit1_pos[1] == myhead[1]) {
				fruit_path[3] *= 6; // Weighted to move downward
			}
		}
	}

	void MyPlayer::GoFruit2() {
		if (fruit2_pos[1] < myhead[1]) {
			// The fruit is on the right side of the head
			if (fruit2_pos[0] > myhead[0]) {
				fruit_path[0] *= 3;
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit2_pos[0] < myhead[0]) {
				fruit_path[0] *= 3;
				fruit_path[3] *= 3;
			}
			if (fruit2_pos[0] == myhead[0]) {
				fruit_path[0] *= 6; // Weighted Upward Movement
			}
		}
		// If the fruit is below the head
		if (fruit2_pos[1] > myhead[1]) {
			// The fruit is on the right side of the head
			if (fruit2_pos[0] > myhead[0]) {
				fruit_path[1] *= 3;
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit2_pos[0] < myhead[0]) {
				fruit_path[1] *= 3;
				fruit_path[3] *= 3;
			}
			if (fruit2_pos[0] == myhead[0]) {
				fruit_path[1] *= 6; // Weighted to move downward
			}

		}
		// 오른쪽에 있는 경우
		if (fruit2_pos[0] > myhead[0]) {
			// 위쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
				fruit_path[2] *= 3;
			}
			// 아래쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
				fruit_path[2] *= 3;
			}
			if (fruit2_pos[1] == myhead[1]) {
				fruit_path[2] *= 6; // Weighted to move downward
			}
		}
		// 왼쪽에 있는 경우
		if (fruit2_pos[0] < myhead[0]) {
			// 위쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
				fruit_path[3] *= 3;
			}
			// 아래쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
				fruit_path[3] *= 3;
			}
			if (fruit2_pos[1] == myhead[1]) {
				fruit_path[3] *= 6; // Weighted to move downward
			}
		}
	}

	Direction MyPlayer::selectDirection(
		int turn, Snake* player_snake, Snake* enemy_snake, std::vector<Fruit*> fruits) {

		int mylen = player_snake->getPositions().size();
		int enlen = enemy_snake->getPositions().size();

		int myhead[2] = { 0, }; int mytail[2] = { 0, };
		int enhead[2] = { 0, }; int entail[2] = { 0, };

		int trace[15][15] = { 0, };
		std::vector<Pos> positions = player_snake->getPositions();
		for (int i = 0; i < mylen; ++i) {
			trace[player_snake->getPositions()[i].y][player_snake->getPositions()[i].x] = 1;
			if (i == 0) {
				myhead[0] = positions[i].x;
				myhead[1] = positions[i].y;
			}
			if (i == mylen) {
				mytail[0] = positions[i].x;
				mytail[1] = positions[i].y;
			}
		}

		std::vector<Pos> en_positions = enemy_snake->getPositions();
		for (int i = 0; i < enlen; ++i) {	// Store the opponent's body position
			trace[enemy_snake->getPositions()[i].y][enemy_snake->getPositions()[i].x] = 2;
			if (i == 0) {
				enhead[0] = en_positions[i].x;
				enhead[1] = en_positions[i].y;
			}
			if (i == enlen) {
				entail[0] = en_positions[i].x;
				entail[1] = en_positions[i].y;
			}
		}

		int mydir;	// Save Direction (Up: 2, Down: -2, Right: 1, Bottom: -1)
		if (player_snake->getDirection().dx == 1) {
			mydir = 1;
		}
		if (player_snake->getDirection().dx == -1) {
			mydir = -1;
		}
		if (player_snake->getDirection().dy == 1) {
			mydir = 2;
		}
		if (player_snake->getDirection().dy == -1) {
			mydir = -2;
		}

		// Priority 1 : Do not hit a wall or come into contact with the other body

		int path[4] = { 1, 1, 1, 1 };	// { Up, Down, Right, Left } : 1 allows; 0 does not allow
		// If there is a wall or opponent above the head of an object's head
		//if (myhead[1] == 0 || trace[myhead[1] + 1][myhead[0]] != 0) {
		//	path[0] = 0;
		//}
		//// If there is a wall or opponent under the head of an object's head
		//if (myhead[1] == 14 || trace[myhead[1] - 1][myhead[0]] != 0) {
		//	path[1] = 0;
		//}
		//// If there is a wall or opponent to the right of the object's head
		//if (myhead[0] == 14 || trace[myhead[1]][myhead[0] + 1] != 0) {
		//	path[2] = 0;
		//}
		//// If there is a wall or opponent to the left of the object's head
		//if (myhead[0] == 0 || trace[myhead[1]][myhead[0] - 1] != 0) {
		//	path[3] = 0;
		//}


		if (myhead[1] == 0) {
			path[0] *= 0;
			path[2] += 3;
			path[3] += 3;
		}
		// If there is a wall or opponent under the head of an object's head
		if (myhead[1] == 14) {
			path[1] *= 0;
			path[2] += 3;
			path[3] += 3;
		}
		// If there is a wall or opponent to the right of the object's head
		if (myhead[0] == 14) {
			path[2] += 0;
			path[0] += 3;
			path[1] += 3;
		}
		// If there is a wall or opponent to the left of the object's head
		if (myhead[0] == 0) {
			path[3] += 0;
			path[0] += 3;
			path[1] += 3;
		}


		if (trace[myhead[1] - 1][myhead[0]] != 0) {
			path[0] *= 0;
			path[1] += 3;
			path[2] += 3;
			path[3] += 3;
		}
		if (trace[myhead[1] + 1][myhead[0]] != 0) {
			path[1] *= 0;
			path[0] += 3;
			path[2] += 3;
			path[3] += 3;
		}
		if (trace[myhead[1]][myhead[0] + 1] != 0) {
			path[2] *= 0;
			path[0] += 3;
			path[1] += 3;
			path[3] += 3;
		}
		if (trace[myhead[1]][myhead[0] - 1] != 0) {
			path[3] *= 0;
			path[0] += 3;
			path[1] += 3;
			path[2] += 3;
		}

		// store fruit coordinates
		int fruit1_pos[2] = { 0, }; int fruit2_pos[2] = { 0, };
		fruit1_pos[0] = fruits[0]->getPositions()[0].x; fruit1_pos[1] = fruits[0]->getPositions()[0].y;
		fruit2_pos[0] = fruits[1]->getPositions()[0].x; fruit2_pos[1] = fruits[1]->getPositions()[0].y;

		// Calculate the distance between the head and fruit
		double dist1 = sqrt(pow((fruit1_pos[0] - myhead[0]), 2) + pow((fruit1_pos[1]) - myhead[1], 2));
		double dist2 = sqrt(pow((fruit2_pos[0] - myhead[0]), 2) + pow((fruit2_pos[1]) - myhead[1], 2));

		// 적이 더 가까운지, 내가 더 가까운지 설계
		double en_dist1 = sqrt(pow((fruit1_pos[0] - enhead[0]), 2) + pow((fruit1_pos[1]) - enhead[1], 2));
		double en_dist2 = sqrt(pow((fruit2_pos[0] - enhead[0]), 2) + pow((fruit2_pos[1]) - enhead[1], 2));

		int fruit_path[4] = { 1, 1, 1, 1 };	// { Up, Down, Right, Left } : 1 allows; 0 does not allow

		if (dist1 < en_dist1) {
			GoFruit1();
		} 
		else if (dist1 > en_dist1) {
			GoFruit1();
		}
		else if (dist1 == en_dist1) {
			if (LongerThanEn(mylen, enlen) == true) {
				GoFruit1();
			}
			else { GoFruit2(); }
		}
		
		if (dist2 < en_dist2) {
			GoFruit2();
		}
		else if (dist2 > en_dist2) {
			GoFruit2();
		}
		else if (dist2 == en_dist2) {
			if (LongerThanEn(mylen, enlen) == true) {
				GoFruit2();
			}
			else { GoFruit1(); }
		}

		if (dist1 < dist2) {
			if (LongerThanEn(mylen, enlen) == true) {
				GoFruit1();
			}
			else { GoFruit2(); }
		}
			
		if (dist1 > dist2) {
			// { Up, Down, Right, Left }
			if (LongerThanEn(mylen, enlen) == true) {
				GoFruit2();
				}
			else { GoFruit1(); }
		}

		int dir[4] = { 0, };
		for (int i = 0; i < 4; ++i) {
			dir[i] = path[i] + fruit_path[i];
		}

		int max = 0; int idx = 0;
		for (int i = 0; i < 4; ++i) {
			if (max < dir[i]) {
				max = dir[i];
				idx = i;
			}
		}

		if (idx == 0) {
			return DrtN();
		}
		if (idx == 1) {
			return DrtS();
		}
		if (idx == 2) {
			return DrtE();
		}
		if (idx == 3) {
			return DrtW();
		}
	}
}
