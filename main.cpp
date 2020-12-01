
#include "animals.hpp"
#include "visitor.hpp"

#include <memory>

void PrintAnimalType(Animal*) { std::cout << "animal" << std::endl; }
void PrintAnimalType(Rabbit*) { std::cout << "rabbit" << std::endl; }
void PrintAnimalType(Lizard*) { std::cout << "lizard" << std::endl; }

int main()
{
  std::unique_ptr<Animal> rabbit = std::make_unique<Rabbit>();
  std::unique_ptr<Animal> lizard = std::make_unique<Lizard>();

  /*
   * The problem that visitor happens to solve is the lack of multiple dispatch in C++.
   * The calls below result in printing "animal" because the function to be called is
   * decided basing on static types of arguments (Animal*) and not the dynamic (runtime) ones
   * (Rabbit or Lizard in this case).
   */
  PrintAnimalType(rabbit.get()); // prints "animal"
  PrintAnimalType(lizard.get()); // prints "animal"

  std::unique_ptr<IVisitor> visitor = std::make_unique<PrintAnimalTypeVisitor>();

  /*
   * The visitor allows us to perform different functions basing on argument's dynamic type.
   * In the calls below, for example, Rabbit::Accept is called, which contains visitor->Visit(this).
   * The 'this' passed to visitor's Visit points to Rabbit object, so the visitor knows that the
   * passed parameter was of class Rabbit, not Animal.
   */
  rabbit->Accept(visitor.get()); // prints "rabbit"
  lizard->Accept(visitor.get()); // prints "lizard"
}
