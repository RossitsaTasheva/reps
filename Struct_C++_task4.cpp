//============================================================================
// Name        : lib_task4.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*4. lib function that produces quotient and reminder
 * (returning struct)*/
struct PlayerInfo {
	int skill_level;
	string name;
};
struct EnemyShip {
	int x_coordinate;
	int y_coordinate;
	int weapon_power; //Сила на оръжието
};

EnemyShip getNewEnemy() {
	EnemyShip ship;
	ship.x_coordinate = 0;
	ship.y_coordinate = 0;
	ship.weapon_power = 20;
	return ship;
}

EnemyShip upgradeWeapons(EnemyShip ship) {
	ship.weapon_power += 10;
	return ship;
}

int main() {

	PlayerInfo players[5];
	for (int i = 0; i < 5; i++) {
		cout << "Please enter the name for player : " << i << '\n';

		cin >> players[i].name;
		cout << "Please enter the skill level for " << players[i].name << '\n';
		cin >> players[i].skill_level;
	}
	for (int i = 0; i < 5; ++i) {
		cout << players[i].name << " is at skill level "
				<< players[i].skill_level << '\n';
	}

	EnemyShip enemy = getNewEnemy();
	enemy = upgradeWeapons(enemy);

//
//   div_t output;
//
//   output = div(27, 4);
//   cout<<"Quotient part of (27/ 4) = %d"<<endl<< output.quot;//Частична част от
//   cout<<"Remainder part of (27/4) = %d"<<endl<< output.rem;//Останалата част от

	return (0);
}
