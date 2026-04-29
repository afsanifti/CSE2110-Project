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

public:
	// Testing
	ProductManager() {
		addProduct("Mango", 12.00, 40);
	}

	// ----------------- FUNCTIONS FOR ADMIN --------------------
	static void addProduct(string name, float price, int stock) {
		products.push_back(Product(name, price, stock));
	}

	static void removeProduct(int index) {
		if (index > 0) {
			products.erase(products.begin() + index - 1);
		}
		else {
			cout << "\nIndex doesn't exist\n";
		}
	}

	static void updatePrice(int index, float newPrice) {
		if (newPrice > 0) {
			products[index].setPrice(newPrice);
		}
	}

	static void addStock(int index, int newStock) {
		int currentStock = products[index].getStock();
		products[index].setStock(currentStock + newStock);
	}

	static void removeStock(int index, int newStock) {
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
			cart.erase(products.begin() + index - 1);
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
	Admin(string username, string password) {
		if (admin_username == username && admin_password == password) {
			isLoggedIn = true;
		}
		else {
			isLoggedIn = false;
			cout << "Invalid Credential" << endl;
		}
	}

	// bool login(string username, string password) {
	//     if (admin_username == username && admin_password == password) {
	//         isLoggedIn = true;
	//         return true;
	//     } else {
	//         return false;
	//     }
	// }

	void addProduct(string name, float price, int stock) {
		if (isLoggedIn == true){
			ProductManager::addProduct(name, price, stock);
		}
	}

	void removeProduct(int index) {
		if (isLoggedIn == true)
		{
			ProductManager::removeProduct(index);
		}
	}

	void updatePrice(int index, float newPrice) {
		if (isLoggedIn == true)
		{
			ProductManager::updatePrice(index, newPrice);
		}
	}

	void addStock(int index, int newStock) {
		if (isLoggedIn == true)
		{
			ProductManager::addStock(index, newStock);
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

class Decoration {
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

			subtotal += cart[i].getPrice();
		}

		cout << "+------+-----------------+------------+---------+ \n";
		cout << "| " << setw(38) << right << "Subtotal "
											 " | "
			 << setw(7) << left << subtotal << " |\n";
		cout << "+------+-----------------+------------+---------+ \n";
	}
};

int main() {
	int profile;

	cout << "+---------Choose your profile---------+\n";
	cout << "| 1. Admin                            |\n";
	cout << "| 2. Customer                         |\n";
	cout << "+-------------------------------------+\n";
	cout << "+---~> ";
	cin >> profile;

	if (profile == 1) {
	}
	else if (profile == 2) {
	}
	else {
	}
	return 0;
}