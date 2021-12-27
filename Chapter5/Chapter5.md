# Chapter 5

## Task 1
В итоговом тесте главы №2 мы написали программу имитации мячика, падающего с башни. Так как тогда мы еще ничего не знали о циклах и не умели их использовать, то время полета мячика составляло всего лишь 5 секунд.

Измените программу, приведенную ниже, таким образом, чтобы мячик падал ровно то количество секунд, которое необходимо ему для достижения земли.

constants.h:
```c++
#ifndef CONSTANTS_H
#define CONSTANTS_H
 
namespace myConstants
{
    const double gravity(9.8); 
}
#endif
```

Основной файл:
```c++
#include <iostream>
#include "constants.h"
 
// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}
 
// Возвращаем расстояние от земли после "..." секунд падения
double calculateHeight(double initialHeight, int seconds)
{
	// Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;
 
	return currentHeight;
}
 
// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(double height, int seconds)
{
	if (height > 0.0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}
 
void calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
}
 
int main()
{
	const double initialHeight = getInitialHeight();
 
	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);
 
	return 0;
}
```

## Task 2
Напишите программу-игру типа Hi-Lo:
- Во-первых, ваша программа должна выбрать случайное целое число в диапазоне от 1 до 100.
- Пользователю дается 7 попыток, чтобы угадать это число.
- Если пользователь не угадал число, то программа должна подсказывать, была ли его догадка слишком большой или слишком маленькой.
- Если пользователь угадал число, то программа должна сообщить, что всё верно - вы выиграли.
- Если же у пользователя кончились попытки, и он не угадал число, то программа должна сообщить ему, что он проиграл и показать правильный результат.
- В конце игры программа должна спросить у пользователя, не хочет ли он сыграть еще раз. Если пользователь не введет ни y, ни n (а что-то другое), то программа должна спросить его еще раз.

Пример результата выполнения вашей программы:
```
Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Correct! You win!
Would you like to play again (y/n)? y
Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Your guess is too high.
Guess #5: 36
Your guess is too low.
Guess #6: 45
Your guess is too low.
Guess #7: 48
Your guess is too low.
Sorry, you lose. The correct number was 49.
Would you like to play again (y/n)? q
Would you like to play again (y/n)? f
Would you like to play again (y/n)? n
Thank you for playing.
```

### ***Подсказки:***
- Используйте в качестве стартового числа во время генерации случайных чисел вызов функции time(0).
- ***Пользователям Visual Studio:*** Из-за плохой реализации функции rand() (первое рандомное число не сильно отличается от стартового) — вызовите rand() сразу после установки стартового числа, чтобы сбросить первый результат.
- Используйте функцию getRandomNumber() из урока №71 для генерации случайного числа.
- В функции, которая будет спрашивать у пользователя, не хочет ли он сыграть еще раз, используйте механизм обработки некорректного пользовательского ввода.
