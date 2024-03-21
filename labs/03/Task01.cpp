#include <iostream>
#include <string>

using namespace std;

class BoardMarker{
    private:
        string Brand;
        string Shade;
        bool Refillable;
        bool Ink_Status;

    public:
        string getbrand() const{
            return Brand;
        }
        string getshade() const{
            return Shade;
        }
        bool isrefillable() const{
            return Refillable;
        }
        bool isInkDepleted() const{
            return Ink_Status;
        }

        void setBrand(std::string newBrand) {
        Brand = newBrand;
        }

        void setShade(std::string newShade) {
        Shade = newShade;
        }

        void setRefillable(bool newRefillable) {
        Refillable = newRefillable;
        }

        void setInkStatus(bool newInkStatus) {
        Ink_Status = newInkStatus;
        }


void write() const {
        if (isInkDepleted()) {
            cout<< "Cannot write. Ink is depleted." << endl;
        } else {
            cout<< "Writing with " << Brand << " board marker in " << Shade << " color." << endl;
        }
    }

    void refill() {
        if (isrefillable()) {
            cout<< "Refilling " << Brand << " board marker." << endl;
            setInkStatus(true);
        } else {
            cout<< "Cannot refill. Marker is not refillable." << endl;
        }
    }
};

int main() {
    BoardMarker marker;
    marker.setBrand("Dollar");
    marker.setShade("Black");
    marker.setRefillable(true);
    marker.setInkStatus(true);

    marker.write();
    marker.refill(); 
    marker.setInkStatus(false);

    marker.write();  
    marker.refill();

    return 0;
}