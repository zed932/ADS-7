// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
  Car* new_car = new Car{light, nullptr, nullptr};
  if (first == nullptr) {
    new_car->next = new_car;
    new_car->prev = new_car;
    first = new_car;
  } else {
    Car* last = first->prev;
    new_car->next = first;
    new_car->prev = last;
    last->next = new_car;
    first->prev = new_car;
  }
}

int Train::getLength() {
  countOp = 0;
  if (first == nullptr) return 0;

  Car* current = first;
  current->light = true;

  while (true) {
    int steps = 0;
    do {
      current = current->next;
      steps++;
      countOp++;
    } while (!current->light);

    current->light = false;
    for (int i = 0; i < steps; i++) {
      current = current->prev;
      countOp++;
    }

    if (!current->light) {
      return steps;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
