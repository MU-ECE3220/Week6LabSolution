#include <iostream>
#include <string>
#include <vector>

#include "product.h"
#include "productVector.h"

int main(int argc, char** argv)
{
    ProductVector productVector("products.txt");
    std::cout << "Number of products imported: " << productVector.get_count() << std::endl;
    std::cout << "Item at position 10: " << productVector.get_productByID(10)->to_string() << std::endl;

    Product newProduct(40, "Fancy Electronic", Category::ELECTRONICS, 5, 93.99);
    productVector.add_product(newProduct);
    std::cout << "Item with ID 40: " << productVector.get_productByID(40)->to_string() << std::endl;

    std::cout << "Most expensive product: " << productVector.find_mostExpensiveProduct()->to_string() << std::endl;
    std::cout << "Least expensive product: " << productVector.find_leastExpensiveProduct()->to_string() << std::endl;

    std::cout << "Sell all of the most expensive product: " << std::endl; 
    productVector.find_mostExpensiveProduct()->sell(4);
    std::cout << "Sell all of item with ID 40: " << std::endl; 
    productVector.get_productByID(40)->sell(5);

    std::cout << "Get out of stock vector: " << std::endl;
    std::vector<Product> outOfStockVector = productVector.get_outOfStockVector();
    std::cout << "Number of out of stock items: " << outOfStockVector.size() << std::endl;

    std::cout << "Test try/catch in getting product: " << std::endl;
    Product* ptest1 = productVector.get_productByIndex(100);
    if (ptest1 != NULL)
        ptest1->to_string();

    std::cout << "Test try/catch in getting product: " << std::endl;
    Product* ptest2 = productVector.get_productByID(100);
    if (ptest2 != NULL)
        ptest2->to_string();

    productVector.exportProductsToText("productsExport.txt");
    productVector.print();
}