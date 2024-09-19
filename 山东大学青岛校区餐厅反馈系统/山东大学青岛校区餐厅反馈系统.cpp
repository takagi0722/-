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

    // �ļ������ڵ����
    if (!ifs.is_open()) {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    string id;
    string name;
    string pwd;

    cout << "����������û���" << endl;
    cin >> name;

    cout << "�������˻�" << endl;
    cin >> id;

    cout << "����������" << endl;
    cin >> pwd;

    // �û���¼
    if (type == 1) {
        string fName, fId, fPwd;
        while (ifs >> fName >> fId >> fPwd) {
            if (name == fName && id == fId && pwd == fPwd) {
                cout << "�û���֤��¼�ɹ�" << endl;
                person = new Users(name, id, pwd);
                break;
            }
        }
    }
    // ����Ա��¼
    else if (type == 2) {
        string fId, fPwd;
        while (ifs >> fId >> fPwd) {
            if (id == fId && pwd == fPwd) {
                cout << "����Ա��֤��¼�ɹ���" << endl;
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
                    cout << "��Чѡ�����������롣" << endl;
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
                    cout << "��Чѡ�����������롣" << endl;
                    break;
                }
            }
            person->operMenu();
        }
    }
    else {
        cout << "��֤��¼ʧ��" << endl;
        system("pause");
        system("cls");
    }

    delete person;
}

int main() {
    int select = 0;

    while (true) {
        cout << "��ӭ����������ɽ�ࡪ��ɽ����ѧ�ൺУ����������ϵͳ" << endl;
        cout << " �������������" << endl;
        cout << "\t\t|------------------------------------|\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|           1.�û�(��ʦ/ѧ��)        |\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|           2.  ����Ա               |\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|           0.   �˳�                |\n";
        cout << "\t\t|                                    |\n";
        cout << "\t\t|------------------------------------|\n";
        cout << "����������ѡ��";

        cin >> select;

        switch (select) {
        case 1:
            LoginIn(USERS_FILE, 1);
            break;
        case 2:
            LoginIn(ADMIN_FILE, 2);
            break;
        case 0:
            cout << "��ӭ��һ��ʹ��" << endl;
            system("pause");
            return 0;
        default:
            cout << "��������������ѡ��!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}
