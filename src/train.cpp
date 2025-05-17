#include "train.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* newCar = new Car{ light, nullptr, nullptr };

  if (first == nullptr) {
    newCar->next = newCar;
    newCar->prev = newCar;
    first = newCar;
  } else {
    Car* tail = first->prev;
    newCar->next = first;
    newCar->prev = tail;
    tail->next = newCar;
    first->prev = newCar;
  }
}

int Train::getLength() {
  countOp = 0;
  if (first == nullptr) return 0;

  first->light = true;
  countOp++;

  int length = 1;
  Car* current = first->next;
  countOp++;

  while (current != first) {
    if (current->light) {
      current->light = false;
      int steps = 0;
      Car* temp = current->prev;
      countOp++;
      while (temp != current) {
        temp = temp->prev;
        countOp++;
        steps++;
      }
      return steps + 1;
    }
    length++;
    current = current->next;
    countOp++;
  }

  return length;
}

int Train::getOpCount() {
  return countOp;
}
