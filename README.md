# Task description:

Трамваи города Решётково

Задание: 

написать программу на С или С++, которая решает ниже описанную задачу.
Город Решётково представлен матрицей m x n, где ряды пронумерованы от 1 до n, а колонки - от 1 до m.
Трамвайные пути в Решётково всегда идут прямо вдоль ряда. Другими словами, начальная и конечная точка трамвайного пути будут (r, c1) и (r, c2), где r представляет номер ряда, c1 - начальная колонка, c2 - конечная колонка.
Мер города хочет узнать количество клеток, где можно поставить уличные фонари. Фонарь может быть размещён только в клетке, не занятой трамвайными рельсами.

Для заданной карты Решётково и его k трамвайных путей найти и вывести количество клеток, где мер может разместить уличные фонари.
Внимание: Трамвайные пути могут пересекаться друг с другом в рамках одного ряда.

Входной формат:
Первая линия содержит 3 целых числа, разделённых пробелами: n (количество рядов), m (количество колонок), k (количество трамвайных путей).
Каждая следующая линия i из общего количества k содержит 3 целых числа, разделённых пробелами: r, c1, c2.

Ограничения:
1 <= n,m <= 10^9
0 <= k <= 1000
1 <= r <= n
1 <= c1,c2 <= m
Выходной формат:
Целое число, определяющее количество клеток, где можно установить уличные фонари.

Тестовый ввод (по три значения в строку через пробел):
4 4 3
2 2 3
3 1 4
4 4 4
Тестовый вывод:
9

Объяснение:
На картинке ниже, жёлтый обозначает первый трамвайный путь, зёлёный - второй путь, синий - третий путь. Уличный фонарь можно разместить на любой красной клетке, поэтому мы выводим число 9.

# How To:

Для ввода данных используется файл \TestTask\sourceData.txt
формат ввода согласно заданию (пункт "Тестовый ввод"):

вывод матрицы трамвайных путей и вывод результата происходит в консоль
