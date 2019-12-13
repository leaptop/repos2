 (defun cmp3(a b)
	(cond   ((< (first a) (first b)) "less");Если первый элемент списка a меньше первого элемента списка b, то пишем "less" и проверка дальнейших условий уже не делается и т.д.
			((> (first a) (first b)) "more")
			((< (second a) (second b)) "less")
			((> (second a) (second b)) "more")
			((< (third a) (third b)) "less")
			((>(third a) (third b)) "more")
			(T "first 3 elements are equal")));в конце по дефолту ставим True и соответствующий вывод

 (cmp3 '(1 2 3) '(1 3 2))