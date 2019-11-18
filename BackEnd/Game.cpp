#include "Game.h"

Game::Game() {

}

Game::~Game() {
	for (auto x : animal)
		delete x;
	for (auto x : vehicle)
		delete x;
}

void Game::draw() {
	//Ponk long xien
}