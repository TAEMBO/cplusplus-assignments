//============================================================================
// Name        : 
// Author      : 
// Class       : 
// Assignment  : A3
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class SalesHistory {
	public:
    	string quarter;
    	int numSold;

        SalesHistory() {
            quarter = "NONE";
            numSold = 0;

            cout << "Constructed sales history instance" << endl;
        }
};

class Product {
	public:
    	string name;
    	int id;
    	int quantity;
    	int salesHistorySize;
    	SalesHistory** salesHistory;

        Product(string givenName, int givenId, int givenQuantity) {
            name = givenName;
            id = givenId;
            quantity = givenQuantity;
            salesHistorySize = 10;
            salesHistory = new SalesHistory*[10]();

            cout << "Constructed product instance #" << givenId << endl;
        }

        ~Product() {
            delete[] salesHistory;

            cout << "Destroyed product instance #" << id << endl;
        }
};

int main() {
    Product** products = new Product*[100]();
    char input;

    cout
        << "Specify a transaction to run:\n"
        << "A - Add a new product to the catalog\n"
        << "D - Delete an existing product from the catalog\n" 
        << "L - List all products in the catalog\n" 
        << "X - Exit" << endl;
    
    cin >> input;

    while (input != 'X') {
        switch (input) {
            case 'A': {
                string newName;
                int newId;
                int newQuantity;
                bool exists = false;

                cout << "Enter the ID for this new product" << endl;
                cin >> newId;

                for (int i = 0; i < 100; i++) {
                    Product* product = products[i];

                    if (product != nullptr && product->id == newId) {
                        cout << "A product already exists with this ID!" << endl;

                        exists = true;
                    }
                }

                if (exists) break;

                cout << "Enter the name for this new product" << endl;
                cin >> newName;

                cout << "Enter the quantity amount for this new product" << endl;
                cin >> newQuantity;

                for (int i = 0; i < 100; i++) {
                    if (products[i] == nullptr || products[i]->id == 0) {
                        products[i] = new Product(newName, newId, newQuantity);

                        break;
                    }
                }

                cout << "Product created!" << endl;

                break;
            }
            case 'D': {
                int deleteId;
                bool exists = false;
                int i = 0;

                cout << "Enter the ID for the product you want to delete" << endl;
                cin >> deleteId;

                if (deleteId) {
                    cout << "You cannot use reserved value 0 as an ID to delete with!" << endl;

                    break;
                }

                while (!exists && i < 100) {
                    if (products[i] != nullptr && products[i]->id == deleteId) {
                        delete products[i];
                    };

                    i++;
                }


                if (!exists) {
                    cout << "A product with that ID doesn't exist!" << endl;

                    break;
                }

                delete products[i];
                products[i] = new Product("OPEN_ELEMENT", 0, 0);

                cout << "Product deleted!" << endl;

                break;
            }
            case 'L': {
                int count = 0;

                for (int i = 0; i < 100; i++) {
                    Product* product = products[i];

                    if (product != nullptr && product->id != 0) {
                        count++;

                        cout
                            << "-----------------------"
                            << "Product #: " << product->id << "\n"
                            << "Product name: " << product->name << "\n"
                            << "Product quantity: " << product->quantity
                            << endl;
                    }
                }

                cout << "Total: " << count << " products" << endl;

                break;
            }
            default:
                cout << "Error: Unknown option given" << endl;
                
                break;
        }

        cout
            << "Specify a transaction to run:\n"
            << "A - Add a new product to the catalog\n" 
            << "D - Delete an existing product from the catalog\n" 
            << "L - List all products in the catalog\n" 
            << "X - Exit" << endl;
        
        cin >> input;
    }

    return 0;
}
