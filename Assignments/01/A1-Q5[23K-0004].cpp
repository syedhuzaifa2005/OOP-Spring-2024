/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int Restaurant::coupons_redeemed_count = 0;

class Restaurant {
private:
    string name;
    string menu_list[5];
    float price_list[5];
    string valid_coupon_codes_list[5];
    static int coupons_redeemed_count;

public:
    string location;
    Restaurant(string name, string location, string* menu, float* price, string* coupon_list) {
        this->name = name;
        this->location = location;
        for (int i = 0; i < 5; i++) {
            menu_list[i] = menu[i];
            price_list[i] = price[i];
            valid_coupon_codes_list[i] = coupon_list[i];
        }
    }

    void display_menu() {
        cout << "Welcome to " << name << " - " << location << endl;
        cout << "Here's our menu" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Item " << i + 1 << ": " << menu_list[i] << "\t\t price: " << price_list[i] << "$" << endl;
        }
        cout << endl;
    }

    void generate_bill(vector<string>& selected_items) {
        float total_price = 0;
        for (const string& item : selected_items) {
            for (int i = 0; i < 5; i++) {
                if (item == menu_list[i]) {
                    total_price += price_list[i];
                    break;
                }
            }
        }

        cout << "Total Bill: " << total_price << "$" << endl;
    }

    void apply_discount(string coupon_code) {
        for (int i = 0; i < 5; i++) {
            if (coupon_code == valid_coupon_codes_list[i]) {
                coupons_redeemed_count++;
                cout << "Discount applied! You've redeemed a coupon." << endl;
                return;
            }
        }
        cout << "Invalid coupon code. No discount applied." << endl;
    }

    static int get_coupons_redeemed_count() {
        return coupons_redeemed_count;
    }
};

class BOGOCoupon {
private:
    string coupon_code;
    string valid_from;
    string valid_until;
    string restaurant_code;

public:
    BOGOCoupon(string code, string from, string until, string rest_code)
        : coupon_code(code), valid_from(from), valid_until(until), restaurant_code(rest_code) {}

    bool is_valid(string selected_restaurant_code){
        return (selected_restaurant_code == restaurant_code);
    }
};

class User {
private:
    string name;
    int age;
    string mobile_number;
    vector<string> coupons_list;
    vector<string> redeemed_coupons_list;

public:
    User(string name, int age, string mobile_number)
        : name(name), age(age), mobile_number(mobile_number) {}

    void accumulate_coupon(string coupon_code) {
        coupons_list.push_back(coupon_code);
        cout << "Coupon added to your list!" << endl;
    }

    bool has_valid_coupon(string restaurant_code, string item) {
        for (const string& coupon : coupons_list) {
            BOGOCoupon bogo(coupon, "", "", "");  // You need to provide valid dates and restaurant code
            if (bogo.is_valid(restaurant_code)) {
                cout << "You have a valid coupon for " << restaurant_code << " - " << item << "!" << endl;
                return true;
            }
        }
        cout << "No valid coupon found for " << restaurant_code << " - " << item << "." << endl;
        return false;
    }

    void redeem_coupon(string coupon_code, Restaurant& restaurant, vector<string>& selected_items) {
        for (const string& redeemed_coupon : redeemed_coupons_list) {
            if (coupon_code == redeemed_coupon) {
                cout << "This coupon has already been redeemed." << endl;
                return;
            }
        }

        for (const string& coupon : coupons_list) {
            BOGOCoupon bogo(coupon, "", "", "");  // You need to provide valid dates and restaurant code
            if (coupon_code == coupon && bogo.is_valid(restaurant.location)) {
                redeemed_coupons_list.push_back(coupon_code);
                restaurant.apply_discount(coupon_code);
                cout << "Coupon redeemed successfully!" << endl;
                return;
            }
        }

        cout << "Invalid coupon code. No coupon redeemed." << endl;
    }
};

int main() {
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl << endl;
	
    string food_menu[5] = {"Sushi", "Pad Thai", "Mango Tango", "California Roll", "Teriyaki Chicken"};
    float food_prices[5] = {10.99, 8.99, 5.99, 12.99, 9.99};
    string food_coupons[5] = {"FH-BOGO-12345", "FH-BOGO-67890", "FH-BOGO-54321", "FH-BOGO-98765", "FH-BOGO-24680"};

    Restaurant food_haven("Food Haven", "City Center", food_menu, food_prices, food_coupons);

    string pixel_menu[5] = {"Binary Burger", "Quantum Quinoa", "Data Donuts", "Tech Tacos", "Pixel Pizza"};
    float pixel_prices[5] = {8.99, 9.99, 4.99, 7.99, 11.99};
    string pixel_coupons[5] = {"PB-BOGO-12345", "PB-BOGO-67890", "PB-BOGO-54321", "PB-BOGO-98765", "PB-BOGO-24680"};

    Restaurant pixel_bites("Pixel Bites", "Cyber Street", pixel_menu, pixel_prices, pixel_coupons);

    User user("Huzaifa", 18, "0331-1234567");

    food_haven.display_menu();
    pixel_bites.display_menu();

    vector<string> selected_items = {"Sushi", "Quantum Quinoa", "Data Donuts"};
    user.accumulate_coupon("FH-BOGO-12345");
    user.has_valid_coupon("Food Haven", "Pad Thai");

    user.redeem_coupon("FH-BOGO-12345", food_haven, selected_items);

    cout << "Total coupons redeemed: " << Restaurant::get_coupons_redeemed_count() << endl;

    return 0;
}
