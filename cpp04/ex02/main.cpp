#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <sstream>

int main (void)
{
	Animal *i = new Cat("funny cat");
	Animal *j = new Dog("funnydog");

	i->makeSound();
	j->makeSound();
	
	delete i;
	delete j;
	
	// const int count = 10;
	// Animal* animals[count];

	// for (int i = 0; i < count / 2; i ++)
	// 	animals[i] = new Dog();
	// for (int i = count / 2; i < count; i++)
	// 	animals[i] = new Cat();

	// for (int i = 0; i < count; i++)
	// 	animals[i]->makeSound();
	// for (int i = 0; i < count; i++)
	// 	delete animals[i];

	// std::cout << "===== above to test the he polymorphism and destruction =====" << std::endl;
	// std::cout << "===== below is to test the ===== deep copy" << std::endl;

	// //Animal * a = new Dog ("golden");
	// // only dog can access the brain, animal cannot
	// Dog a;
	// a.getBrain()->setIdea(0, "stick");
	// a.getBrain()->setIdea(1, "kick");
	// std::cout << a.getBrain()->getIdea(0) << std::endl;
	// std::cout << a.getBrain()->getIdea(1) << std::endl;

    // Dog b = a;

	// b.getBrain()->setIdea(0, "funny");
	// b.getBrain()->setIdea(1, "kick");
	// std::cout << b.getBrain()->getIdea(0) << std::endl;
	// std::cout << b.getBrain()->getIdea(1) << std::endl;


	// std::cout << a.getBrain()->getIdea(0) << std::endl;
	// std::cout << a.getBrain()->getIdea(1) << std::endl;

	return 0;
}
