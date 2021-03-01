#ifndef PRODUCT_VECTOR_H
#define PRODUCT_VECTOR_H

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "product.h"

class ProductVector
{
private:
    std::vector<Product> productsVector_;

public:
    ProductVector();
    /*
    * This constructor reads in a file of products to initialize.
    * It uses a static_cast to convert between from an integer type to enum. 
    * Explicitly, the conversion static_cast<Category>(categoryInt) returns a Category enum set 
    * from the integer categoryInt.
    * 
    * @param importFilePath An std::string type that contains the path to an input file.
    */
    ProductVector(std::string importFilePath);

    void exportProductsToText(std::string filepath);
    size_t get_count();
    Product* get_productByIndex(size_t index);
    Product* get_productByID(int id);
    void add_product(const Product &product);
    Product* find_mostExpensiveProduct();
    Product* find_leastExpensiveProduct();
    std::vector<Product> get_outOfStockVector();
    void print();
};

#endif