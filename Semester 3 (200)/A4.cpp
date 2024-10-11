//============================================================================
// Name        : 
// Author      : 
// Class       : 
// Assignment  : A4
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

        Product(Product& product, int newId) {
            id = newId;
            name = product.name;
            quantity = product.quantity;
            salesHistorySize = 10;
            salesHistory = new SalesHistory*[10]();

            cout << "Copy constructer called on #" << newId << " from #" << product.id << endl;
        }

        ~Product() {
            delete[] salesHistory;

            cout << "Destroyed product instance #" << id << endl;
        }
};

ostream& operator<< (ostream& os, Product* p) {
    cout
        << "Product listing"
        << "Product #: " << p->id << "\n"
        << "Product name: " << p->name << "\n"
        << "Product quantity: " << p->quantity
        << endl;
    
    bool hasHistoryLength = false;

    for (int i = 0; i < p->salesHistorySize; i++) {
        SalesHistory* salesHistoryEntry = p->salesHistory[i];

        if (salesHistoryEntry != nullptr) {
            hasHistoryLength = true;

            cout << "     " << salesHistoryEntry->quarter << "  " << salesHistoryEntry->numSold << "\n";
        }
    }

    if (hasHistoryLength) {
        cout << endl;
    } else {
        cout << endl << "      This product has no sales history" << endl;
    }

    return os;
};

bool operator> (Product& p1, Product& p2) {
    return p1.quantity > p2.quantity;
};

bool operator== (Product& p1, Product& p2) {
    return p1.quantity == p2.quantity;
};

int main() {
    Product** products = new Product*[100]();
    char input;

    cout
        << "Specify a transaction to run:\n"
        << "A - Add a new product to the catalog\n"
        << "S - Add sales history\n"
        << "C - Copy existing product\n"
        << "O - Compare products\n"
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
            case 'C': {
                int queryExistingId;
                int newId;
                bool exists = false;
                Product* product;

                cout << "Enter the ID for the product you want to copy" << endl;
                cin >> queryExistingId;

                for (int i = 0; i < 100; i++) {
                    if (products[i] != nullptr && products[i]->id == queryExistingId) {
                    	product = products[i];
                    	exists = true;
                    	
                    	break;
                    }
                }

                if (!exists) {
                	cout << "A product with this ID doesn't exist!" << endl;

                	break;
                }

                cout << "Enter the ID you want to copy the product to" << endl;
                cin >> newId;

                for (int i = 0; i < 100; i++) {
                    if (products[i] == nullptr) {
                        products[i] = new Product(*product, newId);
                    	
                    	break;
                    }
                }

                break;
            }
            case 'O': {
                int firstQueryId;
                int secondQueryId;
                Product* firstProduct;
                Product* secondProduct;
                bool firstExists = false;
                bool secondExists = false;


                cout << "Enter the ID for the first product you want to compare with" << endl;
                cin >> firstQueryId;

                for (int i = 0; i < 100; i++) {
                    if (products[i] != nullptr && products[i]->id == firstQueryId) {
                    	firstProduct = products[i];
                    	firstExists = true;
                    	
                    	break;
                    }
                }

                if (!firstExists) {
                    cout << "No product with that ID was found" << endl;

                    break;
                }

                cout << "Enter the ID for the second product you want to compare with" << endl;
                cin >> secondQueryId;

                for (int i = 0; i < 100; i++) {
                    if (products[i] != nullptr && products[i]->id == secondQueryId) {
                    	secondProduct = products[i];
                    	secondExists = true;
                    	
                    	break;
                    }
                }

                if (!secondExists) {
                    cout << "No product with that ID was found" << endl;

                    break;
                }

                if ((*firstProduct) == (*secondProduct)) {
                    cout << "The products have the same quantities! (" << firstProduct->quantity << ")" << endl;
                } else if ((*firstProduct) > (*secondProduct)) {
                    cout
                        << "Product #"
                        << firstProduct->id
                        << " has a higher quantity ("
                        << firstProduct->quantity
                        << ") than product #"
                        << secondProduct->id
                        << " ("
                        << secondProduct->id
                        << ")!"
                        << endl;
                } else {
                    cout
                        << "Product #"
                        << secondProduct->id
                        << " has a higher quantity ("
                        << secondProduct->quantity
                        << ") than product #"
                        << firstProduct->id
                        << " ("
                        << firstProduct->id
                        << ")!"
                        << endl;
                }

                break;
            }
            case 'S': {
                int queryId;
                string newQuarter;
                int newUnitsSold;
                bool exists = false;
                Product* product;

                cout << "Enter the ID for the product to add sales history to" << endl;
                cin >> queryId;

                for (int i = 0; i < 100; i++) {
                    if (products[i] != nullptr && products[i]->id == queryId) {
                    	product = products[i];
                    	exists = true;
                    	
                    	break;
                    }
                }

                if (!exists) {
                	cout << "A product with this ID doesn't exist!" << endl;

                	break;
                }

                cout << "Enter the quarter for this new sales history entry" << endl;
                cin >> newQuarter;

                cout << "Enter the amount of units sold for this sales history entry" << endl;
                cin >> newUnitsSold;

                for (int i = 0; i < product->salesHistorySize; i++) {
                    SalesHistory* salesHistoryEntry = product->salesHistory[i];

                    if (salesHistoryEntry == nullptr) {
                        salesHistoryEntry = new SalesHistory();

                        salesHistoryEntry->quarter = newQuarter;
                        salesHistoryEntry->numSold = newUnitsSold;

                        break;
                    }
                }

                cout << "Sales history added to product #" << queryId << endl;

                break;
            }
            case 'D': {
                int deleteId;
                bool exists = false;
                int i = 0;

                cout << "Enter the ID for the product you want to delete" << endl;
                cin >> deleteId;

                if (!deleteId) {
                    cout << "You cannot use reserved value 0 as an ID to delete with!" << endl;

                    break;
                }

                while (!exists && i < 100) {
                    if (products[i] != nullptr && products[i]->id == deleteId) {
                        exists = true;
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

                        cout << product;
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
            << "S - Add sales history\n"
            << "C - Copy existing product\n"
            << "O - Compare products\n"
            << "D - Delete an existing product from the catalog\n" 
            << "L - List all products in the catalog\n" 
            << "X - Exit" << endl;
        
        cin >> input;
	}

    return 0;
}
