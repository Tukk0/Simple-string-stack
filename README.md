# Техническое задание
 В этой задаче запрещено пользоваться стандартной библиотекой C++, кроме файла <iostream>. В частности, запрещено использовать std::vector, std::stack, std::string и прочие классы. Динамическую память нужно выделять вручную, вместо std::string использовать строки в стиле Си. Самим объявлять какие-либо class и struct тоже нельзя. Разрешено пользоваться стандартной библиотекой C. Из фичей языка C++, не входящих в C, можно использовать только <iostream>, операторы new/delete, ссылки и константы. Вам нужно вручную реализовать структуру данных "стек". Этот стек будет хранить строки. Он должен поддерживать операции push и pop.

Стек может быть очень большим, поэтому вам нужно будет хранить его в динамической памяти. В каждом элементе стека будет храниться строка. Размеры строк также могут быть большими, поэтому вам нужно будет выделять динамическую память не только под вершины стека, но и под строки, хранящиеся в них. В вашей программе не должно быть UB и утечек памяти. Всю выделенную память надо корректно освобождать перед завершением работы программы.
* push somestring12345: положить строку somestring в конец стека. Строка всегда будет состоять только из английских букв или цифр, без пробельных символов. В ответ на эту команду нужно вывести «ok».
* pop: удалить из стека последний элемент и вывести его значение (то есть строку), либо вывести «error», если стек был пуст;
* back: сообщить значение последнего элемента стека, либо вывести «error», если стек пуст;
* size: вывести количество элементов в стеке;
* clear: опустошить стек и вывести «ok»;
* exit: вывести «bye» и завершить работу.
  
### Формат ввода
В каждой строке входных данных задана одна операция над стеком в формате, описанном выше.

### Формат вывода
В ответ на каждую операцию выведите соответствующее сообщение на отдельной строке. 
