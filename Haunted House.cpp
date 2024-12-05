// Create a puzzle game that requires the user to solve a single puzzle to escape the room.
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// need a struct called "Item"
struct Item {
	string name;
	string description;
	bool isInspectable;
	
	Item (string name, string description, bool isInspectable = true)
		: name(name), description(description), isInspectable(isInspectable)  {}
};

// need a struct for the NPC called "Character"
struct Character {
	string name;
	string role;
	string dialogue;
	
	Character(string name, string role, string dialogue)
		: name(name), role(role), dialogue(dialogue)  {}

	void interact() {
		cout << name << " (" << role << "): " << dialogue << endl;
	}
};

// need a struct called "Room"
struct Room {
	string description;
	vector<Item> items;
	vector<Character> npcs;
	bool puzzleSolved;
	
	Room(string desc) : description(desc), puzzleSolved(false)  {}
	
// need a function to "showItems"
	void showItems() {
		if (items.empty()) {
			cout << "There are no items to inspect.\n";
		} else {
			cout << "Items in this room:\n";
			for (size_t i = 0; i < items.size(); ++i) {
				cout << i + 1 << ". " << items[i].name << endl;
			}
		}
	}
	
// need a function to "inspectItems"
	void inspectItem(int index) {
		if (index >= 1 && index <= items.size()) {
			cout << items[index - 1].description << endl;
		} else {
			cout << "Invalid item number!\n";
		}
	}
	
// need a function to interactWithNPC"
	void interactWithNPC() {
		if (npcs.empty()) {
			cout << "There are no NPCs to talk to.\n";
		} else {
			for (size_t i = 0; i < npcs.size(); ++i) {
				npcs[i].interact();
			}
		}
	}
	
	bool solvePuzzle(string answer) {
// need a bool to "solvePuzzle"
string correctAnswer = "3101";  // This could be based on clues in the room
if (answer == correctAnswer) {
	puzzleSolved = true;
	cout << "Congratulations! You've solved the puzzle and unlocked the exit!\n";
	return true;
} else {
	cout << "Incorrect solution. Try again.\n";
	return false;
}
}
	};
	
	
// need a function to "showMenu" and make a selection
int showMenu() {
	int choice;
	cout << "\nWhat would you like to do?\n";
	cout << "1. Explore the room\n";
	cout << "2. Interact with NPC\n";
	cout << "3. Inspect items\n";
	cout << "4. Solve the puzzle\n";
	cout << "5. Quit the game\n";
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

// int main() loop
int main() {
	srand(time(0));  // Seed random number generator
// need to create NPCs and items
Character ghost ("\nGhostly Figure", "NPC", "You must solve the puzzle to leave this room.");
Character oldWoman("\nOld Woman", "NPC", "The clue is hidden in plain sight... you just have to look closely.");

Room hauntedRoom("A dark room filled with old furniture. There are cobwebs everywhere and you can feel the wind from outside.  There must be cracks in the walls.\nAn old woman and a ghostly figure stand in the middle of the room.");

hauntedRoom.items.push_back(Item("Old Painting", "\nAn eerie painting of a woman with a blank stare. Her eyes seem to follow you."));
hauntedRoom.items.push_back(Item("Mysterious Book", "\nThe book '101 Dalmatians' rests on the table. It seems out of place in this spooky room. \nThe book is open to chapter three."));
hauntedRoom.items.push_back(Item("Strange Lockbox", "\nA lockbox with a keypad. There are four digits to input."));

hauntedRoom.npcs.push_back(ghost);
hauntedRoom.npcs.push_back(oldWoman);

// start the game
Room* currentRoom = &hauntedRoom;
bool isGameRunning = true;

// need a while loop to run the game
while (isGameRunning) {
	// Display current room description
	cout << "\nYou are in: " << currentRoom->description << endl;
	
// need to use switch to select menu options
int choice = showMenu();
switch (choice) {
	case 1:
		// Explore the room
		cout << "You look around.\n";
		currentRoom->showItems();
		break;
	case 2:
		// Interact with NPC
		currentRoom->interactWithNPC();
		break;
	case 3:
		// Inspect items
		cout << "Which item would you like to inspect? (Enter number): ";
		int itemChoice;
		cin >> itemChoice;
		currentRoom->inspectItem(itemChoice);
		break;
	case 4:
		// need to test the puzzle solution
		if (currentRoom->puzzleSolved) {
			cout << "You've already solved the puzzle.\n";
		} else {
			cout << "Enter the 4-digit code to solve the puzzle: ";
			string userInput;
			cin >> userInput;
			if (currentRoom->solvePuzzle(userInput)) {
				currentRoom->puzzleSolved = true;
			}
		}
		break;
	case 5:
	// end the game
	cout << "You decided to stop so you remain trapped. Game over.\n";
	isGameRunning = false;
	break;
	default:
	cout << "Invalid choice. Please try again.\n";
	}

	// Check if puzzle is solved and the game ends
	if (currentRoom->puzzleSolved) {
		cout << "The lid springs open. You see a key inside. Now you can escape the room.\n";
		break; 	// End the game if the puzzle is solved
	}
}

	return 0;
}
