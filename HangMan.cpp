// HangMan
// Классическая игра " Виселица" 

// HangMan
// Классическая игра "Виселица"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
    // Подготовка
    const int MAX_WRONG = 8;  // Максимально допустимое количество ошибок
    vector<string> words;     // Подборка слов для загадывания
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    // Создаем генератор случайных чисел
    random_device rd;
    default_random_engine g(rd());

    // Перемешиваем слова
    shuffle(words.begin(), words.end(), g);

    const string THE_WORD = words[0]; // Слово для отгадывания
    int wrong = 0;                   // Количество ошибочных вариантов
    string soFar(THE_WORD.size(), '_'); // Часть слова, открытая на данный момент
    string used = "";                // Уже отгаданные буквы

    cout << "Welcome to HangMan. Good luck!!!\n";

    // Основной цикл
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);  // Перевод в верхний регистр, так как загаданное слово записано в верхнем регистре

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right!!! " << guess << " is in the word.\n";
            // Обновить переменную soFar, включив в нее новую угаданную букву
            for (size_t i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    // Конец игры
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!!!";
    }
    else
    {
        cout << "\nYou guessed it!!!";
    }
    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}

