# Letka Quadratic
<!--описание репозитория-->
Программа для решения квадратных уравнений по входным коэффициентам **a**, **b** и **c** в уравнении типа ***a\*x2 + b\*x + c = 0***.

<!--команда для компиляции-->
## Команда для компиляции
```g++ Source/In_Out.c Source/main.c Source/solver.c Source/tester.c Source/compare.c Source/output_tester_result.cpp -o quadr -I ./Header```

<!--параметры старта программы-->
## Параметры старта программы
> `-test`
> > включение режима тестирования
>
> `-file <name_file>`
> > ввод данных из файла *name_file*
> > > необходим аргумент *-test*

<!--описание файлов-->
## Описание файлов
| Название               | Описание                                                          |
|------------------------|-------------------------------------------------------------------|
| Main	                 | Основной файл                                                     |
| Types                  | Файл с новыми типами данных                                       |
| In_Out                 | Файл с функциями ввода/вывода                                     |
| Solver                 | Файл с функцией для решения уравнения                             |
| Tester                 | Файл с функцией для сравнения полученных корней  с ожидаемыми     |
| Compare                | Файл с функцией для сравнения двух чисел с плавающей точкой       |
| Output_tester_result   | Файл с функциями вывода результата в консоль или в отдельное окно |
