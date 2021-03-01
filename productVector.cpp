#include "productVector.h"

ProductVector::ProductVector(){}

ProductVector::ProductVector(std::string importFilePath)
{
    std::ifstream file(importFilePath);
    std::string line;

    getline(file, line);
    int numOfProducts = std::stoi(line);

    int id, categoryInt;
    std::string name;
    Category category;
    unsigned int numInStock;
    double price;
    for (int i = 0; i < numOfProducts; i++)
    {
        getline(file, line);
        id = stoi(line);
        
        getline(file, line);
        name.assign(line);

        getline(file, line);
        categoryInt = stoi(line);
        category = static_cast<Category>(categoryInt);

        getline(file, line);
        numInStock = stoi(line);

        getline(file, line);
        price = std::stod(line);

        Product p(id, name, category, numInStock, price);
        productsVector_.push_back(p);
    }
    file.close();
}

size_t ProductVector::get_count()
{
    return productsVector_.size();
}

Product ProductVector::get_product(size_t index)
{
    try
    {
        if (index > productsVector_.size() - 1)
            throw std::out_of_range("Exception: Index out of range.");
        
        return productsVector_[index];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;

        Product invalidProduct;
        invalidProduct.set_name("INVALID");
        return invalidProduct;
    }

}

void ProductVector::add_product(const Product &product)
{
    std::vector<Product>::iterator iter;
    try
    {
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
            if ((*iter).get_id() == product.get_id())
                throw std::invalid_argument("Exception: Duplicate ID.");

        productsVector_.push_back(product);
        std::cout << "Product " << product.get_name() << " with ID " 
                    << product.get_id() << " successfully added." << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "Duplicate product " << product.get_name() 
                    << " with ID of " << product.get_id() << " not added." << std::endl;
    }
}

Product ProductVector::find_mostExpensiveProduct()
{
    try
    {
        if (productsVector_.size() == 0)
            throw std::length_error("Exception: Products vector has no elements.");

        std::vector<Product>::iterator iter;
        Product* productMax;
        double globalMax = -1.0;
    
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
            if ((*iter).get_price() > globalMax)
                productMax = &(*iter);

        return *productMax;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;

        Product invalidProduct;
        invalidProduct.set_name("INVALID");
        return invalidProduct;
    }
}

Product ProductVector::find_leastExpensiveProduct()
{
    try
    {
        if (productsVector_.size() == 0)
            throw std::length_error("Exception: Products vector has no elements.");

        std::vector<Product>::iterator iter;
        Product* productMin;
        double globalMin = std::numeric_limits<double>::max();
    
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
            if ((*iter).get_price() < globalMin)
                productMin = &(*iter);

        return *productMin;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;

        Product invalidProduct;
        invalidProduct.set_name("INVALID");
        return invalidProduct;
    }
}

std::vector<Product> ProductVector::get_outOfStockVector()
{
    std::vector<Product> outOfStockVector;
    std::vector<Product>::iterator iter;

    for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
    {
        if ((*iter).get_numInStock() == 0)
        {
            Product p(*iter);
            outOfStockVector.push_back(p);
        }
    }
    
    return outOfStockVector;
}