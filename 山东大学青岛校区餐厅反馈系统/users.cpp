#include "users.h"

// Users 类的默认构造函数
Users::Users() {}

// Users 类的带参数构造函数
Users::Users(const std::string& name, const std::string& id, const std::string& pwd) {
    this->m_Name = name;  // 将成员变量 m_Name 设置为提供的 name
    this->m_Id = id;      // 将成员变量 m_Id 设置为提供的 id
    this->m_Pwd = pwd;    // 将成员变量 m_Pwd 设置为提供的 pwd（密码）
}

// 显示用户操作菜单的方法
void Users::operMenu() {
    std::cout << "欢迎用户:" << this->m_Name << " 登录" << std::endl;
    std::cout << "\t\t|------------------------------------|\n";
    std::cout << "\t\t|                                    |\n";
    std::cout << "\t\t|           1.浏览所有菜品           |\n";
    std::cout << "\t\t|                                    |\n";
    std::cout << "\t\t|           2.搜索菜品               |\n";
    std::cout << "\t\t|                                    |\n";
    std::cout << "\t\t|           3.提交意见               |\n";
    std::cout << "\t\t|------------------------------------|\n";
    std::cout << "请输入您的选择：";
}

// 浏览所有菜品的方法
void Users::BrowseAllDishes() {
    std::ifstream file(DISHES_FILE); // 打开菜品文件
    std::string line;

    // 逐行读取文件内容并输出到控制台
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close(); // 关闭文件
}

// 搜索菜品的方法
void Users::SearchForDishes() {
    std::cout << "请输入要搜索的菜名：";
    std::string name;
    std::cin >> name; // 输入要搜索的菜名

    std::ifstream file(DISHES_FILE); // 打开菜品文件
    std::string line;

    // 逐行读取文件内容
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dishName;
        iss >> dishName; // 从文件行中读取菜名

        // 如果找到匹配的菜名，输出该行并返回
        if (dishName == name) {
            std::cout << line << std::endl;
            return;
        }
    }

    std::cout << "未找到相关菜品。" << std::endl; // 如果没有找到匹配的菜名，输出提示信息
}

// 提交意见的方法
void Users::SubmitComment() {
    std::cout << "请输入您的意见：";
    std::string comment;
    std::cin.ignore(); // 忽略输入流中的换行符
    std::getline(std::cin, comment); // 输入意见

    std::ofstream ofs(COMMENTS_FILE, std::ios::app); // 以追加模式打开意见文件
    ofs << comment << std::endl; // 将意见写入文件
    ofs.close(); // 关闭文件
    std::cout << "提交意见成功！" << std::endl; // 输出提交成功的提示信息
}
