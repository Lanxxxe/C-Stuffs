#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

class Customer
{
protected:
  string name;
  string address;
  string contactNumber;

public:
  string getName()
  {
    return this->name;
  }

  string getAddress()
  {
    return this->address;
  }

  string getContctNumber()
  {
    return this->contactNumber;
  }

  virtual void processCashPayment(double amount) = 0;
  virtual void processInstallmentPayment(double amount, string terms) = 0;
  virtual ~Customer(){};
};

class RetailCustomer : public Customer
{
private:
public:
  RetailCustomer(string name, string address, string contactNumber)
  {
    this->name = name;
    this->address = address;
    this->contactNumber = contactNumber;
  }

  void processCashPayment(double amount) override
  {
    double totalAmount = amount;
    double discount = 0.0;

    if (totalAmount > 1000.0)
    {
      discount = 0.12 * totalAmount;
      totalAmount -= discount;
    }

    double additionalDiscount = 0.05 * totalAmount;
    totalAmount -= additionalDiscount;

    cout << "Total Amount: " << amount << endl;
    cout << "Discount (12%): " << discount << endl;
    cout << "Additional Discount (5%): " << additionalDiscount << endl;
    cout << "Amount to Pay: " << totalAmount << endl;
  }

  void processInstallmentPayment(double amount, string terms) override
  {
    double totalAmount = amount;
    double discount = 0.0;

    if (totalAmount > 1000.0)
    {
      discount = 0.12 * totalAmount;
      totalAmount -= discount;
    }

    double downPayment = 0.3 * totalAmount;
    double remainingBalance = totalAmount - downPayment;
    int numMonths = stoi(terms);
    double interestPerMonth = 0.025;
    double monthlyPayment = (remainingBalance + (remainingBalance * interestPerMonth * numMonths)) / numMonths;

    cout << "Total Amount: " << amount << endl;
    cout << "Discount (12%): " << discount << endl;
    cout << "Down Payment (30%): " << downPayment << endl;
    cout << "Remaining Balance: " << remainingBalance << endl;
    cout << "Interest per Month (2.5%): " << interestPerMonth * 100 << "%" << endl;
    cout << "Number of Months: " << numMonths << endl;
    cout << "Monthly Payment: " << monthlyPayment << endl;
  }
};

class RegularCustomer : public Customer
{
private:
public:
  RegularCustomer(string name, string address, string contactNumber)
  {
    this->name = name;
    this->address = address;
    this->contactNumber = contactNumber;
  }

  void processCashPayment(double amount) override
  {
    double totalAmount = amount;
    double discount = 0.0;

    if (totalAmount > 1000.0)
    {
      discount = 0.12 * totalAmount;
      totalAmount -= discount;
    }

    double additionalDiscount = 0.05 * totalAmount;
    totalAmount -= additionalDiscount;

    cout << "Total Amount: " << amount << endl;
    cout << "Discount (12%): " << discount << endl;
    cout << "Additional Discount (5%): " << additionalDiscount << endl;
    cout << "Amount to Pay: " << totalAmount << endl;
  }

  void processInstallmentPayment(double amount, string terms) override
  {
    double totalAmount = amount;
    double discount = 0.0;

    if (totalAmount > 1000.0)
    {
      discount = 0.12 * totalAmount;
      totalAmount -= discount;
    }

    double downPayment = 0.25 * totalAmount;
    double remainingBalance = totalAmount - downPayment;
    int numMonths = stoi(terms);
    double monthlyPayment = remainingBalance / numMonths;

    cout << "Total Amount: " << amount << endl;
    cout << "Discount (12%): " << discount << endl;
    cout << "Down Payment (25%): " << downPayment << endl;
    cout << "Remaining Balance: " << remainingBalance << endl;
    cout << "Number of Months: " << numMonths << endl;
    cout << "Monthly Payment: " << monthlyPayment << endl;
  }
};


double getValidFloatInput() {
  double input;
  while (!(cin >> input) || input < 0) {
    cout << "Invalid input. Please enter a valid or non-negative number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return input;
}

int getValidIntInput() {
    int num;
    while (!(cin >> num || num < 0)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer: ";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return num;
};


class Product {
private:
    int id;
    string description;
    int quantity;
    double itemPrice;

public:
    Product (){}
    ~Product (){}

    void process() {
        cout << "Product ID: ";
        id = getValidIntInput();

        cout << "Product Description: ";
        getline(cin, description);

        cout << "Item Price: ";
        itemPrice = getValidFloatInput();

        cout << "Quantity: ";
        quantity = getValidIntInput();
    }

    double calculateTotalAmount() {
        double totalAmount = this->itemPrice * this->quantity;
        return totalAmount;
    }

    int getID() {
        return id;
    }

    string getDescription() {
        return description;
    }

    int getQuantity() {
        return quantity;
    }

    double getItemPrice() {
        return itemPrice;
    }

};


class Transact
{
private:
  static int generatedID;
  int id;
  string date;
  string customerType;
  string paymentType;
  vector<Product> products;

public:
  Transact() {}

  ~Transact() {}

  void process()
  {
    Customer *customer;
    cout << "Input the following:\n\n";
    string customerName, customerAddress, contactNumber;

    cout << "Customer Name: ";
    getline(cin, customerName);
    cout << "Address: ";
    getline(cin, customerAddress);
    cout << "Contact Number: ";
    getline(cin, contactNumber);
    cout << "Type of Customer (retail/regular): ";
    getline(cin, customerType);
    cout << "Type of Payment (cash/installment): ";
    getline(cin, paymentType);

    transform(customerType.begin(), customerType.end(), customerType.begin(), ::tolower);
    transform(paymentType.begin(), paymentType.end(), paymentType.begin(), ::tolower);

    if (customerType == "retail")
    {
      customer = new RetailCustomer(customerName, customerAddress, contactNumber);
    }
    else if (customerType == "regular")
    {
      customer = new RegularCustomer(customerName, customerAddress, contactNumber);
    }

    char addMoreProducts;
    double totalAmount = 0.0;
    do
    {
      cout << "\n----------------------------------------------------------\n";
      Product product;
      product.process();
      products.push_back(product);
      totalAmount += product.calculateTotalAmount();

      cout << "Add more products? (y/n): ";
      cin >> addMoreProducts;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (tolower(addMoreProducts) == 'y');

    if (paymentType == "cash")
    {
      customer->processCashPayment(totalAmount);
    }
    else if (paymentType == "installment")
    {
      cout << "Payment Terms (3, 6, or 9 months): ";
      string paymentTerms;
      getline(cin, paymentTerms);
      customer->processInstallmentPayment(totalAmount, paymentTerms);
    }

    id = ++Transact::generatedID;
    cout << "\nTransaction ID: " << id << '\n';

    cout << "Transaction Date: ";
    getline(cin, date);

    cout << "\n----------------------------------------------------------\n";
    cout << "Transaction Summary:\n\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "Address: " << customerAddress << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "Customer Type: " << customerType << endl;
    cout << "Payment Type: " << paymentType << endl;

    cout << string(74, '-') << endl;
    cout << left << setw(15) << "Product ID"
         << left << setw(25) << "Description"
         << right << setw(12) << "Item Price"
         << right << setw(10) << "Quantity"
         << right << setw(12) << "Subtotal" << endl;
    cout << string(74, '-') << endl;

    for (Product product : products) {
      cout << left << setw(15) << product.getID()
           << left << setw(25) << product.getDescription()
           << right << setw(12) << fixed << setprecision(2) << product.getItemPrice()
           << right << setw(10) << product.getQuantity()
           << right << setw(12) << fixed << setprecision(2) << product.calculateTotalAmount() << endl;
    }
    cout << string(74, '-') << endl;

    double discount = 0.0;
    if (totalAmount > 1000.0)
    {
      discount = 0.12 * totalAmount;
      totalAmount -= discount;
    }

    cout << "Total Amount: " << totalAmount + discount << endl;
    cout << "Discount (12%): " << discount << endl;

    delete customer;
  }
};

int Transact::generatedID = 0;

int main()
{
  char again;
  Transact transaction;

  do
  {
    transaction.process();

    cout << "\n\nDo you want to try again? [Y/N]: ";
    cin >> again;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n----------------------------------------------------------\n";
  } while (tolower(again) == 'y');

  return 0;
}