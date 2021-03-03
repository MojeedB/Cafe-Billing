/*
Mojeed Bello
CSC 211
Lab 3

Cafe Billing System

Due March 12th 2020
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Global constants
const int SIZE = 8;
double checkTotal = 0.00;
double checkPlusTax;
const double tax = 0.05;

// Structure definition 
struct menuItemType {
	string menuItem;
	double menuPrice;
	int inventoryCount;

};

// Function prototypes
void initData(menuItemType menu[]);	// Initializes the menu structure array

void showMenu(menuItemType menu[], int amt[], int size); // Prints the menu to the screen

bool checkAvailability(menuItemType menu[], int amt[], int size);

void calcAmt(menuItemType menu[], int amt[], int size); // Calculates the amount  owed by customer

void updateInventory(menuItemType menu[], int amt[], int size); // updates the inventory of the menu items

void printTotalBill(menuItemType menu[], int amt[], int size); // Prints the calcAmt function to 
															   // display the bill due

// Main function
int main() {
	menuItemType menu[SIZE]; // Declares menu array of SIZE
	initData(menu);			 // Function call to initialize menu array

	// Local variables
	int selection;
	int quantity;
	int cont = 1;
	int amt[8] = { 0,0,0,0,0,0,0,0 };
	int exits = 0;



	cout << "Welcome to the Coffee Smorgasbord Counter (CSC)!" << endl;
	cout << "You can order your breakfast by choosing the apropriate order number below." << endl;
	cout << endl;

	updateInventory(menu, amt, SIZE);
	showMenu(menu, amt, SIZE);	 // Function call to print menu to screen
	// Loop to allow menu item selection
	do {
		cout << "What would you like to order?" << endl;
		cout << endl;
		cout << "Please input your order number below:" << endl;
		cin >> selection;
		cout << "How many items would you like to order?" << endl;
		cin >> quantity;
		checkAvailability(menu, amt, SIZE);
		// Switch for menu item choices
		switch (selection) {
		case 1:
			amt[0] += quantity;
			cout << "You selected " << menu[0].menuItem << endl;
			cout << endl;
			break;
		case 2:
			amt[1] += quantity;
			cout << "You selected " << menu[1].menuItem << endl;
			cout << endl;
			break;
		case 3:
			amt[2] += quantity;
			cout << "You selected " << menu[2].menuItem << endl;
			cout << endl;
			break;
		case 4:
			amt[3] += quantity;
			cout << "You selected " << menu[3].menuItem << endl;
			cout << endl;
			break;
		case 5:
			amt[4] += quantity;
			cout << "You selected " << menu[4].menuItem << endl;
			cout << endl;
			break;
		case 6:
			amt[5] += quantity;
			cout << "You selected " << menu[5].menuItem << endl;
			cout << endl;
			break;
		case 7:
			amt[6] += quantity;
			cout << "You selected " << menu[6].menuItem << endl;
			cout << endl;
			break;
		case 8:
			amt[7] += quantity;
			cout << "You selected " << menu[7].menuItem << endl;
			cout << endl;
			break;
		default:
			cout << "invalid selection, please make another selection" << endl;
			cout << endl;
			break;
		}
		cout << "To exit, please enter '0' " << endl;
		cout << "if you would like to make another order please select '1'" << endl;
		cin >> cont;
		cout << endl;
	} while (cont != 0);
	updateInventory(menu, amt, SIZE);
	showMenu(menu, amt, SIZE);
	calcAmt(menu, amt, SIZE);
	printTotalBill(menu, amt, SIZE);

	cout << endl;

	cout << "Please enter any key followed by 'enter' to exit!" << endl;
	cin >> exits;
	if (exits == 0) {
		exit(0);
	}
	else exit(0);

	system("pause");
	return 0;
}


// Function definitions
void initData(menuItemType menu[])
{
	// Menu item declaration 
	menuItemType plainEggs, baconEggs, muffin, frenchToast, fruitBasket, cereal, coffee, tea;
	// Menu Item variable initialization
	// Plain Eggs
	plainEggs.menuItem = "Plain Eggs";
	plainEggs.menuPrice = 1.99;
	plainEggs.inventoryCount = 10;
	// Bacon and Eggs
	baconEggs.menuItem = "Bacon and Eggs";
	baconEggs.menuPrice = 3.45;
	baconEggs.inventoryCount = 10;
	// Muffin
	muffin.menuItem = "Muffin";
	muffin.menuPrice = 2.99;
	muffin.inventoryCount = 10;
	// French Toast
	frenchToast.menuItem = "French Toast";
	frenchToast.menuPrice = 4.99;
	frenchToast.inventoryCount = 10;
	// Fruit Basket
	fruitBasket.menuItem = "Fruit Basket";
	fruitBasket.menuPrice = 5.49;
	fruitBasket.inventoryCount = 10;
	// Cereal
	cereal.menuItem = "Cereal";
	cereal.menuPrice = 1.99;
	cereal.inventoryCount = 10;
	// Coffee
	coffee.menuItem = "Coffee";
	coffee.menuPrice = 1.50;
	coffee.inventoryCount = 10;
	// Tea
	tea.menuItem = "Tea";
	tea.menuPrice = 1.25;
	tea.inventoryCount = 10;

	// Menu array
	menu[0] = plainEggs;
	menu[1] = baconEggs;
	menu[2] = muffin;
	menu[3] = frenchToast;
	menu[4] = fruitBasket;
	menu[5] = cereal;
	menu[6] = coffee;
	menu[7] = tea;
}

void showMenu(menuItemType menu[], int amt[], int size)
{

	cout << setw(18) << left << "Breakfast Item" << "\t" << "Price" << "\t"
		<< "Storage Count" << "\t" << "Order Number" << endl;
	cout << "______________________________________________________" << endl;
	for (int i = 0; i < size; i++) {
		cout << fixed << setprecision(2);
		cout << setw(18) << left << menu[i].menuItem << "\t" << "$" << menu[i].menuPrice << "\t"
			<< menu[i].inventoryCount << "\t\t" << i + 1 << endl;
	}
	cout << endl;
}

bool checkAvailability(menuItemType menu[], int amt[], int size)
{
	for (int i = 0; i < size; i++) {
		if (menu[i].inventoryCount <= 0) {
			if (amt[i] > 0) {
				cout << "Item sold out" << endl;
				menu[i].inventoryCount = 0;
				return true;
			}
		}
	}
}

void calcAmt(menuItemType menu[], int amt[], int size)
{
	for (int i = 0; i < size; i++) {
		if (amt[i] > 0) {
			checkTotal += menu[i].menuPrice * amt[i];
		}
	}
	checkPlusTax = checkTotal + (checkTotal * tax);
}

void updateInventory(menuItemType menu[], int amt[], int size)
{
	for (int i = 0; i < size; i++) {
		if (amt[i] > 0) {
			menu[i].inventoryCount -= amt[i];
		}
	}
}

void printTotalBill(menuItemType menu[], int amt[], int size)
{
	cout << "Thank you for choosing The CSC" << endl;
	cout << "Here is you bill" << endl;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (amt[i] > 0) {
			cout << setw(18) << left << menu[i].menuItem << "\t" << "$" << menu[i].menuPrice
				<< "	x" << amt[i] << endl;
		}
	}
	cout << "---------------------------------------" << endl;
	cout << setw(18) << left << "Total: " << "\t" << "$" << checkTotal << endl;
	cout << setw(18) << left << "Tax: " << "\t" << "$" << (checkTotal * tax) << endl;
	cout << setw(18) << left << "Total Plus Tax: " << "\t" << "$" << checkPlusTax << endl;
}
