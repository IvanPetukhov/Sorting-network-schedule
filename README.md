# Sorting-network-schedule
Разработать последовательную программу вычисления расписания сети сортировки, числа  использованных компараторов и числа тактов, необходимых для её срабатывания при  выполнении на n процессорах. Число тактов сортировки при параллельной обработке не должно  превышать числа тактов, затрачиваемых четно-нечетной сортировкой Бетчера.

Параметр командной строки запуска: n.
 
n>=1 – количество элементов в упорядочиваемом массиве, элементы которого расположены на строках с номерами [0…n-1]
 
Формат команды запуска:
bsort n
 
Требуется:
1.      вывести в файл стандартного вывода расписание и его характеристики в представленном далее формате;
2.      обеспечить возможность вычисления сети сортировки для числа элементов 1<=n<=10000;
3.      предусмотреть полную проверку правильности сети сортировки для значений числа сортируемых элементов 1<=n<=24;
4.      представить краткий отчет удовлетворяющий указанным далее требованиям.
 
Формат файла результата:
Начало файла результата
n 0 0
 
cu0  cd0
cu1  cd1
…
cun_comp-1  cdn_comp-1
 
n_comp
n_tact
Конец файла ре результата
 
Здесь:
n 0 0      –   число сортируемых элементов, ноль, ноль. 
Да, вывести число элементов и два нуля.
 
cui  cdi   – номера строк, соединяемых i-м компаратором сравнения перестановки.
n_comp  – число компараторов
n_tact     – число тактов сети сортировки
 
 
Требования к краткому отчету:
1        Титульный лист, содержащий
1.1  Название курса
1.2  Название работы
1.3  Фамилию, Имя, Отчество(при наличии)
1.4  Номер группы
1.5  Дата подачи
2        Описание условия
3        Описание метода решения
4        Описание метода проверки
5        Приложение1: исходный текст программы в отдельном с/с++ файле
 
Пример:
 
Команда запуска
bsort 4
 
Содержимое файла результата:
4 0 0
  0   1
  2   3
  0   2
  1   3
  1   2
5
3
