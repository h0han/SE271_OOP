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
		if (mylen >= enlen) {
			return true;
		}
		else { return false; }
	}
	void MyPlayer::GoFruit1(int(&fruit1_pos)[2], int(&myhead)[2], int(&fruit_path)[4]) {
		// If the fruit is above the head
		if (fruit1_pos[1] < myhead[1]) {
			fruit_path[0] *= 3;
			// The fruit is on the right side of the head
			if (fruit1_pos[0] > myhead[0]) {
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit1_pos[0] < myhead[0]) {
				fruit_path[3] *= 3;
			}
			if (fruit1_pos[0] == myhead[0]) {
				fruit_path[0] *= 6; // Weighted Upward Movement
			}
		}
		// If the fruit is below the head
		if (fruit1_pos[1] > myhead[1]) {
			fruit_path[1] *= 3;
			// The fruit is on the right side of the head
			if (fruit1_pos[0] > myhead[0]) {
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit1_pos[0] < myhead[0]) {
				fruit_path[3] *= 3;
			}
			if (fruit1_pos[0] == myhead[0]) {
				fruit_path[1] *= 6; // Weighted to move downward
			}
		}
		// 오른쪽에 있는 경우
		if (fruit1_pos[0] > myhead[0]) {
			fruit_path[2] *= 3;
			// 위쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
			}
			// 아래쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
			}
			if (fruit1_pos[1] == myhead[1]) {
				fruit_path[2] *= 6;
			}
		}
		// 왼쪽에 있는 경우
		if (fruit1_pos[0] < myhead[0]) {
			fruit_path[3] *= 3;
			// 위쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
			}
			// 아래쪽
			if (fruit1_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
			}
			if (fruit1_pos[1] == myhead[1]) {
				fruit_path[3] *= 6;
			}
		}
	}

	void MyPlayer::GoFruit2(int(&fruit2_pos)[2], int(&myhead)[2], int(&fruit_path)[4]) {
		if (fruit2_pos[1] < myhead[1]) {
			fruit_path[0] *= 3;
			// The fruit is on the right side of the head
			if (fruit2_pos[0] > myhead[0]) {
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit2_pos[0] < myhead[0]) {
				fruit_path[3] *= 3;
			}
			if (fruit2_pos[0] == myhead[0]) {
				fruit_path[0] *= 6; // Weighted Upward Movement
			}
		}
		// If the fruit is below the head
		if (fruit2_pos[1] > myhead[1]) {
			fruit_path[1] *= 3;
			// The fruit is on the right side of the head
			if (fruit2_pos[0] > myhead[0]) {
				fruit_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (fruit2_pos[0] < myhead[0]) {
				fruit_path[3] *= 3;
			}
			if (fruit2_pos[0] == myhead[0]) {
				fruit_path[1] *= 6;
			}

		}
		// 오른쪽에 있는 경우
		if (fruit2_pos[0] > myhead[0]) {
			fruit_path[2] *= 3;
			// 위쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
			}
			// 아래쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
			}
			if (fruit2_pos[1] == myhead[1]) {
				fruit_path[2] *= 6;
			}
		}
		// 왼쪽에 있는 경우
		if (fruit2_pos[0] < myhead[0]) {
			fruit_path[3] *= 3;
			// 위쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[0] *= 3;
			}
			// 아래쪽
			if (fruit2_pos[1] < myhead[1]) {
				fruit_path[1] *= 3;
			}
			if (fruit2_pos[1] == myhead[1]) {
				fruit_path[3] *= 6;
			}
		}
	}

	void MyPlayer::GoTail(int(&mytail)[2], int(&myhead)[2], int(&tail_path)[4]) {
		// If the fruit is above the head
		if (mytail[1] < myhead[1]) {
			tail_path[0] *= 3;
			// The fruit is on the right side of the head
			if (mytail[0] > myhead[0] - 1) {
				tail_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (mytail[0] < myhead[0]) {
				tail_path[3] *= 3;
			}
			//if (mytail[0] == myhead[0]) {
			//	tail_path[0] *= 3; // Weighted Upward Movement
			//}
		}
		// If the fruit is below the head
		if (mytail[1] > myhead[1]) {
			tail_path[1] *= 3;
			// The fruit is on the right side of the head
			if (mytail[0] > myhead[0] - 1) {
				tail_path[2] *= 3;
			}
			// If the fruit is on the left side of the head
			if (mytail[0] < myhead[0]) {
				tail_path[3] *= 3;
			}
			//if (mytail[0] == myhead[0]) {
			//	tail_path[1] *= 3; // Weighted to move downward
			//}
		}
		// 오른쪽에 있는 경우
		if (mytail[0] > myhead[0]) {
			tail_path[2] *= 3;
			// 위쪽
			if (mytail[1] < myhead[1]) {
				tail_path[0] *= 3;
			}
			// 아래쪽
			if (mytail[1] < myhead[1]) {
				tail_path[1] *= 3;
			}
			//if (mytail[1] == myhead[1]) {
			//	tail_path[2] *= 3;
			//}
		}
		// 왼쪽에 있는 경우
		if (mytail[0] < myhead[0]) {
			tail_path[3] *= 3;
			// 위쪽
			if (mytail[1] < myhead[1]) {
				tail_path[0] *= 3;
			}
			// 아래쪽
			if (mytail[1] < myhead[1]) {
				tail_path[1] *= 3;
			}
			//if (mytail[1] == myhead[1]) {
			//	tail_path[3] *= 3;
			//}
		}
	}

	Direction MyPlayer::selectDirection(
		int turn, Snake* player_snake, Snake* enemy_snake, std::vector<Fruit*> fruits) {

		int mylen = player_snake->getPositions().size();
		int enlen = enemy_snake->getPositions().size();

		int myhead[2] = { 0, }; int mytail[2] = { 0, };
		int enhead[2] = { 0, }; int entail[2] = { 0, };

		int trace[15][15] = { 0, };
		int dfsmap[15][15] = { 0, };
		std::vector<Pos> positions = player_snake->getPositions();
		myhead[0] = positions[0].x; myhead[1] = positions[0].y;
		for (int i = 0; i < mylen; ++i) {
			trace[player_snake->getPositions()[i].y][player_snake->getPositions()[i].x] = 1;
			dfsmap[player_snake->getPositions()[i].y][player_snake->getPositions()[i].x] = 1;
			if (i == 0) {
				dfsmap[player_snake->getPositions()[i].y][player_snake->getPositions()[i].x] = 2;
				myhead[0] = positions[i].x;
				myhead[1] = positions[i].y;
			}
			if (i == mylen - 1) {
				mytail[0] = positions[i].x;
				mytail[1] = positions[i].y;
			}
		}

		std::vector<Pos> en_positions = enemy_snake->getPositions();
		enhead[0] = positions[0].x; enhead[1] = positions[0].y;
		for (int i = 0; i < enlen; ++i) {	// Store the opponent's body position
			trace[enemy_snake->getPositions()[i].y][enemy_snake->getPositions()[i].x] = 2;
			dfsmap[enemy_snake->getPositions()[i].y][enemy_snake->getPositions()[i].x] = 1;
			if (i == 0) {
				enhead[0] = en_positions[i].x;
				enhead[1] = en_positions[i].y;
			}
			if (i == enlen) {
				entail[0] = en_positions[i].x;
				entail[1] = en_positions[i].y;
			}
		}

		// Priority 1 : Do not hit a wall or come into contact with the other body

		int path[4] = { 1, 1, 1, 1 };	// { Up, Down, Right, Left } : 1 allows; 0 does not allow

		if (myhead[1] == 0) {
			path[0] *= 0;
			path[1] *= 3;
			path[2] *= 3;
			path[3] *= 3;
		}
		// If there is a wall or opponent under the head of an object's head
		if (myhead[1] == 14) {
			path[1] *= 0;
			path[0] *= 3;
			path[2] *= 3;
			path[3] *= 3;
		}
		// If there is a wall or opponent to the right of the object's head
		if (myhead[0] == 14) {
			path[2] *= 0;
			path[0] *= 3;
			path[1] *= 3;
			path[3] *= 3;
		}
		// If there is a wall or opponent to the left of the object's head
		if (myhead[0] == 0) {
			path[3] *= 0;
			path[0] *= 3;
			path[1] *= 3;
			path[2] *= 3;
		}


		if (trace[myhead[1] - 1][myhead[0]] != 0) {
			path[0] *= 0;
			path[1] *= 3;
			path[2] *= 3;
			path[3] *= 3;
		}
		if (trace[myhead[1] + 1][myhead[0]] != 0) {
			path[1] *= 0;
			path[0] *= 3;
			path[2] *= 3;
			path[3] *= 3;
		}
		if (trace[myhead[1]][myhead[0] + 1] != 0) {
			path[2] *= 0;
			path[0] *= 3;
			path[1] *= 3;
			path[3] *= 3;
		}
		if (trace[myhead[1]][myhead[0] - 1] != 0) {
			path[3] *= 0;
			path[0] *= 3;
			path[1] *= 3;
			path[2] *= 3;
		}
		// store fruit coordinates
		int fruit1_pos[2] = { 0, }; int fruit2_pos[2] = { 0, };
		fruit1_pos[0] = fruits[0]->getPositions()[0].x; fruit1_pos[1] = fruits[0]->getPositions()[0].y;
		fruit2_pos[0] = fruits[1]->getPositions()[0].x; fruit2_pos[1] = fruits[1]->getPositions()[0].y;

		// Calculate the distance between the head and fruit
		double dist1 = sqrt(pow((fruit1_pos[0] - myhead[0]), 2) + pow((fruit1_pos[1]) - myhead[1], 2));
		double dist2 = sqrt(pow((fruit2_pos[0] - myhead[0]), 2) + pow((fruit2_pos[1]) - myhead[1], 2));

		if (dist1 < dist2) {
			dfsmap[fruit1_pos[1]][fruit1_pos[0]] = 2;
		}
		else if (dist1 > dist2) {
			dfsmap[fruit2_pos[1]][fruit2_pos[0]] = 2;
		}

		// 적이 더 가까운지, 내가 더 가까운지 설계
		double en_dist1 = sqrt(pow((fruit1_pos[0] - enhead[0]), 2) + pow((fruit1_pos[1]) - enhead[1], 2));
		double en_dist2 = sqrt(pow((fruit2_pos[0] - enhead[0]), 2) + pow((fruit2_pos[1]) - enhead[1], 2));

		//fruit_path[0] = 1;	// { Up, Down, Right, Left } : 1 allows; 0 does not allow
		int fruit_path[4] = { 1, 1, 1, 1 };

		int tail_path[4] = { 1, 1, 1, 1 };

		double far1 = sqrt(pow((0 - myhead[0]), 2) + pow((0 - myhead[1]), 2));
		double far2 = sqrt(pow((14 - myhead[0]), 2) + pow((14 - myhead[1]), 2));
		double far3 = sqrt(pow((14 - myhead[0]), 2) + pow((0 - myhead[1]), 2));
		double far4 = sqrt(pow((14 - myhead[0]), 2) + pow((14 - myhead[1]), 2));
		double far[4] = { far1, far2, far3, far4 };
		
		int far_max = 0; int far_idx = 0;
		for (int i = 0; i < 4; ++i) {
			if (far_max < far[i]) {
				far_max = far[i];
				far_idx = i;
			}
		}

		if ((mylen > 20) && (LongerThanEn(mylen, enlen) == false)) {
			while (turn == 300) {
				while (myhead[1] == 0 ) {
					path[0] *= 3;
				}
				if (myhead[1] == 0) {

				}
			}
			
			if (0 < myhead[1]) {
				tail_path[0] *= 3;
				// The fruit is on the right side of the head
				if (mytail[0] > myhead[0] - 1) {
					tail_path[2] *= 3;
				}
				// If the fruit is on the left side of the head
				if (mytail[0] < myhead[0]) {
					tail_path[3] *= 3;
				}
				//if (mytail[0] == myhead[0]) {
				//	tail_path[0] *= 3; // Weighted Upward Movement
				//}
			}
		}

		if ((mylen >= 40)&&(LongerThanEn(mylen, enlen) == true)) {
			GoTail(mytail, myhead, tail_path);
		}
		else {
			if (dist1 < en_dist1) {
				GoFruit1(fruit1_pos, myhead, fruit_path);
			}
			else if (dist1 > en_dist1) {
				//if (LongerThanEn(mylen, enlen) == true) {
				//	GoFruit1(fruit1_pos, myhead, fruit_path);
				//}
				GoFruit2(fruit2_pos, myhead, fruit_path);
			}
			else if (dist1 == en_dist1) {
				if (LongerThanEn(mylen, enlen) == true) {
					GoFruit1(fruit1_pos, myhead, fruit_path);
				}
				GoFruit2(fruit2_pos, myhead, fruit_path);
			}

			if (dist2 < en_dist2) {
				GoFruit2(fruit2_pos, myhead, fruit_path);
			}
			else if (dist2 > en_dist2) {
				//if (LongerThanEn(mylen, enlen) == true) {
				//	GoFruit2(fruit1_pos, myhead, fruit_path);
				//}
				GoFruit1(fruit1_pos, myhead, fruit_path);
			}
			else if (dist2 == en_dist2) {
				if (LongerThanEn(mylen, enlen) == true) {
					GoFruit2(fruit2_pos, myhead, fruit_path);
				}
				GoFruit1(fruit1_pos, myhead, fruit_path);
			}
		}
	
		int dir[4] = { 1, 1, 1, 1 };
		for (int i = 0; i < 4; ++i) {
			dir[i] = path[i] * fruit_path[i] * tail_path[i];
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


//namespace snake_arena {
//	// Constructor
//	MyPlayer::MyPlayer(int map_size) :
//		Player(map_size) {
//
//	}
//
//	// Destructor
//	MyPlayer::~MyPlayer() {
//
//	}
//
//	// Your function to primarily implement
//	bool MyPlayer::LongerThanEn(int mylen, int enlen) {
//		if (mylen > enlen) {
//			return true;
//		}
//		else { return false; }
//	}
//	void MyPlayer::GoFruit1(int(&fruit1_pos)[2], int(&myhead)[2], int(&fruit_path)[4]) {
//		// If the fruit is above the head
//		if (fruit1_pos[1] < myhead[1]) {
//			fruit_path[0] *= 3;
//			// The fruit is on the right side of the head
//			if (fruit1_pos[0] > myhead[0]) {
//				fruit_path[2] *= 3;
//			}
//			// If the fruit is on the left side of the head
//			if (fruit1_pos[0] < myhead[0]) {
//				fruit_path[3] *= 3;
//			}
//			if (fruit1_pos[0] == myhead[0]) {
//				fruit_path[0] *= 6; // Weighted Upward Movement
//			}
//		}
//		// If the fruit is below the head
//		if (fruit1_pos[1] > myhead[1]) {
//			fruit_path[1] *= 3;
//			// The fruit is on the right side of the head
//			if (fruit1_pos[0] > myhead[0]) {
//				fruit_path[2] *= 3;
//			}
//			// If the fruit is on the left side of the head
//			if (fruit1_pos[0] < myhead[0]) {
//				fruit_path[3] *= 3;
//			}
//			if (fruit1_pos[0] == myhead[0]) {
//				fruit_path[1] *= 6; // Weighted to move downward
//			}
//		}
//		// if on the right
//		if (fruit1_pos[0] > myhead[0]) {
//			fruit_path[2] *= 3;
//			if (fruit1_pos[1] < myhead[1]) {
//				fruit_path[0] *= 3;
//			}
//			if (fruit1_pos[1] < myhead[1]) {
//				fruit_path[1] *= 3;
//			}
//			if (fruit1_pos[1] == myhead[1]) {
//				fruit_path[2] *= 6;
//			}
//		}
//		// if on the left
//		if (fruit1_pos[0] < myhead[0]) {
//			fruit_path[3] *= 3;
//			if (fruit1_pos[1] < myhead[1]) {
//				fruit_path[0] *= 3;
//			}
//			if (fruit1_pos[1] < myhead[1]) {
//				fruit_path[1] *= 3;
//			}
//			if (fruit1_pos[1] == myhead[1]) {
//				fruit_path[3] *= 6;
//			}
//		}
//	}
//
//	void MyPlayer::GoFruit2(int(&fruit2_pos)[2], int(&myhead)[2], int(&fruit_path)[4]) {
//		if (fruit2_pos[1] < myhead[1]) {
//			fruit_path[0] *= 3;
//			// The fruit is on the right side of the head
//			if (fruit2_pos[0] > myhead[0]) {
//				fruit_path[2] *= 3;
//			}
//			// If the fruit is on the left side of the head
//			if (fruit2_pos[0] < myhead[0]) {
//				fruit_path[3] *= 3;
//			}
//			if (fruit2_pos[0] == myhead[0]) {
//				fruit_path[0] *= 6; // Weighted Upward Movement
//			}
//		}
//		// If the fruit is below the head
//		if (fruit2_pos[1] > myhead[1]) {
//			fruit_path[1] *= 3;
//			// The fruit is on the right side of the head
//			if (fruit2_pos[0] > myhead[0]) {
//				fruit_path[2] *= 3;
//			}
//			// If the fruit is on the left side of the head
//			if (fruit2_pos[0] < myhead[0]) {
//				fruit_path[3] *= 3;
//			}
//			if (fruit2_pos[0] == myhead[0]) {
//				fruit_path[1] *= 6;
//			}
//
//		}
//		// If on the right
//		if (fruit2_pos[0] > myhead[0]) {
//			fruit_path[2] *= 3;
//			if (fruit2_pos[1] < myhead[1]) {
//				fruit_path[0] *= 3;
//			}
//			if (fruit2_pos[1] < myhead[1]) {
//				fruit_path[1] *= 3;
//			}
//			if (fruit2_pos[1] == myhead[1]) {
//				fruit_path[2] *= 6;
//			}
//		}
//		// If on the left
//		if (fruit2_pos[0] < myhead[0]) {
//			fruit_path[3] *= 3;
//			if (fruit2_pos[1] < myhead[1]) {
//				fruit_path[0] *= 3;
//			}
//			if (fruit2_pos[1] < myhead[1]) {
//				fruit_path[1] *= 3;
//			}
//			if (fruit2_pos[1] == myhead[1]) {
//				fruit_path[3] *= 6;
//			}
//		}
//	}
//
//	Direction MyPlayer::selectDirection(
//		int turn, Snake* player_snake, Snake* enemy_snake, std::vector<Fruit*> fruits) {
//
//		int mylen = player_snake->getPositions().size();
//		int enlen = enemy_snake->getPositions().size();
//
//		int myhead[2] = { 0, }; int mytail[2] = { 0, };
//		int enhead[2] = { 0, }; int entail[2] = { 0, };
//
//		int trace[15][15] = { 0, };
//		std::vector<Pos> positions = player_snake->getPositions();
//		myhead[0] = positions[0].x; myhead[1] = positions[0].y;
//		for (int i = 0; i < mylen; ++i) {
//			trace[player_snake->getPositions()[i].y][player_snake->getPositions()[i].x] = 1;
//			if (i == 0) {
//				myhead[0] = positions[i].x;
//				myhead[1] = positions[i].y;
//			}
//			if (i == mylen - 1) {
//				mytail[0] = positions[i].x;
//				mytail[1] = positions[i].y;
//			}
//		}
//
//		std::vector<Pos> en_positions = enemy_snake->getPositions();
//		for (int i = 0; i < enlen; ++i) {	// Store the opponent's body position
//			trace[enemy_snake->getPositions()[i].y][enemy_snake->getPositions()[i].x] = 2;
//			if (i == 0) {
//				enhead[0] = en_positions[i].x;
//				enhead[1] = en_positions[i].y;
//			}
//			if (i == enlen) {
//				entail[0] = en_positions[i].x;
//				entail[1] = en_positions[i].y;
//			}
//		}
//
//		int mydir;	// Save Direction (Up: 2, Down: -2, Right: 1, Bottom: -1)
//		if (player_snake->getDirection().dx == 1) {
//			mydir = 1;
//		}
//		if (player_snake->getDirection().dx == -1) {
//			mydir = -1;
//		}
//		if (player_snake->getDirection().dy == 1) {
//			mydir = 2;
//		}
//		if (player_snake->getDirection().dy == -1) {
//			mydir = -2;
//		}
//
//		// Priority 1 : Do not hit a wall or come into contact with the other body
//
//		int path[4] = { 1, 1, 1, 1 };	// { Up, Down, Right, Left } : 1 allows; 0 does not allow
//
//		if (myhead[1] == 0) {
//			path[0] *= 0;
//			path[1] *= 3;
//			path[2] *= 3;
//			path[3] *= 3;
//		}
//		// If there is a wall or opponent under the head of an object's head
//		if (myhead[1] == 14) {
//			path[1] *= 0;
//			path[0] *= 3;
//			path[2] *= 3;
//			path[3] *= 3;
//		}
//		// If there is a wall or opponent to the right of the object's head
//		if (myhead[0] == 14) {
//			path[2] *= 0;
//			path[0] *= 3;
//			path[1] *= 3;
//			path[3] *= 3;
//		}
//		// If there is a wall or opponent to the left of the object's head
//		if (myhead[0] == 0) {
//			path[3] *= 0;
//			path[0] *= 3;
//			path[1] *= 3;
//			path[2] *= 3;
//		}
//
//
//		if (trace[myhead[1] - 1][myhead[0]] != 0) {
//			path[0] *= 0;
//			path[1] *= 3;
//			path[2] *= 3;
//			path[3] *= 3;
//		}
//		if (trace[myhead[1] + 1][myhead[0]] != 0) {
//			path[1] *= 0;
//			path[0] *= 3;
//			path[2] *= 3;
//			path[3] *= 3;
//		}
//		if (trace[myhead[1]][myhead[0] + 1] != 0) {
//			path[2] *= 0;
//			path[0] *= 3;
//			path[1] *= 3;
//			path[3] *= 3;
//		}
//		if (trace[myhead[1]][myhead[0] - 1] != 0) {
//			path[3] *= 0;
//			path[0] *= 3;
//			path[1] *= 3;
//			path[2] *= 3;
//		}
//
//		// store fruit coordinates
//		int fruit1_pos[2] = { 0, }; int fruit2_pos[2] = { 0, };
//		fruit1_pos[0] = fruits[0]->getPositions()[0].x; fruit1_pos[1] = fruits[0]->getPositions()[0].y;
//		fruit2_pos[0] = fruits[1]->getPositions()[0].x; fruit2_pos[1] = fruits[1]->getPositions()[0].y;
//
//		// Calculate the distance between the head and fruit
//		double dist1 = sqrt(pow((fruit1_pos[0] - myhead[0]), 2) + pow((fruit1_pos[1]) - myhead[1], 2));
//		double dist2 = sqrt(pow((fruit2_pos[0] - myhead[0]), 2) + pow((fruit2_pos[1]) - myhead[1], 2));
//
//		// Design whether the enemy is closer or I am closer
//		double en_dist1 = sqrt(pow((fruit1_pos[0] - enhead[0]), 2) + pow((fruit1_pos[1]) - enhead[1], 2));
//		double en_dist2 = sqrt(pow((fruit2_pos[0] - enhead[0]), 2) + pow((fruit2_pos[1]) - enhead[1], 2));
//
//		//fruit_path[0] = 1;	// { Up, Down, Right, Left } : 1 allows; 0 does not allow
//		int fruit_path[4] = { 1, 1, 1, 1 };
//
//		if (dist1 < en_dist1) {
//			GoFruit1(fruit1_pos, myhead, fruit_path);
//		}
//		else if (dist1 > en_dist1) {
//			GoFruit2(fruit2_pos, myhead, fruit_path);
//		}
//		else if (dist1 == en_dist1) {
//			if (LongerThanEn(mylen, enlen) == true) {
//				GoFruit1(fruit1_pos, myhead, fruit_path);
//			}
//			else { GoFruit2(fruit2_pos, myhead, fruit_path); }
//		}
//
//		if (dist2 < en_dist2) {
//			GoFruit2(fruit2_pos, myhead, fruit_path);
//		}
//		else if (dist2 > en_dist2) {
//			GoFruit1(fruit1_pos, myhead, fruit_path);
//		}
//		else if (dist2 == en_dist2) {
//			if (LongerThanEn(mylen, enlen) == true) {
//				GoFruit2(fruit2_pos, myhead, fruit_path);
//			}
//			else { GoFruit1(fruit1_pos, myhead, fruit_path); }
//		}
//
//		int dir[4] = { 0, };
//		for (int i = 0; i < 4; ++i) {
//			dir[i] = path[i] * fruit_path[i];
//		}
//
//		int max = 0; int idx = 0;
//		for (int i = 0; i < 4; ++i) {
//			if (max < dir[i]) {
//				max = dir[i];
//				idx = i;
//			}
//		}
//
//		if (idx == 0) {
//			return DrtN();
//		}
//		if (idx == 1) {
//			return DrtS();
//		}
//		if (idx == 2) {
//			return DrtE();
//		}
//		if (idx == 3) {
//			return DrtW();
//		}
//	}
//}
