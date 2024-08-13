// Игра MadLib
// Формирует краткую историю на основе пользовательского ввода

#include <iostream> 
#include <string> 

using namespace std; 

string askText (string prompt)
{
	string text; 
	cout << prompt; 
	cin >> text; 
	return text; 
}
int askNumber (string prompt)
{
	int num; 
	cout << prompt; 
	cin >> num; 
	return num; 
}

void tellStory (string name, string noun, int number, string bodyPart, string verb)
{
	cout << "\n Here's your story:\n "; 
	cout << " The famous explorer "; 
	cout << name; 
	cout << " had nearly given up a life-long quest to find \n"; 
	cout << " The Lost City of "; 
	cout << noun; 
	cout << " when one day , the "; 
	cout << noun; 
	cout << " found the explorer. \n"; 
	cout << " Surrounded by "; 
	cout <<  number; 
	cout << " " << noun; 
	cout << ", a tear came to "; 
	cout << name << "'s "; 
	cout << bodyPart << " . \n "; 
	cout << " After all this time, the quest was finally over. ";
	cout << " And then , the "; 
	cout << noun << "\n"; 
	cout << " promptly devoured "; 
	cout << name << ". "; 
	cout << " The moral of the story? Be carefyl what you "; 
	cout << verb; 
	cout << " for. "; 
}
int main ()
{
	cout << " Welcome to Mad Lib. \n\n";
	cout << " Answer the following questions to help create a new story. \n"; 
	string name = askText(" Please enter a name: "); 
	string noun = askText(" Pleease enter a plural nou: "); 
	int number = askNumber(" Please enter a number: "); 
	string bodyPart = askText(" Please enter a body part: "); 
	string verb = askText(" Please enter a verb: "); 
	tellStory(name, noun, number, bodyPart, verb); 
	return 0; 
}
