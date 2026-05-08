/**
 * Project Title: Enterprise Resource Management System
 * Department:    ECE
 * Roll:          2309012
 * Section:       A
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Product {
private:
	string name;
	float price;
	int stock;

public:
	Product(string name, float price, int stock) {
		this->name = name;
		this->price = price;
		this->stock = stock;
	}

	string getName() { return name; }
	float getPrice() { return price; }
	int getStock() { return stock; }

	void setPrice(float price) { this->price = price; }
	void setStock(int stock) { this->stock = stock; }
};

class ProductManager {
private:
	static vector<Product> products;
	static vector<Product> cart;

	ProductManager() {}

	static bool initialized;
	static bool initializeProducts() {
		addProduct("Choclate Cake", 12.00, 40);
		addProduct("Mountain Dew", 25, 50);
		addProduct("Chips", 15, 100);
	}

public:
	// ----------------- FUNCTIONS FOR ADMIN --------------------
	static void addProduct(string name, float price, int stock) {
		products.push_back(Product(name, price, stock));
	}

	static void removeProduct(int index) {
		if (index > 0 && index <= products.size()) {
			products.erase(products.begin() + index - 1);
		}
		else {
			cout << "\nIndex doesn't exist\n";
		}
	}

	static void updatePrice(int index, float newPrice) {
		index = index - 1;

		if (newPrice > 0) {
			products[index].setPrice(newPrice);
		}
	}

	static void addStock(int index, int newStock) {
		index = index - 1;
		int currentStock = products[index].getStock();
		products[index].setStock(currentStock + newStock);
	}

	static void removeStock(int index, int newStock) {
		index = index - 1;
		int currentStock = products[index].getStock();
		if (currentStock >= newStock) {
			products[index].setStock(currentStock - newStock);
		}
		else {
			products[index].setStock(0);
		}
	}

	// ----------------- FUNCTIONS FOR CUSTOMER ----------------
	static void addProductToCart(int index, int quantity) {
		index  = index - 1;
		string name = products[index].getName();
		float price = products[index].getPrice();
		int currentStock = products[index].getStock();

		if (quantity <= currentStock) {
			cart.push_back(Product(name, price, quantity));
			products[index].setStock(currentStock - quantity);
		}
		else {
			cout << "\nInsufficient Stock. Try again\n";
		}
	}

	static void removeProductFromCart(int index) {
		if (index > 0) {
			cart.erase(cart.begin() + index - 1);
		}
		else {
			cout << "\nIndex doesn't exist\n";
		}
	}

	// ---------------- MISCELLANEOUS FUNCTIONS ----------------
	static vector<Product> getProducts() {
		return products;
	}

	static vector<Product> getCart() {
		return cart;
	}

	static Product getProductWithIndex(int index) {
		return products.at(index);
	}
};

vector<Product> ProductManager::products;
vector<Product> ProductManager::cart;
bool ProductManager::initialized = ProductManager::initializeProducts();

/**
 * Things admin can do:
 *      1. Login with credential
 *      2. Add products in the list
 *      3. Update stocks
 *      4. Update prices
 */

class Admin {
private:
	const string admin_username = "Afsan";
	const string admin_password = "2309012";
	bool isLoggedIn;

public:
	Admin() {
		isLoggedIn = false;
	}

	bool login(string username, string password) {
	    if (admin_username == username && admin_password == password) {
	        isLoggedIn = true;
	        return true;
	    } else {
	        return false;
	    }
	}

	void addProduct(string name, float price, int stock) {
		if (isLoggedIn) {
			ProductManager::addProduct(name, price, stock);
		}
	}

	void removeProduct(int index) {
		if (isLoggedIn) {
			ProductManager::removeProduct(index);
		}
	}

	void updatePrice(int index, float newPrice) {
		if (isLoggedIn) {
			ProductManager::updatePrice(index, newPrice);
		}
	}

	void addStock(int index, int newStock) {
		if (isLoggedIn) {
			ProductManager::addStock(index, newStock);
		}
	}

	void removeStock(int index, int newStock) {
		if (isLoggedIn) {
			ProductManager::removeStock(index, newStock);
		}
	}
};

/**
 * Things customers can do:
 *      1. See list of products
 *      2. Add products to their cart
 *      3. Remove products from their cart
 *      4. Get money receipt
 */

class Customer {
public:
	void addToCart(int index, int quantity) {
		ProductManager::addProductToCart(index, quantity);
	}

	void removeFromCart(int index) {
		ProductManager::removeProductFromCart(index);
	}

	// void findProduct() {

	// 
	// void viewCart();
};

class Table {
public:
	static void productTable() {
		cout << "+------+-----------------+---------+---------+ \n";
		cout << "| ID   | Product Name    | Stock   | Price   | \n";
		cout << "+------+-----------------+---------+---------+ \n";

		vector<Product> products = ProductManager::getProducts();
		vector<Product> cart = ProductManager::getCart();

		for (int i = 0; i < products.size(); i++) {
			cout << "| " << setw(5) << left << i + 1
				 << "| " << setw(16) << left << products[i].getName()
				 << "| " << setw(8) << left << products[i].getStock()
				 << "| " << setw(8) << left << products[i].getPrice() << "|" << endl;
		}

		cout << "+------+-----------------+---------+---------+ \n";
	}

	static void cartTable() {
		cout << "Your Cart:\n";
		cout << "+------+-----------------+------------+---------+ \n";
		cout << "| ID   | Product Name    | Quantity   | Price   | \n";
		cout << "+------+-----------------+------------+---------+ \n";

		vector<Product> cart = ProductManager::getCart();
		float subtotal = 0;

		for (int i = 0; i < cart.size(); i++) {
			cout << "| " << setw(5) << left << i + 1
				 << "| " << setw(16) << left << cart[i].getName()
				 << "| " << setw(11) << left << cart[i].getStock()
				 << "| " << setw(8) << left << cart[i].getPrice() << "|" << endl;

			subtotal += cart[i].getPrice() * cart[i].getStock();
		}

		cout << "+------+-----------------+------------+---------+ \n";
		cout << "| " << setw(38) << right << "Subtotal "
											 " | "
			 << setw(7) << left << subtotal << " |\n";
		cout << "+------+-----------------+------------+---------+ \n";
	}
};


int main() {
	system("cls");
	int profile;

	while(true) {
		cout << "+---------Choose your profile---------+\n";
		cout << "| 1. Admin                            |\n";
		cout << "| 2. Customer                         |\n";
		cout << "+-------------------------------------+\n";
		cout << "+---~> ";
		cin >> profile;

		if (profile == 1) {
			string u;
			string p;

			cout << "| Enter Username                      |\n";
			cout << "+---~> ";
			cin >> u;

			cout << "| Enter Password                      |\n";
			cout << "+---~> ";
			cin >> p;
			cout << endl << endl;
			
			Admin admin;
			
			bool credential = admin.login(u, p);
			
			system("cls");
			while(true) {
				bool exit = false;
				if (credential == true) {

					Table::productTable();

					int opt;
					cout << endl;
					cout << "| 1. Add Product                             |\n"
							"| 2. Remove Product                          |\n"
							"| 3. Add Stock                               |\n"
							"| 4. Remove Stock                            |\n"
							"| 5. Update Price                            |\n"
							"| 0. Go back <---                            |\n"
							"+---~> ";
					cin >> opt;

					while (true) {
						if (opt == 1) {
							system("cls");

							string name;
							float price;
							int stock;

							cout << "| Enter Name                         \n";
							cout << "+---~> ";
							getline(cin >> ws, name);
							cout << "| Enter Price                        \n";
							cout << "+---~> ";
							cin >> price; 
							cout << "| Enter Stock                        \n";
							cout << "+---~> ";
							cin >> stock; 

							admin.addProduct(name, price, stock);
							break;
						
						} else if (opt == 2) {
							int indx;
							cout << "| Enter Product Numner:               \n";
							cout << "+---~> ";
							cin >> indx;
							
							admin.removeProduct(indx);
							break;

						} else if (opt == 3) {
							int indx, stock;
							cout << "| Enter Product Numner:               \n";
							cout << "+---~> ";
							cin >> indx;

							cout << "| Enter New Stock Number:             \n";
							cout << "+---~> ";
							cin >> stock;

							admin.addStock(indx, stock);
							break;

						} else if (opt == 4) {
							int indx, stock;
							cout << "| Enter Product Numner:               \n";
							cout << "+---~> ";
							cin >> indx;

							cout << "| Enter New Stock Number:             \n";
							cout << "+---~> ";
							cin >> stock;

							admin.removeStock(indx, stock);
							break;

						} else if (opt == 5) {
							int indx;
							float price;
							
							cout << "| Enter Product Numner:               \n";
							cout << "+---~> ";
							cin >> indx;

							cout << "| Enter New Price:                    \n";
							cout << "+---~> ";
							cin >> price;

							admin.updatePrice(indx, price);
							break;

						} else if (opt == 0) {
							exit = true;
							break;
						} else {
							cout << "\nWrong Input.";
							break;
						}
					}

					system("cls");
				}

				if (exit) { break; }
			}
		} else if (profile == 2) {
			Customer customer;

			bool exit = false;

			while(true) {
				Table::productTable();

				int opt;

				cout << "| 1. Add Product to Cart                     |\n"
						"| 2. Remove Product from Cart                |\n"				
						"| 3. See Cart                                |\n"
						"| 0. Go back <---                            |\n"
						"+---~> ";
				cin >> opt;
				
				while(true) {
					if (opt == 1) {
						int index;
						int quantity;

						cout << "| Enter Product Number:                  \n";
						cout << "+---~> ";
						cin >> index;

						cout << "| Enter Quanntity of Product:            \n";
						cout << "+---~> ";
						cin >> quantity;

						customer.addToCart(index, quantity);
						break;

					} else if (opt == 2) {
						int index;

						cout << "| Enter Product Number:                  \n";
						cout << "+---~> ";
						cin >> index;

						customer.removeFromCart(index);
						break;

					} else if (opt == 3) {
						Table::cartTable();
						break;

					} else if (opt == 0) {
						exit = true;
						break;

					} else {
						cout << "\nWrong Input";
						break;
					}

					
					system("cls");
				}
				if (exit) { break; }
			}
		} else {

		}

	} 

	return 0;
}
