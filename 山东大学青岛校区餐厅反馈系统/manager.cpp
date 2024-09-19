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
    cout << "��ӭ����Ա:" << this->m_id << " ��¼" << endl;
    cout << "\t\t|------------------------------------|\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           1.��ӹ���Ա             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           2.ɾ������Ա             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           3.�޸Ĺ���Ա����         |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           4.��Ӳ�Ʒ               |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           5.ɾ����Ʒ               |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|           6.�鿴���               |\n";
    cout << "\t\t|------------------------------------|\n";
    cout << "����������ѡ��";
}

void Manager::AddManager() {
    cout << "�������¹���Ա�˺ţ�8λ���֣���";
    string id;
    cin >> id;
    cout << "�������¹���Ա���루9λ���֣���";
    string pwd;
    cin >> pwd;

    ofstream ofs(ADMIN_FILE, ios::app);
    ofs << id << " " << pwd << endl;
    ofs.close();
    cout << "��ӹ���Ա�ɹ���" << endl;
}

void Manager::DeleteManager() {
    cout << "������Ҫɾ���Ĺ���Ա�˺ţ�";
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
    cout << "ɾ������Ա�ɹ���" << endl;
}

void Manager::UpdateManagerPassword() {
    cout << "������Ҫ�޸ĵĹ���Ա�˺ţ�";
    string id;
    cin >> id;
    cout << "�������µĹ���Ա���루9λ���֣���";
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
    cout << "�޸Ĺ���Ա����ɹ���" << endl;
}

void Manager::AddDishes() {
    cout << "�����������";
    string name;
    cin >> name;
    cout << "������ʳ�ģ�";
    string ingredients;
    cin >> ingredients;
    cout << "������ص㣨������¥�㡢���ڣ���";
    string location;
    cin >> location;
    cout << "������۸�";
    double price;
    cin >> price;

    ofstream ofs(DISHES_FILE, ios::app);
    ofs << name << " " << ingredients << " " << location << " " << price << endl;
    ofs.close();
    cout << "��Ӳ�Ʒ�ɹ���" << endl;
}

void Manager::DeleteDishes() {
    cout << "������Ҫɾ���Ĳ�����";
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
    cout << "ɾ����Ʒ�ɹ���" << endl;
}

void Manager::ViewComments() {
    ifstream ifs(COMMENTS_FILE);
    if (!ifs.is_open()) {
        cout << "�޷����ļ���" << endl;
        return;
    }
    string comment;
    while (getline(ifs, comment)) {
        cout << comment << endl;
    }
    ifs.close();
}
