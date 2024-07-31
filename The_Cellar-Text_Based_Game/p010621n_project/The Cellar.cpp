//project: The Cellar
#include "ASCII_art.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <conio.h>
#include "itmes_and_entities.h"

using namespace std;

bool gameStarted = false; //condiiton for main menu
bool gameOver = false; // condition for game loop
bool playerDead = false; // condition for end screen

// random number generator for dice roll 
random_device device;  //for RNG
mt19937 randomGenerator(device()); 

// use random(min, max) for number
int random(int min, int max) {
    // orders the numbers so error doesn't occur
    int trueMin = std::min(min, max);
    int trueMax = std::max(max, min);
    // create  arandom number in distributed set
    uniform_int_distribution<int> udist(trueMin, trueMax);
    return udist(randomGenerator);
}

// ACTIONS
//attack
void attack(int& a, int& b, string playerClass, int turn) {
    int damadge = random(1, a); //make a random number up to a max o fthe dice number
    if (turn % 2 == 1) { // shield block 4 damadge
        if (playerClass == classes[0]) {
            damadge = damadge - 4;
            if (damadge < 0) {
                damadge = 0; //prevents damadge form becoming negative and accidently adding health to the enemy
            }
        }
    }
    b = b - damadge; // deal damadge to the enemy
}

//use a healing potion
void heal(int& a, int& b) {
    if (a == 0) { //if out of potions it wont work
        cout << "not possible. You are out of potions." << endl;
    }
    else {
        b = b + 20; //add 20 health to the player
        if (b > 100) { // will only heal up to a max of 100
            b = 100;
        }
        a = a - 1; //subtract one form the potion amount
        cout << "You healed 20 health. You have " << a << " potions left." << endl;
    }
}



// display the first screen and the title page
void mainMenu() {
    mainMenuASCII();
    cout << "press ENTER to start" << endl;
    while (gameStarted == false) {
        char temp = _getch(); //get a temporary input that updates as the keyboard is pressed
        if (temp == 13) { // if pressed enter, end the loop and start the game
            system("cls");
            gameStarted = true;
        }
        else {
            system("cls");  // clear screen so it doesn't stack on top of each other
            mainMenuASCII();
            cout << "press ENTER to start" << endl;
        }
    }
}

// screen showed on player death
void deathScreen() {
    system("cls");
    deathScreenASCII();
    cout << "You have failed your king" << endl;
    cout << "press ENTER to try again" << endl; 
    while (playerDead == true) {
        char temp = _getch(); //get a temporary input that updates as the keyboard is pressed
        if (temp == 13) { // if pressed enter, go back to start screen
            system("cls");
            gameStarted = false;
            playerDead = false;
        }
        else {
            system("cls");  // clear screen so it doesn't stack on top of each other
            deathScreenASCII();
            cout << "You have failed your king" << endl;
            cout << "press ETNER to try again" << endl;
        }
    }
}

// Win page
void winPage() {
    bool kingPageLoopCondition = false; //conditions for each page to show until enter pressed
    bool winPageLoopCondition = false;
    system("cls");
    kingNPCASCII(); //display the king and text
    cout << "It's the king." << endl << endl;
    cout << "Greetings my loyal subject and thank you. I owe you a great favour for saving me and my castle. You shall be bestowed " << endl;
    cout << "wealth and land for your brave actions and show of strength. As for the wizard... well he wont be practicing much " << endl;
    cout << "magic any time soon. So I thank you once more and bid you farewell." << endl;
    cout << "Press ENTER to continue" << endl;
    while (kingPageLoopCondition == false) {
        char temp = _getch(); //get a temporary input that updates as the keyboard is pressed
        if (temp == 13) { // if pressed enter, go to win text
            system("cls");
            gameStarted = false;
            kingPageLoopCondition = true;
        }
        else {
            system("cls");  // clear screen so it doesn't stack on top of each other
            kingNPCASCII();
            cout << "Greetings my loyal subject and thank you. I owe you a great favour for saving me and my castle. You shall be bestowed " << endl;
            cout << "wealth and land for your brave actions and show of strength. As for the wizard... well he wont be practicing much " << endl;
            cout << "magic any time soon. So i thank you once more and bid you farewell." << endl;
            cout << "Press ENTER to continue" << endl;
        }
    }
    system("cls");
    winPageASCII();
    cout << "press ENTER to restart" << endl;
    while (winPageLoopCondition == false) {
        char temp = _getch(); //get a temporary input that updates as the keyboard is pressed
        if (temp == 13) { // if pressed enter, go back to start screen
            system("cls");
            gameStarted = false;
            winPageLoopCondition = true;
        }
        else {
            system("cls");  // clear screen so it doesn't stack on top of each other
            winPageASCII();
            cout << "press ETNER to restart" << endl;
        }
    }

}

// npc at the start
void kingsWizardNPC(string& a) {  // pass the player class variable into the function
    string input;
    bool inputValid = false; //check condition for loops and inputs
    kingsWizardNPCASCII();
    // story explanation
    cout << "Greetings fair player. I am the king's wizard and BOY am I happy to see you." << endl;
    cout << "See, the king currently has a... problem." << endl << endl;
    cout << "There's a... rat king in his basement. WHICH IS DEFINETLY NOT MY FAULT" << endl;
    cout << "But lucky for you, you just got hired to kill the rat" << endl << endl;
    cout << "1. What do you mean rat king?\t2. Not your fault? \t3. LUCKY ME?!\t4. Hell yeah! lets kick some rat butt" << endl;

    // story progression and input check per response
    while (inputValid == false) {
        cin >> input;
        if (input == "1") {
            system("cls");
            kingsWizardNPCASCII();
            cout << "well... its like a giant rat that wears a crown. A big scary rodent... thing" << endl; 
            cout << "But more importantly, YOU are the saviour who has been selected to kill it" << endl << endl;
            cout << "1. Why am I the selected one\t2. So.... how do we do this." << endl;
            while (inputValid == false) {
                cin >> input;
                if (input == "1") {
                    inputValid = true;
                    system("cls");
                    kingsWizardNPCASCII();
                    cout << "Well it was definitly a random selection and not just whoever walked by first" << endl << endl;
                }
                else if (input == "2") {
                    system("cls"); 
                    kingsWizardNPCASCII(); 
                    inputValid = true;
                    cout << "With great difficulty." << endl << endl;
                }
                else {
                    cout << "I'm sorry, what??? (please input a number that is valid)" << endl;                       
                }       
            }
        } 
        else if (input == "2") { 
            system("cls");
            kingsWizardNPCASCII();
            cout << "Yes. It is 100% not my fault. What are you trying to incinuate?" << endl << endl; 
            cout << "1. No, no. I'm not suggesting anything\t 2. That you caused this and you need me to clean it up" << endl;
            while (inputValid == false) {
                cin >> input;
                if (input == "1") {
                    inputValid = true;
                    system("cls");
                    kingsWizardNPCASCII();
                    cout << "Good. You better not be... or I would have to incinerate you." << endl << endl;
                }
                else if (input == "2") {
                    system("cls");
                    kingsWizardNPCASCII();
                    inputValid = true;
                    cout << "Well you're wrong! Anymore of that and I will end you right here." << endl << endl;
                }
                else {
                    cout << "I'm sorry, what??? (please input a number that is valid)" << endl;
                }
            }
        } 
        else if (input == "3") {
            inputValid = true;
            system("cls");
            kingsWizardNPCASCII();
            cout << "Yyyyeesss... lucky you. You have been... graced with the... ability to see the kings cellar" << endl << endl;
        }
        else if (input == "4") {
            inputValid = true;
            system("cls");
            kingsWizardNPCASCII();
            cout << "Thats the spirit! Its totally not really dangerous and deadly." << endl << endl;
        }
        else{
            cout << "I'm sorry, what??? (please input a number that is valid)" << endl;
        }
    }
    inputValid = false; //set the condition back to false

    //class selection
    cout << "Anywayyyyy... I have a few sets of items that you can use to aid your adventure" << endl;
    cout << "Imagine it like a \"class\" system. I hate that word." << endl;
    cout << "You don't look very magical so....  do you feel more like a knight, a warrior or an archer?" << endl << endl;
    cout << "1. Knight\t2. Warrior\t3. Archer" << endl;
    while (inputValid == false) {
        cin >> input;
        if (input == "1") {
            inputValid = true;
            a = classes[0];
            system("cls");
            swordAndShieldASCII();
            cout << "A brilliant choice! I grant you a short sword and a shield. This short sword will strike the rats in the heart." << endl;
            cout << "This shield shall block some of the incoming damage. Easy to wield and light to swing. I will also give you 5 health potions." << endl << endl;
        }
        else if (input == "2") {
            inputValid = true;
            a = classes[1];
            system("cls");
            greatswordASCII();
            cout << "Aahh.. a strong man huh. I will give you this greatsword. A large, strong two handed sword that was forged under " << endl;
            cout << "an immense heat. This blade will smite the enemies in your path. I will also give you 5 health potions." << endl << endl;
        }
        else if (input == "3") {
            inputValid = true;
            a = classes[2];
            system("cls");
            bowAndArrowASCII();
            cout << "Okay... I shall grant you this bow. A strong wooden bow with 99 arrows. The potential for a piercing shot to be " << endl;
            cout << "fired at great speed. A dangerous weapon, if in a skilled person's hands. I will also give you 5 health potions." << endl << endl;
        } 
        else {
            cout << "I'm sorry that wasn't an option (input a valid number)" << endl;
        }
        inputValid = false; // reset input check


        // start the first room
        cout << "Now to explain what you need to do. You will go into the king's cellar and traverse it until you find the rat king." << endl;
        cout << "If I remember correctly, it should be 10 rooms. Be warned there are some traps down there. You know... incase " << endl;
        cout << "intruders got in. When you find the rat king, you will need to kill it. It's as simple as that right. You ready?" << endl << endl;
        cout << "1. Yes\t2. No" << endl;
        while (inputValid == false) {
            cin >> input;
            if (input == "1") {
                inputValid = true;
                cout << "perfect, in you go. (press ENTER to continue)" << endl;  
                bool temp = false;
                while (temp == false) {
                    char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                    if (tempTwo == 13) { // if pressed enter, end the loop and start the game
                        system("cls"); //clear screen for first room
                        temp = true;
                    }
                }
            }
            else if (input == "2") {
                inputValid = true;
                cout << "well... you don't really have a choice." << endl;
                cout << "You feel a hand on your back as the wizard pushes you in and closes the door. (press ENTER to continue)" << endl;
                bool temp = false;
                while (temp == false) {
                    char tempTwo = _getch();
                    if (tempTwo == 13) { 
                        system("cls");
                        temp = true;
                    }
                }
            }
            else {
                cout << "What was that, I asked for a yes or a no (input a valid number)" << endl; //loop until valid input
            }
        }
    }
}

// first room - fight 1 - one small rat
void roomOne(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratHealth, int ratDamadge) {
    string actionInput; //input for user
    int turnTimer = 0; //to tale turns from player to rat
    playerHealth = 100; //sets in first room so on restart that it will restart the player health too
    ratHealth = 15;
    potionAmount = 5; // set the potions back to 5
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl; //displays current HP and potion amount on the top
    oneSmallRatASCII();
    cout << "Small Rat: " << ratHealth << "/15" << endl; //displays rat health under rat
    cout << "As your eyes adjust to the sudden darkness, you notice a couple torches on the walls of the stone cellar." << endl;
    cout << "A small rat stands infront of the door forward. The rat king must be deeper in the cellar." << endl;
    cout << "And theres only one way forward." << endl;


    // combat loop, ends if either player or rat die
    while ((ratHealth > 0) && (playerHealth > 0)) { 
        while (turnTimer % 2 == 0) { //alternates with even to odd turn number
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") { //attack, different number based on class and weapons chosen
                if (playerClass == classes[0]) {
                    attack(shortsword, ratHealth, playerClass, turnTimer); //calls attack function
                    turnTimer++;
                }
                else if (playerClass == classes[1]) {
                    attack(greatsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else {
                    attack(bow, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
            } //heals
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }
        system("cls");
        if (ratHealth > 0) { // rat attacks the player
            attack(ratDamadge, playerHealth, playerClass, turnTimer); 
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            oneSmallRatASCII();
            cout << "Small Rat: " << ratHealth << "/15" << endl;
            cout << "The small rat attacks you" << endl;
            turnTimer++;
        }
    }
    if (playerHealth <= 0) { //rat has died and player moves on
        playerDead = true; //if rat has won
    }
    else {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
        oneSmallRatASCII();
        cout << "Small Rat: " << ratHealth << "/15" << endl;
        cout << "The rat was beaten. You can now move on to room two." << endl;
        cout << "Press ENTER to continue" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop and move to room 2
                system("cls"); //clear screen
                temp = true;
            }
        }  
        
    }

}

// second room - fight 2 - one small rat    similar to room one
void roomTwo(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratHealth, int ratDamadge) {
    string actionInput;
    int turnTimer = 0;
    ratHealth = 15; //reset the health of the rat for the room
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    oneSmallRatASCII();
    cout << "Small Rat: " << ratHealth << "/15" << endl;
    cout << "You step over the dead rat and enter the second. You look around and you meet the eyes of another small rat in " << endl;
    cout << "the back left corner. You ready your weapon and prepare for another fight... You sense this might be a pattern." << endl;

    while ((ratHealth > 0) && (playerHealth > 0)) {
        while (turnTimer % 2 == 0) {
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") {
                if (playerClass == classes[0]) {
                    attack(shortsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else if (playerClass == classes[1]) {
                    attack(greatsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else {
                    attack(bow, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
            }
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }
        system("cls");
        if (ratHealth > 0) {
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            oneSmallRatASCII();
            cout << "Small Rat: " << ratHealth << "/15" << endl;
            cout << "The small rat attacks you" << endl;
            turnTimer++;
        }
    }
    if (ratHealth <= 0) {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
        oneSmallRatASCII();
        cout << "Small Rat: " << ratHealth << "/15" << endl;
        cout << "The rat was beaten. You can now move on to room three." << endl;
        cout << "Press ENTER to continue" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop 
                system("cls"); //clear screen for room 3 
                temp = true;
            }
        }
    }
    else {
        playerDead = true;
    }
}

// third room - trap
void roomThree(int& playerHealth, int& potionAmount) {
    bool inputValid = false;
    string userInput;
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    trapASCII();
    cout << "The first thing you notice as you enter room three is the lack of rat. Instead there are several holes in the floor " << endl;
    cout << "infront of the door to room four. But what were they there for, and what should you do?" << endl;
    cout << "1. Approach slowly\t 2. Try and run past it into the next room" << endl;
    while (inputValid == false) {    
        cin >> userInput;
        if (userInput == "1") {  //avoid the spikes
            inputValid = true;
            system("cls");
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            spikeASCII();
            cout << "As you approach the door, several spikes shoot up out the ground where the holes once were. Thankfully they all " << endl;
            cout << "triggered early as you approached slowly and you can just step over them to get to room four. A narrow escape..." << endl;
            cout << "Press ENTER to go into room 4" << endl;
            bool temp = false;
            while (temp == false) {
                char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                if (tempTwo == 13) { // if pressed enter, end the loop and start the game
                    system("cls"); //clear screen for room 4 
                    temp = true;
                }
            }
        }
        else if (userInput == "2") {   //hit by the spikes, doing 25 damadge
            inputValid = true;
            playerHealth = playerHealth - 25;
            system("cls");
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            spikeASCII();
            cout << "As you started to run up to the door and get past the holes, sharp spikes emerged from the floor and stabbed into " << endl;
            cout << "your foot. You look back on your decision with regret and 25 less health... and continue on." << endl;
            cout << "Press ENTER to go into room 4" << endl; 
            bool temp = false;
            while (temp == false) {
                char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                if (tempTwo == 13) { // if pressed enter, end the loop
                    system("cls"); //clear screen for room 4 
                    temp = true;
                }
            }
        }
        else {
            cout << "That isn't possible (input a valid option, 1 or 2)" << endl;
        }
    }
}

// fourth room - fight 3- one big rat
void roomFour(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratHealth, int ratDamadge) {
    string actionInput;
    int turnTimer = 0;
    ratHealth = 30; //reset the health of the rat for the room
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    bigRatASCII();
    cout << "big Rat: " << ratHealth << "/30" << endl;
    cout << "You continue on into room four, and meet an abomination. A obscenly large rat stands before you. He looks the same " << endl;
    cout << "height as you. You're not sure if you will make it out of this one, but you have few options. Onward you must go and " << endl;
    cout << "this rat is in the way. You worry about the size of the rat king." << endl;

    while ((ratHealth > 0) && (playerHealth > 0)) { // run the combat loop until either the rat or the player has died
        while (turnTimer % 2 == 0) {
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") {
                if (playerClass == classes[0]) {
                    attack(shortsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else if (playerClass == classes[1]) {
                    attack(greatsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else {
                    attack(bow, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
            }
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }
        system("cls");
        if (ratHealth > 0) {
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            bigRatASCII();
            cout << "Big Rat: " << ratHealth << "/30" << endl;
            cout << "The Big rat attacks you" << endl;
            turnTimer++;
        }
    }
    if (ratHealth <= 0) {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
        bigRatASCII();
        cout << "Big Rat: " << ratHealth << "/30" << endl;
        cout << "The big rat was beaten. You feel like it is unnatural for rats to be this large without magic. " << endl;
        cout << "However, you can now move on to room five." << endl;
        cout << "Press ENTER to continue" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop 
                system("cls"); //clear screen for room 5
                temp = true;
            }
        }
    }
    else {
        playerDead = true;
    }
}


// fifth room - rest room, fountain
void roomFive(int& playerHealth, int& potionAmount) {
    bool inputValid = false;
    string userInput;
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    fountainASCII();  // display the foutnain ASCII art, then dsiplay the text beneathe it
    cout << "As you walk into room five, you hear the rushing sounds of water. You notice a faint pink glow coming from your right " << endl;
    cout << "as you get through the door frame. You turn to see a beautiful fountain erupting water at the top. A glowing pink heart " << endl;
    cout << "sits on the base of the fountain. You step closer and feel a couple droplets splash on your face. It's refreshing." << endl;
    cout << "Is it safe to drink... it seems kinda sketchy being down here with the rats." << endl;
    cout << "1.Drink from the fountain\t2. ignore the fountain and go to room 6" << endl;
    while (inputValid == false) {
        cin >> userInput;
        if (userInput == "1") { //heal 25 health at the fountain
            inputValid = true;
            system("cls");
            playerHealth = playerHealth + 25; //keep saty the max health of 100 if going over when healed
            if (playerHealth > 100) {
                playerHealth = 100;
            }
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            fountainASCII();
            cout << "The cool water runs down your throat and you feel refreshed. A nice break from all the combat and rats. You take a " << endl;
            cout << "well needed rest and sit down. You are healed 25 health." << endl;
            cout << "Press ENTER to continue into room six" << endl;
            bool temp = false;
            while (temp == false) {
                char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                if (tempTwo == 13) { // if pressed enter, end the loop 
                    system("cls");
                    temp = true;
                }
            }
        }
        else if (userInput == "2") { //no health change
            inputValid = true;
            system("cls");
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            fountainASCII();
            cout << "You decide that it seems to good too be true. Clean water amongst all these rats, they've probably gone into it to " << endl;
            cout << "wash or drink. It just seems unsanitary and best to leave it. " << endl;
            cout << "Press ENTER to continue on to room six" << endl;
            bool temp = false;
            while (temp == false) {
                char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                if (tempTwo == 13) { // if pressed enter, end the loop 
                    system("cls");
                    temp = true;
                }
            }
        }
        else { //waits for a valid input
            cout << "Input invalid, plese input either 1 or 2" << endl;
        }
    }
}

//sixth room - fight 4 - two small rats
void roomSix(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratOneHealth, int&ratTwoHealth, int ratDamadge) {
    string actionInput;
    string ratSelection; //used when selecting which enemy to hit
    int turnTimer = 0;
    ratOneHealth = 15; //reset the health of the rats for the room
    ratTwoHealth = 15;
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    twoSmallRatsASCII();
    cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15" << endl;
    cout << "You continue on into room six, and you enter a room with more enemies than before. Two small rats stand before you. " << endl;
    cout << "They look the same size as the smaller ones as before, not as scary as that giant thing but there are 2 of them. " << endl;
    cout << "Which to go for first?" << endl;

    while (((ratOneHealth > 0) || (ratTwoHealth > 0)) && (playerHealth > 0)) { // run the combat loop until either the rats or the player has died
        while (turnTimer % 2 == 0) {
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") {
                cout << "1. Rat 1 \t 2. Rat 2" << endl;
                cin >> ratSelection;
                if (ratSelection == "1") { //only damdges the first rat
                    if (ratOneHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "that rat is dead, please input again" << endl;
                        continue;
                    }
                }
                else if (ratSelection == "2") { //only damadges the second rat
                    if (ratTwoHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "That rat is already dead, please input again" << endl;
                    }
                }
                else {
                    cout << "That isn't a valid target (input a valid input, either 1 or 2)" << endl;
                }
            }
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }

        system("cls");
        if ((ratOneHealth > 0) && (ratTwoHealth > 0)) { //checks to see which rats are alive to attack
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            twoSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The first small rat attacks you" << endl;
            cout << "The second small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (ratTwoHealth <= 0)) {
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            twoSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratTwoHealth > 0) && (ratOneHealth <= 0)) {
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            twoSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The Second Small rat attacks you" << endl;
            turnTimer++;   
        }

    }
    if ((ratOneHealth <= 0) && (ratTwoHealth <= 0)) {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
       twoSmallRatsASCII();
       cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15" << endl;
        cout << "You have bested both of the rats and the path to room seven is now free. You hope that there are" << endl;
        cout << "no more hoards of enemies like this, 1 was more than enough let alone 2 or more. You head on." << endl;
        cout << "Press ENTER to continue" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop 
                system("cls"); //clear screen for room 7
                temp = true;
            }
        }
    }
    else {
        playerDead = true;
    }
}

// seventh room - fight 5 - three small rats
void roomSeven(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratOneHealth, int& ratTwoHealth, int& ratThreeHealth, int ratDamadge) {
    string actionInput;
    string ratSelection; //used when selecting which enemy to hit
    int turnTimer = 0;
    ratOneHealth = 15; //reset the health of the rats for the room
    ratTwoHealth = 15;
    ratThreeHealth = 15;
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    threeSmallRatsASCII();
    cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
    cout << "You enter room 7 and you find exactly what you didn't want to, three small rats. You feared these groups would get " << endl;
    cout << "bigger. They look the same size as before so still not scary but certainly more threatening that the last room. But " << endl;
    cout << "you must go on. Which to go for first?" << endl;

    while (((ratOneHealth > 0) || (ratTwoHealth > 0) || (ratThreeHealth > 0)) && (playerHealth > 0)) { // run the combat loop until either the rats or the player has died
        while (turnTimer % 2 == 0) {
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") {
                cout << "1. Rat 1 \t 2. Rat 2\t 3. Rat 3" << endl;
                cin >> ratSelection;
                if (ratSelection == "1") { //only damdges the first rat
                    if (ratOneHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "that rat is dead, please input again" << endl;
                        continue;
                    }
                }
                else if (ratSelection == "2") { //only damadges the second rat
                    if (ratTwoHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "That rat is already dead, please input again" << endl;
                    }
                }
                else if (ratSelection == "3") { //only damadges the third rat
                    if (ratThreeHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratThreeHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratThreeHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratThreeHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "That rat is already dead, please input again" << endl;
                    }
                }
                else {
                    cout << "That isn't a valid target (input a valid input, either 1 or 2)" << endl;
                }
            }
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }

        system("cls");
        if ((ratOneHealth > 0) && (ratTwoHealth > 0) && (ratThreeHealth > 0)) { //checks to see which rats are alive to attack, three rats alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The first small rat attacks you" << endl;
            cout << "The second small rat attacks you" << endl;
            cout << "The third small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (ratTwoHealth <= 0) && (ratThreeHealth > 0)) { //1 and 3 alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            cout << "The third small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (ratTwoHealth > 0) && (ratThreeHealth <= 0)) { //1 and 2 alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            cout << "The Second small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (ratTwoHealth <= 0) && (ratThreeHealth <= 0)) { //1 is alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth <= 0) && (ratTwoHealth > 0) && (ratThreeHealth > 0)) { //2 and 3 are alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The Second small rat attacks you" << endl;
            cout << "The third small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth <= 0) && (ratTwoHealth > 0) && (ratThreeHealth <= 0)) { // 2 is alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The Second small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth <= 0) && (ratTwoHealth <= 0) && (ratThreeHealth > 0)) { // 3 is alive
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            threeSmallRatsASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
            cout << "The third Small rat attacks you" << endl;
            turnTimer++;
        }
    }
    if (playerHealth <= 0) {
        playerDead = true;
    }
    else {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
        threeSmallRatsASCII();
        cout << "Small Rat: " << ratOneHealth << "/15\t Small Rat: " << ratTwoHealth << "/15\t Small Rat: " << ratThreeHealth << "/15" << endl;
        cout << "You were finally able to strike down the last rat of the group and clear the way. This is getting" << endl;
        cout << "very dangerous now. Three at once is very hard and there are still 3 rooms left. You fear for the " << endl;
        cout << "future, but your quest is not finished yet so you press on to room 8" << endl;
        cout << "Press ENTER to continue" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop 
                system("cls"); //clear screen for room 8
                temp = true;
            }
        }
    }
}

// eigth room - dead adventurer
void roomEight(int& playerHealth, int& potionAmount) {
    bool inputValid = false;
    string userInput;
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    deadNPCASCII();
    cout << "You enter room eight and encounter a foul smell. A rotting corpse is lying in the corner and it has clearly been there " << endl;
    cout << "for quite some time. It has a bite taken out of the legs and hands as the rats have been using it for food. Some form of " << endl;
    cout << "Yellow fungus is coming out of one of the bit off fingers. A horrible sight, but potentially might have something " << endl;
    cout << "that could help you on your quest and help kill the rat king. They look like some kind of adventurer, how many have " << endl;
    cout << "been sent down before you... either way it might be helpful, but it looks diseased." << endl;
    cout << "1. Loot the advnturer\t2. Leave the corpse alone" << endl;
    while (inputValid == false) {
        cin >> userInput;
        if (userInput == "1") { //gain one poiton from the corpse
            inputValid = true;
            system("cls");
            potionAmount++;
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            deadNPCASCII();
            cout << "You approach the body and the stench is horrible. You cautiously start pressing at pockets and check the weapons. " << endl;
            cout << "he seems to have the same equipment as you, confirming that they were also sent down by the wizard. you feel this " << endl;
            cout << "is not the first time this has happened and that this person has been here for a while. You do hear some glass as " << endl;
            cout << "you tap the left breast pocket. You reach in and find a health potion. At least there was some benefit to this." << endl;
            cout << "press ENTER to move to room nine." << endl;
            bool temp = false;
            while (temp == false) {
                char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                if (tempTwo == 13) { // if pressed enter, end the loop and move to room nine
                    system("cls");
                    temp = true;
                }
            }
        }
        else if (userInput == "2") { //no health change
            inputValid = true;
            system("cls");
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            deadNPCASCII();
            cout << "You decide that this is a rotting corpase and not a good idea to go and touch it. Who knows what kind of disease " << endl;
            cout << "you could get from this thing. I mean the rats have started eating it, it can not be okay to touch. " << endl;
            cout << "Press ENTER to continue on to room nine" << endl;
            bool temp = false;
            while (temp == false) {
                char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
                if (tempTwo == 13) { // if pressed enter, end the loop
                    system("cls");
                    temp = true;
                }
            }
        }
        else { //waits for a valid input
            cout << "Input invalid, plese input either 1 or 2" << endl;
        }
    }
}

// ninth room - fight 6 - two small, one big rat
void roomNine(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratOneHealth, int& ratTwoHealth, int& bigRatHealth, int smallRatDamadge, int bigRatDamadge) {
    string actionInput;
    string ratSelection; //used when selecting which enemy to hit
    int turnTimer = 0;
    ratOneHealth = 15; //reset the health of the rats for the room
    ratTwoHealth = 15;
    bigRatHealth = 30;
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    roomNineASCII();
    cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
    cout << "You enter room 9 and meet the worst thing yet. A group of 2 small and one very large rat. This is going to be it, this is too much. " << endl;
    cout << "They look the same size as the ones encoutered earlier and back in room 4. You did it once before, its just once more and then the last room " << endl;
    cout << "Which to go for first, I mean does it matter, you've got to get through. You have to or You'll die?" << endl;

    while (((ratOneHealth > 0) || (ratTwoHealth > 0) || (bigRatHealth > 0)) && (playerHealth > 0)) { // run the combat loop until either the rats or the player has died
        while (turnTimer % 2 == 0) {
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") {
                cout << "1. small Rat 1 \t 2. Large Rat\t 3. Small Rat 2" << endl;
                cin >> ratSelection;
                if (ratSelection == "1") { //only damdges the first rat
                    if (ratOneHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratOneHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "that rat is dead, please input again" << endl;
                        continue;
                    }
                }
                else if (ratSelection == "2") { //only damadges the second rat
                    if (bigRatHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, bigRatHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, bigRatHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, bigRatHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "That rat is already dead, please input again" << endl;
                    }
                }
                else if (ratSelection == "3") { //only damadges the third rat
                    if (ratTwoHealth > 0) {

                        if (playerClass == classes[0]) {
                            attack(shortsword, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else if (playerClass == classes[1]) {
                            attack(greatsword, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                        else {
                            attack(bow, ratTwoHealth, playerClass, turnTimer);
                            turnTimer++;
                        }
                    }
                    else {
                        cout << "That rat is already dead, please input again" << endl;
                    }
                }
                else {
                    cout << "That isn't a valid target (input a valid input, either 1 or 2)" << endl;
                }
            }
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }

        system("cls");
        if ((ratOneHealth > 0) && (bigRatHealth > 0) && (ratTwoHealth > 0)) { //checks to see which rats are alive to attack, all three rats alive
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            attack(bigRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The first small rat attacks you" << endl;
            cout << "The large rat atttacks you" << endl;
            cout << "The second small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (bigRatHealth <= 0) && (ratTwoHealth > 0)) { //1 and 3 alive
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            cout << "The second small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (bigRatHealth > 0) && (ratTwoHealth <= 0)) { //1 and 2 alive
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            attack(bigRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            cout << "The Big rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth > 0) && (bigRatHealth <= 0) && (ratTwoHealth <= 0)) { //1 is alive
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The first Small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth <= 0) && (bigRatHealth > 0) && (ratTwoHealth > 0)) { //2 and 3 are alive
            attack(bigRatDamadge, playerHealth, playerClass, turnTimer);
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The Big rat attacks you" << endl;
            cout << "The second small rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth <= 0) && (bigRatHealth > 0) && (ratTwoHealth <= 0)) { // 2 is alive
            attack(bigRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The big rat attacks you" << endl;
            turnTimer++;
        }
        else if ((ratOneHealth <= 0) && (bigRatHealth <= 0) && (ratTwoHealth > 0)) { // 3 is alive
            attack(smallRatDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            roomNineASCII();
            cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
            cout << "The second small rat attacks you" << endl;
            turnTimer++;
        }
    }
    if ((ratOneHealth <= 0) && (bigRatHealth <= 0) && (ratTwoHealth <= 0)) {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
        roomNineASCII();
        cout << "Small Rat: " << ratOneHealth << "/15\t Large Rat: " << bigRatHealth << "/30\t Small Rat: " << ratTwoHealth << "/15" << endl;
        cout << "You were finally able to strike down the last rat of the group and clear the way. This is getting" << endl;
        cout << "very dangerous now. Three at once is very hard and there is still 3 rooms left. You fear for the " << endl;
        cout << "future, but your quest is not finished yet so you press on to room 8" << endl;
        cout << "Press ENTER to continue" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop 
                system("cls"); //clear screen for room 10
                temp = true;
            }
        }
    }
    else {
        playerDead = true;
    }
}

// tenth room - rat king
void roomTen(int& playerHealth, string playerClass, int shortsword, int greatsword, int bow, int shield, int& potionAmount, int& ratHealth, int ratDamadge) {
    string actionInput;
    int turnTimer = 0;
    ratHealth = 50; //reset the health of the rat for the room
    cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
    ratKingASCII();
    cout << "Rat King: " << ratHealth << "/50" << endl;
    cout << "You enter the last room of this crazy journey and gasp in the horror of what stands before you. A GIANT rat with the " << endl;
    cout << "imprint of a crown on its side. Easily 20 foot long, and 8 foot tall. He towers over you and then he turns his head. " << endl;
    cout << "Bright yellow eyes staring into your soul and he screams an ear-percing shriek. This is it. This is the whole point " << endl;
    cout << "of this random and strange day. From the wizard to the smaller rats and now this. This is the end. You brandish " << endl;
    cout << "your weapon for one final time. This is the fight of your life." << endl;

    while ((ratHealth > 0) && (playerHealth > 0)) { // run the combat loop until either the rat or the player has died
        while (turnTimer % 2 == 0) {
            cout << "1.Attack\t2. Heal" << endl;
            cin >> actionInput;
            if (actionInput == "1") {
                if (playerClass == classes[0]) {
                    attack(shortsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else if (playerClass == classes[1]) {
                    attack(greatsword, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
                else {
                    attack(bow, ratHealth, playerClass, turnTimer);
                    turnTimer++;
                }
            }
            else if (actionInput == "2") {
                heal(potionAmount, playerHealth);
                turnTimer++;
            }
            else {
                cout << "nothing happened (input a valid input)" << endl;
            }
        }
        system("cls");
        if (ratHealth > 0) {
            attack(ratDamadge, playerHealth, playerClass, turnTimer);
            cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
            ratKingASCII();
            cout << "Rat King: " << ratHealth << "/50" << endl;
            cout << "The Rat King attacks you" << endl;
            turnTimer++;
        }
    }
    if (ratHealth <= 0) {
        cout << "HP: " << playerHealth << "/100\t\t potion amount: " << potionAmount << endl << endl;
        ratKingASCII();
        cout << "Rat King: " << ratHealth << "/50" << endl;
        cout << "The Rat King was beaten. You have actually beaten the Rat King. " << endl;
        cout << "What now? You turn back and march your way back through the ten rooms. the cellar door is open." << endl;
        cout << "Press ENTER to continue through the door" << endl;
        bool temp = false;
        while (temp == false) {
            char tempTwo = _getch(); //get a temporary input that updates as the keyboard is pressed
            if (tempTwo == 13) { // if pressed enter, end the loop and start the game
                system("cls"); //clear screen for room 3 
                temp = true;
            }
        }
    }
    else {
        playerDead = true;
    }
}


int main()
{
    // initiate player and set health to 100
    struct entity player;
    player.health = 100;


    // initiate items
    struct item shield;
    shield.damadgeBlock = 4;
    struct item shortsword;
    shortsword.diceNumber = 8;
    struct item greatsword;
    greatsword.diceNumber = 12;
    struct item bow;
    bow.diceNumber = 12;
    struct item arrow;
    arrow.amount = 99;
    struct item potion;
    potion.amount = 5;

    // initiate the rats
    struct entity smallRat; 
    smallRat.health = 15;
    smallRat.damadge = 8;

    struct entity smallRatTwo;
    smallRatTwo.health = 15; 
    smallRatTwo.damadge = 8; 

    struct entity smallRatThree;
    smallRatThree.health = 15;
    smallRatThree.damadge = 8;

    struct entity largeRat;
    largeRat.health = 30;
    largeRat.damadge = 12;

    struct entity ratKing;
    ratKing.health = 50;
    ratKing.damadge = 20;

    // check for game loop
    while (gameOver == false) {
        // runs whilst player health != 0
        while (playerDead == false) {
            mainMenu();
            kingsWizardNPC(player.classType);
            roomOne(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, smallRat.health, smallRat.damadge);
            if (playerDead == true) {
                break;
            }
            roomTwo(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, smallRat.health, smallRat.damadge);
            if (playerDead == true) {
                break;
            }
            roomThree(player.health, potion.amount);
            if (playerDead == true) {
                break;
            }
            roomFour(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, largeRat.health, largeRat.damadge);
            if (playerDead == true) {
                break;
            }
            roomFive(player.health, potion.amount);
            if (playerDead == true) {
                break;
            }
            roomSix(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, smallRat.health, smallRatTwo.health, smallRat.damadge);
            if (playerDead == true) {
                break;
            }
            roomSeven(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, smallRat.health, smallRatTwo.health, smallRatThree.health, smallRat.damadge);
            if (playerDead == true) {
                break;
            }
            roomEight(player.health, potion.amount);
            if (playerDead == true) {
                break;
            }
            roomNine(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, smallRat.health, smallRatTwo.health, largeRat.health, smallRat.damadge, largeRat.damadge);
            if (playerDead == true) {
                break;
            }
            roomTen(player.health, player.classType, shortsword.diceNumber, greatsword.diceNumber, bow.diceNumber, shield.damadgeBlock, potion.amount, ratKing.health, ratKing.damadge);
            if (playerDead == true) {
                break;
            }
            winPage();
        }

        // dead condition checking for when player health = 0
        while (playerDead == true) {
            deathScreen();
        }

    }

}
