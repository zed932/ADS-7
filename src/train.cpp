#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
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
  if (!first) return 0;

  first->light = true;
  countOp++;
  Car* current = first->next;
  countOp++;
  int candidate = 1;

  while (true) {
    if (current->light) {
      current->light = false;
      countOp++;
      int stepsBack = 0;
      Car* temp = current->prev;
      countOp++;
      while (temp != current) {
        temp = temp->prev;
        countOp++;
        stepsBack++;
      }
      if (!first->light) {
        return stepsBack + 1;
      } else {
        candidate++;
        current = first->next;
        countOp++;
      }
    } else {
      current = current->next;
      countOp++;
      candidate++;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
