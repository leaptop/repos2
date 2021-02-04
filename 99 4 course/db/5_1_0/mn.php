<html> <head>
    <meta http-equiv="Content-Type" content="text/html;
charset=utf-8">
    <title> Paragraph 1 < /title>
        < /head> <body>
        <?php
        $serverName = "localhost";
        $username = "root";
        $password = "root";
        $dbname = "sample";
        $conn = new mysqli($serverName, $username, $password, $dbname);
        mysqli_set_charset($conn, 'utf8');
        //проверка подключения к ' "
        if ($conn->connect_error) {
            die("Нет соединения с MySQL" . $conn->connect_error);
        }
        //удаление табилцы
        $sql = "DROP TABLE IF EXISTS notebook_br01";
        //Проверка удаления таблицы
        if ($conn->query($sql) === TRUE) {
            echo "Таблица удалилась <br>";
        } else {
            echo "Ошибка удаления таблицы" . $conn-> error;
        }
        //создание таблицы notebook_br01
        $sql = "CREATE TABLE notebook_br01 (id INT(8) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
 name VARCHAR(50) NOT NULL,  city VARCHAR(50) NOT NULL,  address VARCHAR(50) NOT NULL,  birthday DATE, mail VARCHAR(20) NOT NULL )";
        if ($conn->query($sql) === TRUE) {
            echo "Таблица notebook_br01 создана";
        } else {
            echo "Ошибка в создании таблицы notebook_br01: " . $conn-> error;
        }
        $conn->close();
        ?>	 >
        < /body> < /html>
