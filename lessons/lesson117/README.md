# Урок №117. Список инициализации членов класса

Этот урок на [Ravesli](https://ravesli.com/urok-117-spisok-initsializatsii-chlenov-klassa/#toc-0).

## Задание

Напишите класс с именем RGBA, который содержит 4 переменные-члены типа [std::uint8_t](https://ravesli.com/urok-32-fiksirovannyj-razmer-integers-spor-naschet-unsigned/) (подключите заголовочный файл cstdint для доступа к типу std::uint8_t):

- `m_red`;
- `m_green`;
- `m_blue`;
- `m_alpha`.

Присвойте `0` в качестве значения по умолчанию для `m_red`, `m_green` и `m_blue`, и `255` для `m_alpha`. Создайте конструктор со списком инициализации членов, который позволит пользователю передавать значения для `m_red`, `m_green`, `m_blue` и `m_alpha`. Напишите функцию print(), которая будет выводить значения переменных-членов.

> ***Подсказка:*** Если функция print() работает некорректно, то убедитесь, что вы [конвертировали](https://ravesli.com/urok-56-yavnoe-preobrazovanie-tipov-dannyh-operatory-casts/) std::uint8_t в int.

Следующий код функции main():

```c++
int main()
{
	RGBA color(0, 135, 135);
	color.print();
 
	return 0;
}
```

Должен выдавать следующий результат:

```
r=0 g=135 b=135 a=255
```