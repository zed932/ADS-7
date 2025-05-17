// Copyright 2022 NNTU-CS
#include "train.h"
#include <cstdint>

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

  while (true) {
    Car* cursor = first;
    uint16_t lengthEstimate = 1;

    if (!cursor->light) {
      cursor->light = true;
      countOp++;
    }

    cursor = cursor->next;
    countOp++;

    while (!cursor->light) {
      cursor = cursor->next;
      countOp++;
      lengthEstimate++;
    }

    cursor->light = false;
    countOp++;

    if (!first->light) {
      return lengthEstimate;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
