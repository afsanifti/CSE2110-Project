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

public:
    // Testing
    ProductManager() {
        addProduct("Mango", 12.00, 40);
    }

    static void addProduct(string name, float price, int stock) {
        products.push_back(Product(name, price, stock));
    }

    static void removeProduct(int index) {
        products.erase(products.begin() + index);
    }

    static void updatePrice(int index, float newPrice) {
        // TODO: add limits for index
        products[index].setPrice(newPrice);
    }

    static void updateStock(int index, int newStock) {
        // TODO: add limits
        products[index].setStock(newStock);
    }

    static vector<Product> getProducts() {
        return products;
    }
};

vector<Product> ProductManager::products;

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
    Admin() : isLoggedIn(false) {}

    bool login(string username, string password) {
        if (admin_username == username && admin_password == password) {
            isLoggedIn = true;
            return true;
        } else {
            return false;
        }
    }

    void addProduct(string name, float price, int stock) {
        ProductManager::addProduct(name, price, stock);
    }

    void removeProduct(int index) {
        ProductManager::removeProduct(index);
    }

    void updatePrice(int index, float newPrice) {
        ProductManager::updatePrice(index, newPrice);
    }

    void updateStock(int index, int newStock) {
        ProductManager::updateStock(index, newStock);
    }
};

class Customer {};

class Decoration {
public:
    static void productTable() {
        cout << "+------+-----------------+---------+---------+ \n";
        cout << "| ID   | Product Name    | Stock   | Price   | \n";
        cout << "+------+-----------------+---------+---------+ \n";

        vector<Product> products = ProductManager::getProducts();

        for (int i = 0; i < products.size(); i++) {
            cout << "| " << setw(5) << left << i + 1
                 << "| " << setw(16) << left << products[i].getName()
                 << "| " << setw(8) << left << products[i].getStock()
                 << "| " << setw(8) << left << products[i].getPrice() << "|" << endl;
        }

        cout << "+------+-----------------+---------+---------+ \n";
    }
};

int main() {
    ProductManager();
    Decoration::productTable();
    Admin admin;
    admin.addProduct("Banana", 10.12, 30);
    Decoration::productTable();
    return 0;
}