#include <iostream>

using namespace std;

struct item {
	int diceNumber = 0; // for the damadge of the item
	int damadgeBlock = 0; //for the shield
	int amount = 1; 
};


struct entity {
	int health = 0; 
	string classType = "null"; //null as a lot of creatures wont have a class
	int damadge = 0; // used fo rthe rats to have a damadge with no items
};

// class options for the user
string classes[3] = { "knight", "warrior", "archer" };
