#pragma once

#include "visitor.hpp"

class Animal
{
public:
  virtual void Accept(IVisitor* visitor) = 0;

protected:
  Animal() = default;
}; // class Animal

class Rabbit : public Animal
{
public:
  virtual void Accept(IVisitor* visitor) override { visitor->Visit(this); }
}; // class Rabbit

class Lizard : public Animal
{
public:
  virtual void Accept(IVisitor* visitor) override { visitor->Visit(this); }
}; // class Lizard
