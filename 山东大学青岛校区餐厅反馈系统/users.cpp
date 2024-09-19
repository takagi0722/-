#include "users.h"

// Users ���Ĭ�Ϲ��캯��
Users::Users() {}

// Users ��Ĵ��������캯��
Users::Users(const std::string& name, const std::string& id, const std::string& pwd) {
    this->m_Name = name;  // ����Ա���� m_Name ����Ϊ�ṩ�� name
    this->m_Id = id;      // ����Ա���� m_Id ����Ϊ�ṩ�� id
    this->m_Pwd = pwd;    // ����Ա���� m_Pwd ����Ϊ�ṩ�� pwd�����룩
}

// ��ʾ�û������˵��ķ���
void Users::operMenu() {
    std::cout << "��ӭ�û�:" << this->m_Name << " ��¼" << std::endl;
    std::cout << "\t\t|------------------------------------|\n";
    std::cout << "\t\t|                                    |\n";
    std::cout << "\t\t|           1.������в�Ʒ           |\n";
    std::cout << "\t\t|                                    |\n";
    std::cout << "\t\t|           2.������Ʒ               |\n";
    std::cout << "\t\t|                                    |\n";
    std::cout << "\t\t|           3.�ύ���               |\n";
    std::cout << "\t\t|------------------------------------|\n";
    std::cout << "����������ѡ��";
}

// ������в�Ʒ�ķ���
void Users::BrowseAllDishes() {
    std::ifstream file(DISHES_FILE); // �򿪲�Ʒ�ļ�
    std::string line;

    // ���ж�ȡ�ļ����ݲ����������̨
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close(); // �ر��ļ�
}

// ������Ʒ�ķ���
void Users::SearchForDishes() {
    std::cout << "������Ҫ�����Ĳ�����";
    std::string name;
    std::cin >> name; // ����Ҫ�����Ĳ���

    std::ifstream file(DISHES_FILE); // �򿪲�Ʒ�ļ�
    std::string line;

    // ���ж�ȡ�ļ�����
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dishName;
        iss >> dishName; // ���ļ����ж�ȡ����

        // ����ҵ�ƥ��Ĳ�����������в�����
        if (dishName == name) {
            std::cout << line << std::endl;
            return;
        }
    }

    std::cout << "δ�ҵ���ز�Ʒ��" << std::endl; // ���û���ҵ�ƥ��Ĳ����������ʾ��Ϣ
}

// �ύ����ķ���
void Users::SubmitComment() {
    std::cout << "���������������";
    std::string comment;
    std::cin.ignore(); // �����������еĻ��з�
    std::getline(std::cin, comment); // �������

    std::ofstream ofs(COMMENTS_FILE, std::ios::app); // ��׷��ģʽ������ļ�
    ofs << comment << std::endl; // �����д���ļ�
    ofs.close(); // �ر��ļ�
    std::cout << "�ύ����ɹ���" << std::endl; // ����ύ�ɹ�����ʾ��Ϣ
}
