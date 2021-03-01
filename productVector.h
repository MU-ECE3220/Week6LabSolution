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
    ProductVector(std::string importFilePath);

    size_t get_count();
    Product get_product(size_t index);
    void add_product(const Product &product);
    Product find_mostExpensiveProduct();
    Product find_leastExpensiveProduct();
    std::vector<Product> get_outOfStockVector();
};

#endif