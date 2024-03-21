/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/


#include <iostream>
#include <string>
using namespace std;

const int MAX_MENU_ITEMS = 10; 
class MenuItem {
private:
    string foodName;
    double foodPrice;

public:
    MenuItem(const string& name = "", double price = 0.0) : foodName(name), foodPrice(price) {}

    string getFoodName() const {
        return foodName;
    }

    double getFoodPrice() const {
        return foodPrice;
    }
};

class Menu {
private:
    MenuItem menuItems[MAX_MENU_ITEMS];
    int itemCount;

public:
    Menu() : itemCount(0) {}

    void addItem(const MenuItem& item) {
        if (itemCount < MAX_MENU_ITEMS) {
            menuItems[itemCount++] = item;
        } else {
            cout << "Menu is full. Cannot add more items." << endl;
        }
    }


    void displayMenu() const {
        cout << "Menu: " << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << menuItems[i].getFoodName() << " - $" << menuItems[i].getFoodPrice() << endl;
        }
		cout << endl;
    }
};

class Payment {
private:
    double amount;

public:
    Payment(double amount) : amount(amount) {}

    double getAmount() const {
        return amount;
    }
};

class Order {
private:
    MenuItem orderedItems[MAX_MENU_ITEMS];
    Payment payment;
    int itemCount;

public:
    Order(const MenuItem items[], int count, const Payment& payment) : payment(payment), itemCount(count) {
        for (int i = 0; i < count; ++i) {
            orderedItems[i] = items[i];
        }
    }

    void displayOrder() const {
        cout << "Ordered Items: " << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << orderedItems[i].getFoodName() << " - $" << orderedItems[i].getFoodPrice() << endl;
        }
        cout << "Total Amount: $" << payment.getAmount() << endl << endl;
    }
};

class Restaurant {
private:
    Menu menu;

public:
    void addMenuItem(const MenuItem& item) {
        menu.addItem(item);
    }

    void placeOrder(const Order& order) {
        order.displayOrder();
    }

    void displayMenu() const {
        menu.displayMenu();
    }
};

int main() {
    Restaurant restaurant;

    MenuItem item1("Burger", 8.99);
    MenuItem item2("Pizza", 12.99);
    restaurant.addMenuItem(item1);
    restaurant.addMenuItem(item2);

    cout << "Welcome to the Restaurant! " << endl;
    restaurant.displayMenu();

    MenuItem orderItems[] = {item1, item2};
    Payment payment(21.98); 
    Order order(orderItems, 2, payment);

    cout << "Placing Order..." << endl;
    restaurant.placeOrder(order);

    return 0;
}
