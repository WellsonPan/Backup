// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
private:
	std::string code, name;
	double price;

public:
	// Create a product with a given code, name, and price.
	//
	// code is intended to be a UPC code (bar code) or PLU code in a
	// string.
	//
	// name may be any string.
	//
	// price is in units of dollars. It must be positive, or else this
	// function throws std::invalid_argument.
	Product(const std::string& code, const std::string& name, double price) {
		if (price < 0)
		{
			throw std::invalid_argument("Price is negative");
		}
		else
		{
			this->code = code;
			this->name = name;
			this->price = price;
		}
		//throw logic_error("not implemented yet");
	}

	~Product() {}

	Product()
	{}

	// Accessors.
	const std::string& getCode() const { return code; }
	const std::string& getName() const { return name; }
	double getPrice() const { return price; }
};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
private:
	int max;
	int currentAmount = 0;
	Product * catalogOfProducts;

public:
	// Create a new catalog.
	//
	// maxProducts is the maximum number of products that can be
	// stored. It must be positive, or else this function throws
	// std::invalid_argument.
	Catalog(int maxProducts) {
		if (maxProducts <= 0)
		{
			throw std::invalid_argument("There cannot be negative or zero items");
		}
		else
		{
			max = maxProducts;
			catalogOfProducts = new Product[maxProducts];
		}
		// TODO: implement this function properly
		//throw logic_error("not implemented yet");
	}

	~Catalog() {
		delete[] catalogOfProducts;
		// TODO: implement this function properly
		//throw logic_error("not implemented yet");
	}

	// Accessors.
	int getMaxProducts() const {
		return max;
		// TODO: implement this function properly
		//throw logic_error("not implemented yet");
	}

	int getNumProducts() const {
		return currentAmount;
		// TODO: implement this function properly
		//throw logic_error("not implemented yet");
	}

	// Return true when the catalog cannot fit any more products.
	bool isFull() const {
		return currentAmount == max;
		// TODO: implement this function properly
		//throw logic_error("not implemented yet");
	}

	// Add a new product to the catalog with a given code and name.
	//
	// code, name, and price have the same meaning as in a Product. If
	// price is invalid, throw std::invalid_argument.
	//
	// If this catalog is already full, throw overflow_error.
	//
	// Code must be different from all the product codes already in the
	// database. If it's not, throw std::invalid_argument.
	void addProduct(const std::string& code, const std::string& name, double price) {
		bool flag = false;
		if (currentAmount != 0)
		{
			for (int index = 0; index < currentAmount; index++)
			{
				if ((catalogOfProducts[index].getCode()) == code)
				{
					flag = true;
					index = max;
				}
			}
		}

		if (isFull())
		{
			throw std::overflow_error("Adding to full array");
		}
		else if (price < 0)
		{
			throw std::invalid_argument("Price cannot be negative");
		}
		else if (flag)
		{
			throw std::invalid_argument("Code matches another code");
		}
		else
		{
			Product newProduct(code, name, price);
			catalogOfProducts[currentAmount] = newProduct;
			currentAmount++;
		}
	}

	// Find a product by its code.
	//
	// code is a product code.
	//
	// Returns a const reference to the product with the matching code.
	//
	// Throw std::invalid_argument if no product with that code exists
	// in the catalog.
	const Product& findCode(const std::string& code) const {
		Product * found = new Product("", "", 0);

		for (int index = 0; index < currentAmount; index++)
		{
			if (catalogOfProducts[index].getCode() == code)
			{
				*found = catalogOfProducts[index];
				index = currentAmount;
			}
		}
		if (((found->getCode()) == "") && ((found->getName()) == "") && (found->getPrice() == 0))
		{
			throw std::invalid_argument("A product with that code does not exist");
		}
		return *found;
		//throw logic_error("not implemented yet");
	}
};