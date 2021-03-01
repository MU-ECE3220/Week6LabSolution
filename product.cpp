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

        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << "Successfully sold item " << name_ << " in quantity " << quantity << std::endl;
        std::cout << "Total bill: " << totalBill << std::endl;
        std::cout << numInStock_ << " remaining. " << std::endl;
    }
}

std::string Product::to_string()
{
    std::string productString;

    productString = "ID: " + std::to_string(id_) + ", " +
                    "Name: " + name_ + ", " +
                    "Category: " + Product::category_to_string(category_) + ", " +
                    "Number in stock: " + std::to_string(numInStock_) + ", " + 
                    "Price: " + Product::double_to_string_precision(price_, 2) + "\n";
    return productString;
}

std::string Product::to_export_string()
{
    std::string productString;

    productString = std::to_string(id_) + "\n" +
                    name_ + "\n" +
                    std::to_string(Product::category_to_integer(category_)) + "\n" +
                    std::to_string(numInStock_) + "\n" + 
                    Product::double_to_string_precision(price_, 2) + "\n";
    return productString;
}


std::string Product::category_to_string(Category category)
{
    switch (category)
    {
        case Category::UNINITALIZED : return "Uninitialized"; break;
        case Category::APPLIANCES   : return "Appliances"; break;
        case Category::AUTOMOTIVE   : return "Automotive"; break;
        case Category::BOOKS        : return "Books"; break;
        case Category::CLOTHES      : return "Clothes"; break;
        case Category::ELECTRONICS  : return "Electronics"; break;
        case Category::GROCERIES    : return "Groceries"; break;
        case Category::VIDEO_GAMES  : return "Video Games"; break;
        default : return ""; break;
    }
}

int Product::category_to_integer(Category category)
{
    return static_cast<typename std::underlying_type<Category>::type>(category);
}

std::string Product::double_to_string_precision(double dvalue, size_t precision)
{
    std::string doubleString;
    size_t precisionPosition;

    doubleString = std::to_string(dvalue);
    precisionPosition = doubleString.find(".") + precision + 1;

    return doubleString.substr(0, precisionPosition);
}