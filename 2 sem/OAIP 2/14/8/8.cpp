#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

const int TABLE_SIZE = 128;

struct HashNode {
	std::string key;
	int value;
	bool is_deleted;

	HashNode() : key(""), value(-1), is_deleted(false) {}
};

class HashTable {
private:
	std::vector<HashNode> table;

public:
	HashTable() : table(TABLE_SIZE) {}

	static unsigned int hash(const std::string& key, unsigned int p = 1000000007, unsigned int a = 31, unsigned int b = 17, unsigned int m = 1000) {
		unsigned int hash = 0;
		for (char c : key) {
			hash = ((hash * a + c) % p + b) % m;
		}
		return hash;
	}

	// Вставка элемента в хеш-таблицу
	void insert(std::string key, int value) {

		// Вычисляем хеш-код
		unsigned int index = hash(key) % TABLE_SIZE;

		// Открытая адресация
		while (!table[index].key.empty() && !table[index].is_deleted) {
			index = (index + 1) % TABLE_SIZE;
		}

		table[index].key = key;
		table[index].value = value;
		table[index].is_deleted = false;
	}

	// Получение значения элемента по ключу
	int get(std::string key) {

		unsigned int index = hash(key) % TABLE_SIZE;
		for (int i = 0; i < TABLE_SIZE; ++i) {
			if (table[index].key == key && !table[index].is_deleted) {
				return table[index].value;
			}
			index = (index + 1) % TABLE_SIZE;
		}
		return -1; // Возвращаем -1, если элемент не найден
	}

	// Удаление элемента по ключу
	void remove(std::string key) {

		unsigned int index = hash(key) % TABLE_SIZE;
		for (int i = 0; i < TABLE_SIZE; ++i) {
			if (table[index].key == key && !table[index].is_deleted) {
				table[index].is_deleted = true;
				return;
			}
			index = (index + 1) % TABLE_SIZE;
		}
	}

	// Вывод хеш-таблицы
	void print() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			std::cout << i << ": ";
			if (!table[i].key.empty() && !table[i].is_deleted) {
				std::cout << "[" << table[i].key << ", " << table[i].value << "] ";
			}
			std::cout << std::endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Rus");

	HashTable table;

	int choice = 0;
	while (choice != 5) {
		std::cout << "1. Вставить элемент в хеш-таблицу" << std::endl;
		std::cout << "2. Найти элемент в хеш-таблице" << std::endl;
		std::cout << "3. Удалить элемент из хеш-таблицы" << std::endl;
		std::cout << "4. Распечатать хеш-таблицу" << std::endl;
		std::cout << "5. Выйти из программы" << std::endl;

		std::cout << "Введите номер команды: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::string key;
			std::cout << "Введите ключ: ";
			std::cin >> key;

			int value;
			std::cout << "Введите значение: ";
			std::cin >> value;

			table.insert(key, value);
			std::cout << "Элемент добавлен в хеш-таблицу" << std::endl;
			break;
		}
		case 2: {
			std::string key;
			std::cout << "Введите ключ: ";
			std::cin >> key;
			int value = table.get(key);
			if (value == -1) {
				std::cout << "Элемент не найден" << std::endl;
			}
			else {
				std::cout << "Значение элемента: " << value << std::endl;
			}
			break;
		}
		case 3: {
			std::string key;
			std::cout << "Введите ключ: ";
			std::cin >> key;
			table.remove(key);
			std::cout << "Элемент удален из хеш-таблицы" << std::endl;
			break;
		}
		case 4: {
			std::cout << "Хеш-таблица: " << std::endl;
			table.print();
			break;
		}
		case 5: {
			std::cout << "До свидания!" << std::endl;
			break;
		}
		default: {
			std::cout << "Некорректный выбор, попробуйте еще раз" << std::endl;
			break;
		}
		}
	}

	return 0;
}
