#pragma once
#include "identity.h"
#include <string>
using namespace std;

class Manager : public Identity {
public:
    Manager();
    Manager(string id, string pwd);
    virtual void operMenu();

    void AddManager();
    void DeleteManager();
    void UpdateManagerPassword();
    void AddDishes();
    void DeleteDishes();
    void ViewComments();

    string m_id;
};
