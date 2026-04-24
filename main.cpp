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

class ProductSystem {
private:
    static vector<Product> products;

public:
    static void addProducts(string name, float price, int stock) {
        products.push_back(Product(name, price, stock));
    }

    static void updatePrice(int index, float newPrice) {
        // TODO: add limits for index
        products[index].setPrice(newPrice);
    }

    static void updateStock(int index, int newStock) {
        products[index].setStock(newStock);
    } 
};

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
        ProductSystem::addProducts(name, price, stock);
    }

    void updatePrice(int index, float newPrice) {
        ProductSystem::updatePrice(index, newPrice);
    }

    void updateStock(int index, int newStock) {
        ProductSystem::updateStock(index, newStock);
    }
};

class Customer {};

class Decoration {
public:
    void productTable() {
        cout << "+------+-----------------+---------+---------+ \n";
        cout << "| ID   | Product Name    | Stock   | Price   | \n";
        cout << "+------+-----------------+---------+---------+ \n";

        for (int i = 0; i < 10; i++) {
            cout << "| " << setw(5) << left << i + 1
                 << "| " << setw(16) << left << "Name"
                 << "| " << setw(8) << left << "Stock"
                 << "| " << setw(8) << left << "Price" << "|" << endl;
        }

        cout << "+------+-----------------+---------+---------+ \n";
    }
};

int main() {
    
    return 0;
}