#include <iostream>
using namespace std;

class Product {
    public: string pID, pDesc;
    int qty;
    double price, tPrice, disc;

    void disProd() {
        cout << "Input the following: ";
        cout << "\nProduct ID: ";
        cin >> pID;
        cout << "Product Description: ";
        cin >> pDesc;
        cout << "Item Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;
    }

    void computePrice();
};

class Transact {
    public:
    string tranID, tranDate, pID;

    void disTran(){
        cout << "\n Transaction ID: ";
        cin >> tranID;
        cout << "\n Transaction Date: ";
        cin >> tranDate;
    }
};

void Product::computePrice() {
    if (price > 1000) {
        tPrice = price*qty;
        disc - tPrice*0.12;

        cout << "\n Item Price: " << price;
        cout << "\n Quantity: " << qty;
        cout << "\n Total Amount: " << tPrice;
        cout << "\n Discount: 12%";
        cout << "\n AmounDue: " << tPrice - disc;
        cout << "\n Thank you for your order!"; 
    } 
    else {
        tPrice = price*qty;
        disc = price + 0;
        cout << "\n Item Price: " << price;
        cout << "\n Quantity: " << qty;
        cout << "\n Total Amount: " << tPrice;
        cout << "\n Discount: 0%";
        cout << "\n AmounDue: " << tPrice + 0;
        cout << "\n Thank you for your order!"; 
    }
};


int main () {
    char again;
    class Product newProd;
    class Transact newTran;

    do {
        newProd.disProd();
        newTran.disTran();
        newProd.computePrice();

        cout << "\n\n Do you want to Try Again? [Y/N]: ";
        cin >> again;
        cout << endl;
    } while (again == 'Y' || again == 'y');
}

