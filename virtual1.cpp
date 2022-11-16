#include <iostream>
using namespace std;

class Mammal {
public:
	Mammal() : mage(1) { cout << "mammal constructor!\n"; }
	~Mammal() { cout << "mammal destructor!\n"; }
	void Move() { cout << "test move base\n"; }
	virtual void Speak();

private:
	int mage;

};

void Mammal::Speak() {
	cout << "I am speak base class\n";
}

class Dog : public Mammal {
public:
	Dog() { cout << "constructor for dog\n"; }
	~Dog() { cout << "destructor for dog\n"; }
	void Move() { cout << "move function for dog\n"; }
	void Speak() { cout << "woof for dog -- \n"; }

private:

};
class Cat : public Mammal {
public:
	Cat() { cout << "constructor for cat\n"; }
	~Cat() { cout << "destructor for cat\n"; }
	void Move() { cout << "move function for cat\n"; }
	void Speak() { cout << "meow for cat === \n"; }
};

int main() {

	Mammal* thedog = new Dog();
	thedog->Move();
	thedog->Speak();
	Mammal* thecat = new Cat();
	thecat->Move();
	thecat->Speak();


}
