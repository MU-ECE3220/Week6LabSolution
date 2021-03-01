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

void ProductVector::exportProductsToText(std::string filepath)
{
    std::ofstream file(filepath);

    file << get_count() << std::endl;

    std::vector<Product>::iterator iter;
    for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
        file << (*iter).to_export_string();

    file.close();
}

size_t ProductVector::get_count()
{
    return productsVector_.size();
}

Product* ProductVector::get_productByIndex(size_t index)
{
    try
    {
        if (index > productsVector_.size() - 1)
            throw std::string("Exception: Vector index out of range.");
        
        return &(productsVector_[index]);
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;

        return NULL;
    }
}

Product* ProductVector::get_productByID(int id)
{
    try
    {
        std::vector<Product>::iterator iter;
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
        {
            if ((*iter).get_id() == id)
                return &(*iter);
        }
        throw std::string("Exception: No product with ID " + std::to_string(id) + ".");
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;

        return NULL;
    }
}

void ProductVector::add_product(const Product &product)
{
    std::vector<Product>::iterator iter;
    try
    {
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
            if ((*iter).get_id() == product.get_id())
                throw std::string("Exception: Duplicate ID.");

        productsVector_.push_back(product);
        std::cout << "Product " << product.get_name() << " with ID " 
                    << product.get_id() << " successfully added." << std::endl;
    }
    catch(const std::string &e)
    {
        std::cerr << e << std::endl;
        std::cerr << "Duplicate product " << product.get_name() 
                    << " with ID of " << product.get_id() << " not added." << std::endl;
    }
}

Product* ProductVector::find_mostExpensiveProduct()
{
    try
    {
        if (productsVector_.size() == 0)
            throw std::string("Exception: Products vector has no elements.");

        std::vector<Product>::iterator iter;
        Product* productMax;
        double globalMax = -1.0;
    
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
            if ((*iter).get_price() > globalMax)
            {
                globalMax = (*iter).get_price();
                productMax = &(*iter);
            }

        return productMax;
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;

        return NULL;
    }
}

Product* ProductVector::find_leastExpensiveProduct()
{
    try
    {
        if (productsVector_.size() == 0)
            throw std::string("Exception: Products vector has no elements.");

        std::vector<Product>::iterator iter;
        Product* productMin;
        double globalMin = std::numeric_limits<double>::max();
    
        for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
            if ((*iter).get_price() < globalMin)
            {
                globalMin = (*iter).get_price();
                productMin = &(*iter);
            }

        return productMin;
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;

        return NULL;
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

void ProductVector::print()
{
    std::vector<Product>::iterator iter;

    for (iter = productsVector_.begin(); iter != productsVector_.end(); iter++)
        std::cout << (*iter).to_string();
}