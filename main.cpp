/**
 * Project Title: Enterprise Resource Management System
 * Department:    ECE
 * Roll:          2309012
 * Section:       A
 */

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Things admin can do:
 *      1. Login with credential
 *      2. Add products in the list
 *      3. Update stocks
 *      4. Update prices
 */

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

class Admin {
private:
    const string admin_username = "Afsan";
    const int admin_password = 2309012;
    bool isLoggedIn;
public:
    Admin() : isLoggedIn(false) {}
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
    Decoration deco;
    deco.productTable();
    return 0;
}