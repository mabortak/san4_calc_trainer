// calculate trainer

// add input exceptions

#include <iostream>
#include <ctime>

int operation(int& last_answer, int& b, const short& difficulty);
bool question(const short& difficulty, const short& level, const short& health, int& last_answer);

int main() {

	std::cout << "\nWelcome to san4calc" << "\n";

	unsigned short health = 5;
	unsigned short level = 0;
	unsigned short difficulty = 0;  // choose math_op. see int operation();
	int last_answer = 0;

	while (health) {
		srand(time(nullptr));

		if (level < 5) difficulty = 2;
		if (level >= 5 && level < 10) difficulty = 3;
		if (level >= 10) difficulty = 4;

		std::cout <<
			"\nYour health: " << health << "\n" <<
			"Your level: " << level << "\n" <<
			"Difficulty (1-4): " << difficulty << "\n\n";

		if (question(difficulty, level, health, last_answer)) level++;
		else health--;
	}
	std::cout << "\n\nOkey, nice. Your level: " << level << "\n\n";
	return EXIT_SUCCESS;
}

int operation(int& last_answer, int& b, const short& difficulty) {
	char math_op = "+-*%"[rand() % difficulty];
	std::cout << last_answer << " ";
	switch (math_op)
	{
	case '+':
		last_answer = last_answer + b;
		break;
	case '-':
		last_answer = last_answer - b;
		break;
	case '*':
		b = rand() % 10;
		last_answer = last_answer * b;
		break;
	case '%':
		b = rand() % 10;
		last_answer = last_answer % b;
		break;
	default:
		break;
	}
	std::cout << math_op << " " << b << " = ";
	return last_answer;
}

bool question(const short& difficulty, const short& level, const short& health, int& last_answer) {
	int b = 0;
	int answer = 0;
	int sum = 0;

	if (last_answer == 0)
		last_answer = rand() % 100;
	if (level < 5)
		b = rand() % 50;
	else b = rand() % 100;

	sum = operation(last_answer, b, difficulty);
	// exception input
	while (!(std::cin >> answer) || (std::cin.peek() != '\n')) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Error!" << "\n";
	}
	//
	if (sum != answer) {
		std::cout << "Nope! " << sum << "\n";
		last_answer = 0;
		return false;
	}
	if (sum == answer) {
		std::cout << "Yeap!\n";
		return true;
	}
}
