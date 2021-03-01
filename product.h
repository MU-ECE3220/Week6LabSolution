#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

enum Category { UNINITALIZED=-1, APPLIANCES, AUTOMOTIVE, BOOKS, CLOTHES,
                ELECTRONICS, GROCERIES, VIDEO_GAMES};

class Product
{
private:
    int id_;
    std::string name_;
    Category category_;
    unsigned int numInStock_;
    double price_;
    
public:
    Product();
    Product(int id, std::string name, Category category, unsigned int numInStock, double price);
    Product(const Product &product);

    int get_id() const;
    std::string get_name() const;
    Category get_category() const;
    unsigned int get_numInStock() const;
    double get_price() const;

    void set_id(int id);
    void set_name(std::string name);
    void set_category(Category category);
    void set_numInStock(unsigned int numInStock);
    void set_price(double price);

    void sell(unsigned int quantity);
};

#endif