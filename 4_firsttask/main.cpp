#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
using namespace std;
/** @file
 * @author Водолазов Д.С.
 * @version 1.3.3.7
 * @date 27.01.2024
 * @copyright ИБСТ ПГУ
 * @warning Это 4 лаба
 * @brief Заголовочный файл для модуля Gronsfeld
 */


/** @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка.
 */

class modAlphaCipher
{
private:
	wstring numAlpha = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";
	map <char, int> alphaNum;
	vector <int> key;
	vector <int> convert(const string& s);
	string convert(const vector<int>& v);
	/** @brief Валидация ключа.
	 * @param s Ключ. Должен содержать только строчные и прописные буквы кириллицы. Если необходимо, буквы переводятся в верхний регистр.
	 * @return Ключ, прошедший валидацию.
	 * @throw cipher_error: пустая строка, некорректные символы в строке.
	 */
	string getValidKey(const string& s);
	/** @brief Валидация текста.
	 * @param s Текст на русском языке. Не должен быть пустым. Символы пунктуации, цифры и пробелы приводят к возбуждению исключений. Если необходимо, буквы переводятся в верхний регистр.
	 * @return Текст, прошедший валидацию.
	 * @throw cipher_error: пустая строка, некорректные символы.
	 */
	string getValidOpenText(const string& s);
	/** @brief Валидация зашифрованного текста.
	 * @param s Зашифрованный текст на русском языке. Не должен быть пустым. Буквы нижнего регистра, символы пунктуации, цифры и пробелы приводят к возбуждению исключений.
	 * @return Зашифрованный текст, прошедший валидацию.
	 * @throw cipher_error: пустая строка, некорректные символы.
	 */
	string getValidCipherText(const string& s);
public:
	/** @brief Запрет конструктора без параметров.
	*/
	modAlphaCipher() = delete;
	/** @brief Конструктор для установки ключа.
	 * @param skey Строка для установки ключа. Должен содержать только строчные и прописные буквы кириллицы.
	 */
	modAlphaCipher(const string& skey);
	/** @brief Зашифрование.
	 * @param open_text Текст на русском языке.
	 * @warning Текст не должен быть пустой строкой, не должен содержать пробелы, символы пунктуации и цифры.
	 * @return Зашифрованный текст
	 */
	string encrypt(const string& open_text);
	/** @brief Расшифрование.
	 * @param cipher_text Зашифрованный текст на русском языке.
	 * @warning Зашифрованный текст не должен быть пустой строкой, не должен содержать пробелы, символы пунктуации, цифры и буквы нижнего регистра.
	 * @return Расшифрованный текст
	 */
	string decrypt(const string& cipher_text);
};

class cipher_error : public invalid_argument
{
public:
	explicit cipher_error(const string& what_arg) :
		invalid_argument(what_arg) {}
	explicit cipher_error(const char* what_arg) :
		invalid_argument(what_arg) {}
};