#include <iostream>
#include <fstream>

int main() {
    // Запрашиваем у пользователя путь к файлу
    std::cout << "Enter the path to the text file: ";
    std::string filePath;
    std::cin >> filePath;

    // Открываем файл в бинарном режиме
    std::ifstream file(filePath, std::ios::binary);

    // Проверяем, был ли файл успешно открыт
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    // Устанавливаем размер буфера для чтения
    const size_t bufferSize = 1024; // 1 КБ
    char buffer[bufferSize];

    // Читаем и выводим содержимое файла по фрагментам
    while (!file.eof()) {
        file.read(buffer, bufferSize - 1); // Оставляем место для '\0'
        buffer[file.gcount()] = '\0'; // Добавляем конец строки для std::cout

        // Выводим прочитанный фрагмент
        std::cout << buffer;
    }

    // Закрываем файл
    file.close();

    return 0;
}
