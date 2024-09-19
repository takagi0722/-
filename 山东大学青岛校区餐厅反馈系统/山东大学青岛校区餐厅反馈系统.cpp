#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "globalFile.h"
#include "identity.h"
#include "users.h"
#include "manager.h"

void LoginIn(string fileName, int type) {
    Identity* person = NULL;

    ifstream ifs(fileName, ios::in);

    // 文件不存在的情况
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    string id;
    string name;
    string pwd;

    cout << "请输入你的用户名" << endl;
    cin >> name;

    cout << "请输入账户" << endl;
    cin >> id;

    cout << "请输入密码" << endl;
    cin >> pwd;

    // 用户登录
    if (type == 1) {
        string fName, fId, fPwd;
        while (ifs >> fName >> fId >> fPwd) {
            if (name == fName && id == fId && pwd == fPwd) {
                cout << "用户验证登录成功" << endl;
                person = new Users(name, id, pwd);
                break;
            }
        }
    }
    // 管理员登录
    else if (type == 2) {
        string fId, fPwd;
        while (ifs >> fId >> fPwd) {
            if (id == fId && pwd == fPwd) {
                cout << "管理员验证登录成功！" << endl;
                person = new Manager(id, pwd);
                break;
            }
        }
    }

    if (person != NULL) {
        system("pause");
        system("cls");
        person->operMenu();

        int choice;
        while (cin >> choice) {
            system("cls");
            if (type == 1) {
                Users* user = dynamic_cast<Users*>(person);
                switch (choice) {
                case 1:
                    user->BrowseAllDishes();
                    break;
                case 2:
                    user->SearchForDishes();
                    break;
                case 3:
                    user->SubmitComment();
                    break;
                default:
                    cout << "无效选择，请重新输入。" << endl;
                    break;
                }
            }
            else if (type == 2) {
                Manager* manager = dynamic_cast<Manager*>(person);
                switch (choice) {
                case 1:
                    manager->AddManager();
                    break;
                case 2:
                    manager->DeleteManager();
                    break;
                case 3:
                    manager->UpdateManagerPassword();
                    break;
                case 4:
                    manager->AddDishes();
                    break;
                case 5:
                    manager->DeleteDishes();
                    break;
                case 6:
                    manager->ViewComments();
                    break;
                default:
                    cout << "无效选择，请重新输入。" << endl;
                    break;
                }
            }
            person->operMenu();
        }
    }
    else {
        cout << "验证登录失败" << endl;
        system("pause");
        system("cls");
    }

    delete person;
}

int main() {
    int select = 0;

    while (true) {
        cout << "欢迎来到：饕在山青——山东大学青岛校区餐厅反馈系统" << endl;
        cout << " 请输入您的身份" << endl;
        cout << "\t\t|------------------------------------|\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|           1.用户(教师/学生)        |\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|           2.  管理员               |\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|           0.   退出                |\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|------------------------------------|\n";
        cout << "请输入您的选择：";

        cin >> select;

        switch (select) {
        case 1:
            LoginIn(USERS_FILE, 1);
            break;
        case 2:
            LoginIn(ADMIN_FILE, 2);
            break;
        case 0:
            cout << "欢迎下一次使用" << endl;
            system("pause");
            return 0;
        default:
            cout << "输入有误，请重新选择!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}
