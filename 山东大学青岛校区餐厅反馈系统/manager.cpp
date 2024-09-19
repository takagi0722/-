#include "manager.h"
#include "globalFile.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Manager::Manager() {}

Manager::Manager(string id, string pwd) {
    this->m_id = id;
    this->m_Pwd = pwd;
}

void Manager::operMenu() {
    cout << "欢迎管理员:" << this->m_id << " 登录" << endl;
    cout << "\t\t|------------------------------------|\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           1.添加管理员             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           2.删除管理员             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           3.修改管理员密码         |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           4.添加菜品               |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           5.删除菜品               |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           6.查看意见               |\n";
    cout << "\t\t|------------------------------------|\n";
    cout << "请输入您的选择：";
}

void Manager::AddManager() {
    cout << "请输入新管理员账号（8位数字）：";
    string id;
    cin >> id;
    cout << "请输入新管理员密码（9位数字）：";
    string pwd;
    cin >> pwd;

    ofstream ofs(ADMIN_FILE, ios::app);
    ofs << id << " " << pwd << endl;
    ofs.close();
    cout << "添加管理员成功！" << endl;
}

void Manager::DeleteManager() {
    cout << "请输入要删除的管理员账号：";
    string id;
    cin >> id;

    ifstream ifs(ADMIN_FILE);
    vector<string> admins;
    string line;
    while (getline(ifs, line)) {
        if (line.find(id) == string::npos) {
            admins.push_back(line);
        }
    }
    ifs.close();

    ofstream ofs(ADMIN_FILE);
    for (const auto& admin : admins) {
        ofs << admin << endl;
    }
    ofs.close();
    cout << "删除管理员成功！" << endl;
}

void Manager::UpdateManagerPassword() {
    cout << "请输入要修改的管理员账号：";
    string id;
    cin >> id;
    cout << "请输入新的管理员密码（9位数字）：";
    string newPwd;
    cin >> newPwd;

    ifstream ifs(ADMIN_FILE);
    vector<string> admins;
    string line;
    while (getline(ifs, line)) {
        if (line.find(id) != string::npos) {
            line = id + " " + newPwd;
        }
        admins.push_back(line);
    }
    ifs.close();

    ofstream ofs(ADMIN_FILE);
    for (const auto& admin : admins) {
        ofs << admin << endl;
    }
    ofs.close();
    cout << "修改管理员密码成功！" << endl;
}

void Manager::AddDishes() {
    cout << "请输入菜名：";
    string name;
    cin >> name;
    cout << "请输入食材：";
    string ingredients;
    cin >> ingredients;
    cout << "请输入地点（餐厅、楼层、窗口）：";
    string location;
    cin >> location;
    cout << "请输入价格：";
    double price;
    cin >> price;

    ofstream ofs(DISHES_FILE, ios::app);
    ofs << name << " " << ingredients << " " << location << " " << price << endl;
    ofs.close();
    cout << "添加菜品成功！" << endl;
}

void Manager::DeleteDishes() {
    cout << "请输入要删除的菜名：";
    string name;
    cin >> name;

    ifstream ifs(DISHES_FILE);
    vector<string> dishes;
    string line;
    while (getline(ifs, line)) {
        if (line.find(name) == string::npos) {
            dishes.push_back(line);
        }
    }
    ifs.close();

    ofstream ofs(DISHES_FILE);
    for (const auto& dish : dishes) {
        ofs << dish << endl;
    }
    ofs.close();
    cout << "删除菜品成功！" << endl;
}

void Manager::ViewComments() {
    ifstream ifs(COMMENTS_FILE);
    if (!ifs.is_open()) {
        cout << "无法打开文件。" << endl;
        return;
    }
    string comment;
    while (getline(ifs, comment)) {
        cout << comment << endl;
    }
    ifs.close();
}
