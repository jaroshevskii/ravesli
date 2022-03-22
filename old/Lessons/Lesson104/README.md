# Урок №104. Указатели на функции

Страница на [Ravesli](https://ravesli.com/urok-104-ukazateli-na-funktsii/).

На [уроке №80](https://ravesli.com/urok-80-ukazateli-vvedenie/) мы узнали, что указатель — это переменная, которая содержит адрес другой переменной. Указатели на функции аналогичны, за исключением того, что вместо обычных переменных, они указывают на функции!

**Оглавление:**

1. [Тест](#тест)

### Тест

#### Задание №1

**В этот раз мы попытаемся написать версию базового калькулятора с помощью указателей на функции.**

a) Напишите короткую программу, которая просит пользователя ввести два целых числа и выбрать математическую операцию: `+`, `-`, `*` или `/`. Убедитесь, что пользователь ввел корректный символ математической операции (используйте проверку).

b) Напишите функции add(), subtract(), multiply() и divide(). Они должны принимать два целочисленных параметра и возвращать целочисленное значение.

c) Создайте typedef с именем `arithmeticFcn` для указателя на функцию, которая принимает два целочисленных параметра и возвращает целочисленное значение.

d) Напишите функцию с именем getArithmeticFcn(), которая принимает символ выбранного математического оператора и возвращает соответствующую функцию в качестве указателя на функцию.

e) Добавьте в функцию main() вызов функции getArithmeticFcn().

f) Соедините все части вместе.

#### Задание №2

**Теперь давайте изменим программу, которую мы написали в 1-м задании, чтобы переместить логику из getArithmeticFcn в массив.**

a) Создайте структуру с именем `arithmeticStruct`, которая имеет два члена: математический оператор типа char и указатель на функцию `arithmeticFcn`.

Ответ 2.a)

b) Создайте статический глобальный массив `arithmeticArray`, используя структуру `arithmeticStruct`, который будет инициализирован каждой из 4 математических операций.

Ответ 2.b)

c) Измените `getArithmeticFcn` для выполнения цикла по массиву и возврата соответствующего указателя на функцию.

> ***Подсказка:*** Используйте цикл [foreach](https://ravesli.com/urok-91-tsikl-foreach/).

Ответ 2.c)

d) Соедините все части вместе.