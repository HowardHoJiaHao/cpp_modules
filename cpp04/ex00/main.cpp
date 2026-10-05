
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << meta ->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    delete meta;
    delete i;
    delete j; 

    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();
    std::cout << meta2 ->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    meta2->makeSound();
    i2->makeSound();

    delete meta2;
    delete i2; 

    return 0;
}

// int main (void)
// {
// 	std::cout << " ------test the polymorphism with class ------" << std::endl;

// 	// a is animal and object points to a dog
// 	Animal* a = new Dog();
// 	a -> makeSound(); //this is runtime polymorphism

// 	std::cout << " === dog series === " << std::endl;

// 	Animal* b = new Dog("super dog"); //only this line counts as polymorphism
// 	b -> makeSound();

// 	Dog* c1 = new Dog("mutant dog"); 
// 	Animal* c2 = new Dog(*c1); // Dog(*c1) is copy constructor
// 	c2 -> makeSound();

// 	//Dog* d1 = new Dog("robot dog"); this one cannot count as polymorphism
// 	std::cout << " \n=== test robot dog === " << std::endl;
// 	Animal* d1 = new Dog("robot dog");
// 	Animal* d2 = new Dog();
// 	*d2 = *d1; // this is an assignment operator
// 	d2 -> makeSound();

// 	std::cout << " --- cleanup the dog ---" << std::endl;
// 	delete a;
// 	delete b;
// 	delete c2;
// 	delete c1;
// 	delete d1;
// 	delete d2;


// 	std::cout << "\n === cat series === " << std::endl;
// 	Animal* e = new Cat();
// 	e -> makeSound();

// 	Animal* f = new Cat("super cat"); 
// 	f -> makeSound();

// 	Cat* g1 = new Cat("mutant cat"); 
// 	Animal* g2 = new Cat(*g1);
// 	g2 -> makeSound();

// 	std::cout << " \n=== test robot cat === " << std::endl;
// 	Animal* h1 = new Cat("robot cat");
// 	Animal* h2 = new Cat();
// 	*h2 = *h1;
// 	h2 -> makeSound();

// 	std::cout << " --- cleanup the cat ---" << std::endl;
// 	delete e;
// 	delete f;
// 	delete g2;
// 	delete g1;
// 	delete h1;
// 	delete h2;

// 	std::cout << " ------ subject pdf ------" << std::endl;
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << std::endl;
// 	std::cout << i->getType() << std::endl;

// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// 	std::cout << " ------test the polymorphism with wongg animal dog and cat class ------" << std::endl;

// 	WrongAnimal* wa = new WrongAnimal();
// 	std::cout << wa->getType() << std::endl;
// 	wa->makeSound();

// 	WrongAnimal* wc = new WrongCat();
// 	std::cout << "\nthe type of cat is " <<std::endl;
// 	std::cout << wc->getType() << std::endl;
// 	wc->makeSound();
// 	delete wa;
// 	delete wc;

// 	return 0;
// }