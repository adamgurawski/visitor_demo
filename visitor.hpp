#pragma once

#include <iostream>

class Animal;
class Rabbit;
class Lizard;

class IVisitor
{
public:
  virtual ~IVisitor() = default;

  virtual void Visit(Animal* animal) = 0;
  virtual void Visit(Rabbit* rabbit) = 0;
  virtual void Visit(Lizard* lizard) = 0;

protected:
  IVisitor() = default;
};

class PrintAnimalTypeVisitor : public IVisitor
{
public:
  PrintAnimalTypeVisitor() = default;

  virtual void Visit(Animal* animal) override { Println("animal"); }
  virtual void Visit(Rabbit* rabbit) override { Println("rabbit"); }
  virtual void Visit(Lizard* lizard) override { Println("lizard"); }

private:
  void Println(const char* animalType) const { std::cout << animalType << std::endl; }
};
