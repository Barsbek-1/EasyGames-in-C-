//Word Jumble 
//Классическая игра-головоломка , в которой пользователь разгадывают слова , с подсказками или без них. 

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5; 
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
		{"wall", " Do you feel you're benging your head against something?"},
		{"glassed", " These might help you see the answer."},
		{"labored", " Going slowly , is it?"},
		{"persistent", " Keep at it."},
		{"jumble", " It's what the game is all about."}
	}; 

	srand (static_cast<unsigned int> (time(0)));
	int choice = (rand() % NUM_WORDS); 
	string theWord = WORDS[choice][WORD]; // слово , которое нужно угадать 
	string theHint = WORDS[choice][HINT]; // подсказка для слова 

	string jumble = theWord; // перемешанный вариант слова 
	int length = jumble.size(); 
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length); 
		int index2 = (rand() % length); 
		char temp = jumble [index1]; 
		jumble [index1] = jumble [index2];
		jumble [index2] = temp; 
	}

	cout << "\t\t\t Welcome to Word Jumble!!!\n\n"; 
	cout << " Unscramble the letters to make a word.\n";
	cout << " Enter 'hint' for a hint.\n"; 
	cout << " Enter 'quit' to quit the game.\n\n";
	cout << " The Jumble is: " << jumble; 
	string guess; 
	cout << "\n\n Your guess: "; 
	cin >> guess; 

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint; 
		}
		else 
		{
			cout << " Sorry, tha's not it."; 
		}
		cout << "\n\n Your guess: "; 
		cin >> guess; 
	}
	if (guess == theWord)
	{
		cout << "\n That's it! You guessed it! \n"; 
	}
	cout << "\n Thanks for playing. \n"; 
	return 0; 
}
