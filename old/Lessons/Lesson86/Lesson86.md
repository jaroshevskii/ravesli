# Lesson 86

## Task
Напишите программу, которая:
- спрашивает у пользователя, сколько имен он хочет ввести;
- просит пользователя ввести каждое имя;
- вызывает функцию для сортировки имен в алфавитном порядке (измените код сортировки методом выбора из урока №77);
- выводит отсортированный список имен.

### ***Подсказки:***
- Используйте динамическое выделение std::string для хранения имен.
- std::string поддерживает сравнение строк с помощью операторов сравнения < и >.

Пример результата выполнения вашей программы:
```
How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Alex
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Alex
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark
```