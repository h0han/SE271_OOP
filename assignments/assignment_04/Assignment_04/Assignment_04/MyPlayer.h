#pragma once
////////////////////////////////////////////////////////////////////////////////
// SE271 - Assignment 4: Snake Arena
// Note: You WILL SUBMIT THIS FILE !!!
// Implement your strategy, whatever you want
// You can modify anything as long as it can be compiled with the provided code
// The current implementation simplely rotates the snake every turn
////////////////////////////////////////////////////////////////////////////////

#include "Player.h"
#include "Commons.h"

#include <string>

#define MyPlayer		Player201911189		// CHANGE THIS: Your StudentID 
#define PLAYER_NAME		"YNG"	// CHANGE THIS: Name your player

namespace snake_arena {
	class MyPlayer final : public Player {
	public:
		MyPlayer(int map_size);
		virtual ~MyPlayer() override;

		virtual std::string getName() const { return PLAYER_NAME; }
		virtual Direction selectDirection(
			int turn, Snake* player_snake, Snake* enemy_snake,
			std::vector<Fruit*> fruits);
	private:
		bool LongerThanEn(int mylen, int enlen);
		void GoFruit1(int(&fruit1_pos)[2], int(&myhead)[2], int(&fruit_path)[4]);
		void GoFruit2(int(&fruit2_pos)[2], int(&myhead)[2], int(&fruit_path)[4]);
		void GoTail(int(&tail_pos)[2], int(&myhead)[2], int(&tail_path)[4]);
	};
}
