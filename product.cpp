#include "product.h"

Product::Product()
{
    id_ = -1;
    name_ = "";
    category_ = Category::UNINITALIZED;
    numInStock_ = 0;
    price_ = 0.0;
}

Product::Product(int id, std::string name, Category category, unsigned int numInStock, double price)
{
    id_ = id;
    name_ = name;
    category_ = category;
    numInStock_ = numInStock;
    price_ = price;
}

Product::Product(const Product &product)
{
    id_ = product.id_;
    name_ = product.name_;
    category_ = product.category_;
    numInStock_ = product.numInStock_;
    price_ = product.price_;
}

int Product::get_id() const
{
    return id_;
}

std::string Product::get_name() const
{
    return name_;
}

Category Product::get_category() const
{
    return category_;
}

unsigned int Product::get_numInStock() const
{
    return numInStock_;
}

double Product::get_price() const
{
    return price_;
}

void Product::set_id(int id)
{
    if (id >= 0)
        id_ = id;
    else
        std::cout << "Warning: ID not set. Must be nonnegative." << std::endl;
}

void Product::set_name(std::string name)
{
    if (name != "")
        name_ = name;
    else
        std::cout << "Warning: Name not set. Must be nonempty." << std::endl;
}

void Product::set_category(Category category)
{
    category_ = category;
}

void Product::set_numInStock(unsigned int numInStock)
{
    if (numInStock >= 0)
        numInStock_ = numInStock;
    else
        std::cout << "Warning: Stock number not set. Must be nonnegative." << std::endl;
}

void Product::set_price(double price)
{
    if (price >= 0.0)
        price_ = price;
    else
        std::cout << "Warning: Price not set. Must be nonnegative." << std::endl;
}

void Product::sell(unsigned int quantity)
{
    if (quantity > numInStock_)
    {
        std::cout << "Warning: Not enough quantity to sell." << std::endl;
        std::cout << "Try again with a quantity at " << numInStock_ << " or below." << std::endl;
    }
    else
    {
        numInStock_ -= quantity;
        double totalBill = (double)quantity * price_;

        std::cout.precision(2);
        std::cout << "Successfully sold item " << name_ << " in quantity " << quantity << std::endl;
        std::cout << "Total bill: " << totalBill << std::endl;
        std::cout << numInStock_ << " remaining. " << std::endl;
    }
}