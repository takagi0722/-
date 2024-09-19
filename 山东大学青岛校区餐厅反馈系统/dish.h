#ifndef DISH_H
#define DISH_H

#include <string>
#include <vector>

class Dish {
private:
    std::string name;
    std::string ingredients;
    std::string location;
    std::string price;

public:
    Dish(); // Default constructor

    Dish(const std::string& name, const std::string& ingredients, const std::string& location, const std::string& price);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getIngredients() const;
    void setIngredients(const std::string& ingredients);
    std::string getLocation() const;
    void setLocation(const std::string& location);
    std::string getPrice() const;
    void setPrice(const std::string& price);
    static std::vector<Dish> readDishesFromFile(const std::string& fileName);
};

#endif // DISH_H
#pragma once
