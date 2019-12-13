import java.awt.*;
import javax.swing.*;

public class Paints {
    public static void main(String[] args) {

        /* Задание заголовка окна*/
        JFrame w = new JFrame("Окно с изображением");
        /*Задание размеров окна*/
        w.setSize(400, 400);

        /* 	Если у окна не будет функции закрытия,
         *	при нажатии крестика окно не закроется.*/
        w.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        /*	Менеджер определяет
         *  каким образом в окне расположены объекты.*/
        w.setLayout(new BorderLayout(1, 1));

        Canvas canv = new Canvas();
        w.add(canv);
        w.setVisible(true);
    }
}

/* Класс, который будет рисовать элементы*/
class Canvas extends JComponent {

    /*Метод, перерисовывающий элемент внутри окна
     *при обновлении*/
    public void paintComponent(Graphics g) {
        super.paintComponents(g);
        Graphics2D g2d = (Graphics2D) g;

        /* 	Устанавливает цвет рисования в зелёный*/
        g2d.setPaint(Color.GREEN);

        /* 	Рисует текущим цветом прямоугольник	*/
        g2d.drawRect(100, 100, 80, 20);

        g2d.setPaint(Color.RED);
        /* 	Рисует текущим цветом в координатах (150,150) строку "привет мир"*/
        g2d.drawString("Привет мир", 150, 150);

        g2d.setColor(Color.blue);
        /*	Рисует текущим цветом овал в координатах (200,50)*/
        g2d.fillOval(200, 50, 50, 20);

        /* 	Вызывает обновление себя после завершения рисования	*/
        super.repaint();
    }
}