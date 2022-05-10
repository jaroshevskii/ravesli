# Глава №8. Итоговый тест

Эта глава на [Ravesli](https://ravesli.com/glava-8-itogovyj-test/).

## Задание №1

a) Напишите класс с именем Point. В классе Point должны быть две переменные-члены типа double: `m_a` и `m_b` со значениями по умолчанию `0.0`. Напишите конструктор для этого класса и функцию вывода print().

Следующая программа:

```c++
#include <iostream>
 
int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
 
    return 0;
}
```

Должна выдавать следующий результат:

```
Point(0, 0)
Point(2, 5)
```

b) Теперь добавим метод distanceTo(), который будет принимать второй объект класса Point в качестве параметра и будет вычислять расстояние между двумя объектами. Учитывая две точки (`a1`, `b1`) и (`a2`, `b2`), расстояние между ними можно вычислить следующим образом: `sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2))`. Функция sqrt() находится в заголовочном файле cmath.

Следующая программа:

```c++
int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
 
    return 0;
}
```

Должна выдавать следующий результат:

```
Point(0, 0)
Point(2, 5)
Distance between two points: 5.38516
```

c) Измените функцию distanceTo() из метода класса в дружественную функцию, которая будет принимать два объекта класса Point в качестве параметров. Переименуйте эту функцию на distanceFrom().

Следующая программа:

```c++
int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
 
    return 0;
}
```

Должна выдавать следующий результат:

```
Point(0, 0)
Point(2, 5)
Distance between two points: 5.38516
```

## Задание №2

Напишите деструктор для следующего класса:

```c++
#include <iostream>
 
class Welcome
{
private:
    char *m_data;

public:
    Welcome()
    {
        m_data = new char[14];
        const char *init = "Hello, World!";
        for (int i = 0; i < 14; ++i)
        m_data[i] = init[i];
    }
 
    ~Welcome()
    {
        // Реализация деструктора
    }

    void print() const
    {
        std::cout << m_data;
    }
 
};
 
int main()
{
    Welcome hello;
    hello.print();
 
    return 0;
}
```

## Задание №3

Давайте создадим генератор случайных монстров.

a) Сначала создайте перечисление MonsterType со следующими типами монстров: `Dragon`, `Goblin`, `Ogre`, `Orc`, `Skeleton`, `Troll`, `Vampire` и `Zombie` + добавьте `MAX_MONSTER_TYPES`, чтобы иметь возможность подсчитать общее количество всех перечислителей.

b) Теперь создайте класс Monster со следующими тремя атрибутами (переменными-членами): тип (MonsterType), имя (std::string) и количество здоровья (int).

c) Перечисление MonsterType является специфичным для Monster, поэтому переместите его внутрь класса под спецификатор доступа public.

d) Создайте конструктор, который позволит инициализировать все переменные-члены класса.

Следующий фрагмент кода должен скомпилироваться без ошибок:

```c++
int main()
{
    Monster jack(Monster::Orc, "Jack", 90);
 
    return 0;
}
```

e) Теперь нам нужно вывести информацию про нашего монстра. Для этого нужно конвертировать MonsterType в std::string. Добавьте функцию getTypeString(), которая будет выполнять конвертацию, и функцию вывода print().

Следующая программа:

```c++
int main()
{
    Monster jack(Monster::Orc, "Jack", 90);
    jack.print();
 
    return 0;
}
```

Должна выдавать следующий результат:

```
Jack is the orc that has 90 health points.
```

f) Теперь мы уже можем создать сам генератор монстров. Для этого создайте статический класс MonsterGenerator и статический метод с именем generateMonster(), который будет возвращать случайного монстра. Пока что возвратом метода пускай будет анонимный объект: `(Monster::Orc, "Jack", 90)`.

Следующая программа:

```c++
int main()
{
    Monster m = MonsterGenerator::generateMonster();
    m.print();
 
    return 0;
}
```

Должна выдавать следующий результат:

```
Jack is the orc that has 90 health points.
```

g) Теперь MonsterGenerator должен генерировать некоторые случайные атрибуты. Для этого нам понадобится генератор случайного числа. Воспользуйтесь следующей функцией:

```c++
// Генерируем случайное число между min и max (включительно).
// Предполагается, что srand() уже был вызван 
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
    // Равномерно распределяем вычисление значения из нашего диапазона
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
```

Поскольку MonsterGenerator будет полагаться непосредственно на эту функцию, то поместите её внутрь класса в качестве статического метода.

h) Теперь измените функцию generateMonster() для генерации случайного MonsterType (между `0` и `Monster::MAX_MONSTER_TYPES-1`) и случайного количества здоровья (от 1 до 100). Это должно быть просто. После того, как вы это сделаете, определите один статический фиксированный массив `s_names` размером 6 элементов внутри функции generateMonster() и инициализируйте его 6-ю любыми именами на ваш выбор. Добавьте возможность выбора случайного имени из этого массива.

Следующий фрагмент должен скомпилироваться без ошибок:

```c++
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
 
int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

    Monster m = MonsterGenerator::generateMonster();
    m.print();

    return 0;
}
```

i) Почему мы объявили массив s_names статическим?

## Задание №4

Настало время для нашего и вашего любимого задания «Blackjack». На этот раз мы перепишем игру «Blackjack», которую написали ранее в [итоговом тесте главы №6](https://ravesli.com/glava-6-itogovyj-test/), но уже с использованием классов! Вот полный код без классов:

```c++
#include <iostream>
#include <array>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
 
enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};
 
enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};
 
struct Card
{
    CardRank rank;
    CardSuit suit;
};
 
void printCard(const Card &card)
{
    switch (card.rank)
    {
        case RANK_2:		std::cout << '2'; break;
        case RANK_3:		std::cout << '3'; break;
        case RANK_4:		std::cout << '4'; break;
        case RANK_5:		std::cout << '5'; break;
        case RANK_6:		std::cout << '6'; break;
        case RANK_7:		std::cout << '7'; break;
        case RANK_8:		std::cout << '8'; break;
        case RANK_9:		std::cout << '9'; break;
        case RANK_10:		std::cout << 'T'; break;
        case RANK_JACK:		std::cout << 'J'; break;
        case RANK_QUEEN:	std::cout << 'Q'; break;
        case RANK_KING:		std::cout << 'K'; break;
        case RANK_ACE:		std::cout << 'A'; break;
    }

    switch (card.suit)
    {
        case SUIT_CLUB:		std::cout << 'C'; break;
        case SUIT_DIAMOND:	std::cout << 'D'; break;
        case SUIT_HEART:	std::cout << 'H'; break;
        case SUIT_SPADE:	std::cout << 'S'; break;
    }
}
 
void printDeck(const std::array<Card, 52> deck)
{
    for (const auto &card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
 
  std::cout << '\n';
}
 
void swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}
 
// Генерируем случайное число между min и max (включительно).
// Предполагается, что srand() уже был вызван
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
    // Равномерно распределяем вычисление значения из нашего диапазона
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
 
void shuffleDeck(std::array<Card, 52> &deck)
{
    // Перебираем каждую карту в колоде
    for (int index = 0; index < 52; ++index)
    {
        // Выбираем любую случайную карту
        int swapIndex = getRandomNumber(0, 51);
        // Меняем местами с нашей текущей картой
        swapCard(deck[index], deck[swapIndex]);
    }
}
 
int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case RANK_2:		return 2;
        case RANK_3:		return 3;
        case RANK_4:		return 4;
        case RANK_5:		return 5;
        case RANK_6:		return 6;
        case RANK_7:		return 7;
        case RANK_8:		return 8;
        case RANK_9:		return 9;
        case RANK_10:		return 10;
        case RANK_JACK:		return 10;
        case RANK_QUEEN:	return 10;
        case RANK_KING:		return 10;
        case RANK_ACE:		return 11;
    }
  
    return 0;
}
 
char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');
  
    return choice;
}
 
bool playBlackjack(const std::array<Card, 52> deck)
{
    const Card *cardPtr = &deck[0];
 
    int playerTotal = 0;
    int dealerTotal = 0;
 
    // Дилер получает одну карту
    dealerTotal += getCardValue(*cardPtr++);
    std::cout << "The dealer is showing: " << dealerTotal << '\n';
 
    // Игрок получает две карты
    playerTotal += getCardValue(*cardPtr++);
    playerTotal += getCardValue(*cardPtr++);
 
    // Игрок начинает
    while (1)
    {
      std::cout << "You have: " << playerTotal << '\n';
      char choice = getPlayerChoice();
      if (choice == 's')
        break;
 
      playerTotal += getCardValue(*cardPtr++);
    
      // Смотрим, не проиграл ли игрок
      if (playerTotal > 21)
        return false;
    }

    // Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
    while (dealerTotal < 17)
    {
      dealerTotal += getCardValue(*cardPtr++);
      std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // Если у дилера больше 21, то он проиграл, а игрок выиграл
    if (dealerTotal > 21)
      return true;

    return (playerTotal > dealerTotal);
}
 
int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
 
    std::array<Card, 52> deck;
  
    // Конечно, можно было бы инициализировать каждую карту отдельно, но зачем? Ведь есть циклы!
    int card = 0;
    for (int suit = 0; suit < MAX_SUITS; ++suit)
    for (int rank = 0; rank < MAX_RANKS; ++rank)
    {
        deck[card].suit = static_cast<CardSuit>(suit);
        deck[card].rank = static_cast<CardRank>(rank);
        ++card;
    }

    shuffleDeck(deck);

    if (playBlackjack(deck))
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";

    return 0;
}
```

Нехило, правда? С чего же начинать? Для начала нам нужна стратегия. Программа «Blackjack» состоит из 4 частей:

- Логика работы с картами.
- Логика работы с колодами карт.
- Логика раздачи карт из колоды.
- Логика игры.

Наша стратегия заключается в том, чтобы работать над каждой из этих частей индивидуально. Таким образом, вместо конвертации целой программы за один присест, мы сделаем это спокойно за 4 шага.

Скопируйте вышеприведенный код в вашу IDE, а затем закомментируйте всё, кроме строк, содержащих #include.

a) Начнем с того, что переделаем Card из структуры в класс. Хорошей новостью является то, что класс Card очень похож на класс Monster из предыдущего задания. Алгоритм действий следующий:

- Во-первых, переместите перечисления CardSuit и CardRank внутрь класса Card под спецификатор доступа public (они неотъемлемо связаны с Card, поэтому должны находиться внутри класса).
- Во-вторых, создайте закрытые переменные-члены `m_rank` и `m_suit` для хранения значений CardRank и CardSuit.
- В-третьих, создайте открытый конструктор класса Card с инициализацией карт (переменных-членов класса). Укажите параметры по умолчанию для конструктора (используйте MAX_RANKS и MAX_SUITS).
- Наконец, переместите функции printCard() и getCardValue() внутрь класса под спецификатор доступа public (не забудьте сделать их const!).

> ***Примечание:*** При использовании std::array (или std::vector), где элементами являются объекты класса, класс должен иметь конструктор по умолчанию, чтобы элементы могли быть инициализированы разумными значениями по умолчанию. Если вы этого не сделаете, то получите ошибку попытки ссылаться на удаленную функцию.

Следующий фрагмент кода должен скомпилироваться без ошибок:

```c++
#include <iostream>
 
int main()
{
    const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEART);
    cardQueenHearts.printCard();
    std::cout << " has the value " << cardQueenHearts.getCardValue() << '\n';
 
    return 0;
}
```

b) Хорошо, теперь давайте работать над классом Deck:

- Во-первых, в Deck должно быть 52 карты, поэтому создайте private-член `m_deck`, который будет фиксированным массивом с 52-мя элементами (используйте std::array).
- Во-вторых, создайте конструктор, который не принимает никаких параметров и инициализирует каждый элемент массива `m_deck` случайной картой (используйте код из функции main() с циклами for из вышеприведенного примера, где присутствует полный код). Внутри циклов создайте анонимный объект Card и присваивайте его каждому элементу массива `m_deck`.
- В-третьих, переместите функцию printDeck() в класс Deck под спецификатор доступа public (не забудьте о const).
- В-четвертых, переместите функции getRandomNumber() и swapCard() в класс Deck в качестве закрытых статических членов.
- В-пятых, переместите функцию shuffleDeck() в класс в качестве открытого члена.

> ***Подсказка:*** Самой сложной частью здесь является инициализация колоды карт с использованием модифицированного кода из исходной функции main(). В следующей строке показывается, как это сделать:

```c++
    m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
```

Следующий фрагмент должен cкомпилироваться без ошибок:

```c++
#include <iostream>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
 
int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
 
    Deck deck;
    deck.printDeck();
    deck.shuffleDeck();
    deck.printDeck();
 
    return 0;
}
```

c) Теперь нам нужен способ отследить то, какая карта будет раздаваться следующей (в исходной программе для этого используется `cardptr`):

- Во-первых, добавьте в класс Deck целочисленный член `m_cardIndex` и инициализируйте его значение `0`.
- Во-вторых, создайте открытый метод dealCard(), который будет возвращать константную ссылку на текущую карту и увеличивать `m_cardIndex`.
- В-третьих, метод shuffleDeck() также должен быть обновлен для сброса `m_cardIndex` (так как после перетасовки колоды, раздается карта, которая является верхней).

Следующий фрагмент должен скомпилироваться без ошибок:

```c++
int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

    Deck deck;
    deck.shuffleDeck();
    deck.printDeck();
    std::cout << "The first card has value: " << deck.dealCard().getCardValue() << '\n';
    std::cout << "The second card has value: " << deck.dealCard().getCardValue() << '\n';
 
    return 0;
}
```

d) Почти готово! Теперь немного самостоятельности:

- Добавьте в программу функции getPlayerChoice() и playBlackjack().
- Измените функцию playBlackjack() в соответствие с уже имеющимся классом и методами.
- Удалите лишнее и добавьте нужное в функцию main() (см. полный код выше).

Ура!