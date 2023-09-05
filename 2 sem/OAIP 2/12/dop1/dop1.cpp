#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Определяем структуру для хранения информации об абонентах
struct Subscriber {
    string name;    // Имя владельца телефона
    string phone;   // Номер телефона
    string tariff;  // Тарифный план
};

// Определяем структуру для узла бинарного дерева
struct TreeNode {
    Subscriber data;    // Данные об абоненте
    TreeNode* left;     // Указатель на левый подузел
    TreeNode* right;    // Указатель на правый подузел
};

// Функция для создания нового узла дерева
TreeNode* createNode(Subscriber subscriber) {
    TreeNode* newNode = new TreeNode();
    newNode->data = subscriber;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Функция для добавления нового узла в дерево
void addNode(TreeNode*& root, Subscriber subscriber) {
    if (root == nullptr) {
        root = createNode(subscriber);
    }
    else if (subscriber.phone < root->data.phone) {
        addNode(root->left, subscriber);
    }
    else {
        addNode(root->right, subscriber);
    }
}

// Функция для вывода всех абонентов в дереве
void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << "Name: " << root->data.name << endl;
        cout << "Phone: " << root->data.phone << endl;
        cout << "Tariff: " << root->data.tariff << endl;
        cout << endl;
        printTree(root->right);
    }
}

// Функция для поиска владельца по номеру телефона
Subscriber findSubscriber(TreeNode* root, string phone) {
    if (root == nullptr || root->data.phone == phone) {
        return root->data;
    }
    else if (phone < root->data.phone) {
        return findSubscriber(root->left, phone);
    }
    else {
        return findSubscriber(root->right, phone);
    }
}


// Функция для подсчета количества абонентов на каждом тарифном плане
void countTariffs(TreeNode* root, vector<string>& tariffs, vector<int>& counts) {
    if (root != nullptr) {
        // Ищем индекс текущего тарифного плана в векторе tariffs
        int index = -1;
        for (int i = 0; i < tariffs.size(); i++) {
            if (tariffs[i] == root->data.tariff) {
                index = i;
                break;
            }
        }
        // Если тарифный план еще не встречался, добавляем его в векторы tariffs и counts
        if (index == -1) {
            tariffs.push_back(root->data.tariff);
            counts.push_back(1);
        }
        else {
            // Иначе увеличиваем счетчик абонентов на текущем тарифном плане
            counts[index]++;
        }

        countTariffs(root->left, tariffs, counts);
        countTariffs(root->right, tariffs, counts);
    }
}

// Функция для определения наиболее востребованного тарифа
string findPopularTariff(TreeNode* root) {
    vector<string> tariffs;
    vector<int> counts;
    countTariffs(root, tariffs, counts);

    int maxCount = -1;
    string popularTariff;
    for (int i = 0; i < tariffs.size(); i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            popularTariff = tariffs[i];
        }
    }

    return popularTariff;
}

void printMenu() {
    cout << "1. Добавить нового абонента\n";
    cout << "2. Вывести список абонентов\n";
    cout << "3. Найти абонента по номеру телефона\n";
    cout << "4. Найти наиболее востребованный тариф\n";
    cout << "0. Выход\n";
}

bool isValid(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}


int main() {
    setlocale(LC_ALL, "Rus");
    // Создаем базу данных абонентов в виде бинарного дерева
    TreeNode* root = nullptr;
    while (true) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            Subscriber sub;
            cout << "Введите имя абонента: ";
            cin >> sub.name;
            cout << "Введите номер телефона: ";
            cin >> sub.phone;
            if (!isValid(sub.phone)) {
                cout << "Партия вами не довольна! Вы соврали о номере телефона!";
                exit(1);
            }
            cout << "Введите тарифный план: ";
            cin >> sub.tariff;
            addNode(root, sub);
            break;
        }
        case 2: {
            cout << "Список абонентов:\n";
            printTree(root);
            break;
        }
        case 3: {
            string phone;
            cout << "Введите номер телефона: ";
            cin >> phone;
            Subscriber sub = findSubscriber(root, phone);
            if (sub.name != "") {
                cout << "Абонент найден: " << sub.name << " " << sub.phone << " " << sub.tariff << endl;
            }
            else {
                cout << "Абонент не найден\n";
            }
            break;
        }
        case 4: {
            string popularTariff = findPopularTariff(root);
            cout << "Наиболее востребованный тарифный план: " << popularTariff << endl;
            break;
        }
        case 0: {
            return 0;
        }
        default: {
            cout << "Некорректный выбор\n";
            break;
        }
        }
    }

    return 0;
}