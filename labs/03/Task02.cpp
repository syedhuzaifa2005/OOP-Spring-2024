#include <iostream>
#include <string>

using namespace std;


class WaterBottle{
    private:
        string Company_Name;
        string Color;
        int capacity_litres;
        int capacity_millilitres;

    public:
        string getCompany() const {
            return Company_Name;
        }

        string getColor() const {
            return Color;
        }

        int getWaterCapacityLiters() const {
            return capacity_litres;
        }

        int getWaterCapacityMilliliters() const {
            return capacity_millilitres;
        }

        void setCompany(string newCompany) {
            Company_Name = newCompany;
        }

        void setColor(string newColor) {
            Color = newColor;
        }

        void setWaterCapacityLiters(int newCapacityLiters) {
            capacity_litres = newCapacityLiters;
        }

        void setWaterCapacityMilliliters(int newCapacityMilliliters) {
            capacity_millilitres = newCapacityMilliliters;
        }

        void consumeWater(int consumedMilliliters) {
            if (consumedMilliliters <= capacity_millilitres) {
                capacity_millilitres -= consumedMilliliters;

                if (capacity_millilitres < 0) {
                    capacity_litres -= 1;
                    capacity_millilitres += 1000;  
                }

            cout << "Water consumed. Remaining capacity: " << capacity_litres << " liters, " << capacity_millilitres << " milliliters." << endl;
            } else {
                cout << "Not enough water in the bottle." << endl;
            }
        }
};

int main() {
    WaterBottle bottle;

    bottle.setCompany("Aquafina");
    bottle.setColor("Blue");
    bottle.setWaterCapacityLiters(2);
    bottle.setWaterCapacityMilliliters(500);

    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Water Capacity: " << bottle.getWaterCapacityLiters() << " liters, " << bottle.getWaterCapacityMilliliters() << " milliliters." << endl;

    bottle.consumeWater(200);
    bottle.consumeWater(1200);

    return 0;
}
