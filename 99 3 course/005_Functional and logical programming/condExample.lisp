 (defun cmp3(a b)
	(cond   ((< (first a) (first b)) "less");���� ������ ������� ������ a ������ ������� �������� ������ b, �� ����� "less" � �������� ���������� ������� ��� �� �������� � �.�.
			((> (first a) (first b)) "more")
			((< (second a) (second b)) "less")
			((> (second a) (second b)) "more")
			((< (third a) (third b)) "less")
			((>(third a) (third b)) "more")
			(T "first 3 elements are equal")));� ����� �� ������� ������ True � ��������������� �����

 (cmp3 '(1 2 3) '(1 3 2))