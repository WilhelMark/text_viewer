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
    while (true) {
        file.read(buffer, bufferSize);
        size_t bytesRead = file.gcount(); // Количество прочитанных байт

        // Если файл закончился, выходим из цикла
        if (bytesRead == 0) {
            break;
        }

        // Выводим прочитанный фрагмент
        for (size_t i = 0; i < bytesRead; ++i) {
            std::cout << buffer[i];
        }
    }

    // Закрываем файл
    file.close();

    return 0;
}
