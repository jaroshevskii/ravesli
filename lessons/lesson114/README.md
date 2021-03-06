# Урок №114. Спецыфикаторы доступа public и private

Этот урок на [Ravesli](https://ravesli.com/urok-114-spetsifikatory-dostupa-public-i-private/).

## Задание №1

a) Что такое откритый член?

b) Что такое закритий член?

c) Что такое спецыфикатор доступа?

d) Сколько есть спецыфикаторов доступа в языке C++? Назовите их.

## Задание №2

a) Напишите простой клсасс с именем Numbers. Этот класс должен иметь:

- три закритие переменные-члены типа double: `m_a`, `m_b`, `m_c`;
- открытый метод с именем setValues(), который позволит устанавливать значение для `m_a`, `m_b`, `m_c`;
- открытый метод с именем print(), который будет выводить объект класса Numbers в следующем формате: `<m_a, m_b, m_c>`.

Следующий код функции main():

```c++
int main()
{
    Numbers point;
    point.setValues(3.0, 4.0, 5.0);

    point.print();

    return 0;
}
```

Должен выдавать следующий результат:

```
<3, 4, 5>
```

b) Добавьте функцию isEqual() в класс Numbers, чтобы следующий код работал корректно:

```c++
int main()
{
    Numbers point1;
    point1.setValues(3.0, 4.0, 5.0);

    Numbers point2;
    point2.setValues(3.0, 4.0, 5.0);

    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are same\n";
    else
        std::cout << "point1 and point2 are different\n";

    Numbers point3;
    point3.setValues(7.0, 8.0, 9.0);

    if (point1.isEqual(point3))
      std::cout << "point1 and point2 are same\n";
    else
      std::cout << "point1 and point2 are different\n";
}
```

## Задание №3

Теперь попробуем что-то посложнее.
Напишите класс, который реалызует функционал [стека](https://ravesli.com/urok-105-stek-i-kucha/). Класс Stack должен иметь:

- закрытый целочисленый [фиксированый массив](https://ravesli.com/urok-74-massivy-chast-1/) длиной 10 элементов;
- закрытое целочисленое значение для отслеживания длины стека;
- открытый метод с именем reset(), который будет инициализировать значением `0` длину всех елементов;
- открытый метод с именем push(), который будет добавлять значение в стек. Метод push() должен возвращать значение `false`, если массив уже заполнен, в противном случае - `true`;
- открытый метод с именем pop() для возврата значений из стека. Если в стеке нет значений, то должен выводится [сейтмент assert](https://ravesli.com/urok-109-assert-i-static_assert/);
- открытый метод с именем print(), который будет выводить все значение стека.

Следующий код функции main():

```c++
int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    
    stack.print();

    return 0;
}
```

Должен выдавать следующий результат:

```
( )
( 3 7 5 )
( 3 7 )
( )
```