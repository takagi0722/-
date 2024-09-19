#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "globalFile.h"
#include "identity.h"
#include "dish.h" 

class Users : public Identity {
private:
    std::vector<Dish> m_Dishes;
    string m_Id;
public:
    Users();
    Users(const std::string& name, const std::string& id, const std::string& pwd); // Constructor with parameters
    void operMenu() override;
    void BrowseAllDishes();
    void SearchForDishes();
    void SubmitComment();

    string m_id;
};
