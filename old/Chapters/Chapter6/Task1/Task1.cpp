#include <iostream>

enum class ItemTypes { ARROW, TORCH, HEALTH_POTIONS, NUMBER_OF_INTEM_TYPES };

constexpr size_t getNumberOfItems() {
  return static_cast<size_t>(ItemTypes::NUMBER_OF_INTEM_TYPES);
}

int getTotalNumberOfItems(const int (&items)[getNumberOfItems()]) {
  int totalNumberOfItems = 0;

  for (const auto &numberOfItems : items)
    totalNumberOfItems += numberOfItems;
  return totalNumberOfItems;
}

int main() {
  const int items[getNumberOfItems()]{12, 6, 3};

  std::cout << "Total number of items: " << getTotalNumberOfItems(items) << "\n"
            << '\n';
  return 0;
}