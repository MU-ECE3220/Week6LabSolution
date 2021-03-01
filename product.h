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

    std::string to_string();
    std::string to_export_string();
    static std::string category_to_string(Category category);

    /*
    * This function converts a Category type to its integer representation. 
    * Its implementation is something you're not used to. static_cast<toType>(fromType) will 
    * is a compile-time cast. Not all casts will work, and the compiler will throw errors. toType is 
    * the desired type to cast to. fromType is the type that you want to convert.
    * 
    * The typename keyword means that whatever follows it is a type. 
    * std::underlying_type<variable or class >::type gets the underlying type of a variable or class. 
    * For enum, the underlying type is an integer.
    * @param category This is the category to be converted to an int.
    * @return The integer representation of the Category enum type.
    */
    static int category_to_integer(Category category);
    static std::string double_to_string_precision(double dvalue, size_t precision);
};

#endif