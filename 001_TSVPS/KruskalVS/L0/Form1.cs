using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Windows.Forms;
//using System.Collections.ObjectModel.ArrayList;
namespace L0
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }
        public double cntKrusc = 0, cntBellFord = 0, cntDeik = 0;//для подсчета сложности Краскала и остальных
        public int n;//число вершин графа
        //public int m;
        public double[,] mas;//матрица смежности графа
        public string[] elems;//список имён вершин для подписи в матрице
        public double[] dist;// расстояния для Беллмана-Форда
        public int iskm = 0;//вершина для подсчета расстояний от неё до остальных(Дейкстра, Форд-Беллман)
        public double[,] masBumaga;//массив для хранения матрицы в коде
        public double[,] masBumaga2;//массив для запоминания вводимых матриц
        private void button1_Click(object sender, EventArgs e)//  Start 
        {
            n = Convert.ToInt32(numericUpDown1.Value);
            if (n > 10000 || n < 0)
            {
                MessageBox.Show("Значение N в множестве по умолчанию не м.б. более 10000");
                numericUpDown1.Value = n = 0;
                return;
            }

            elems = new string[n];
            for (int i = 0; i < n; i++) { elems[i] = "V" + Convert.ToString(i); }

            Random rand = new Random();
            if (n != 0)
            {
                mas = new double[n, n];//граф представлен матрицей смежности
                dataGridView1.RowCount = n;
                dataGridView1.ColumnCount = n;
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
                masBumaga = new double[n, n];
                if ((checkBox2.Checked))//
                {
                    for (int ii = 0; ii < n; ++ii)
                    {
                        for (int jj = 0; jj < n; ++jj)
                        {
                            masBumaga[ii, jj] = Double.PositiveInfinity;// на старте длины рёбер бесконечны(связей нет)
                        }
                    }
                    masBumaga[0, 1] = 5; masBumaga[1, 0] = 5; masBumaga[0, 2] = 7; masBumaga[2, 0] = 7;
                    masBumaga[0, 4] = 1; masBumaga[4, 0] = 1; masBumaga[4, 3] = 4; masBumaga[3, 4] = 4;
                    masBumaga[3, 2] = 2; masBumaga[2, 3] = 2; masBumaga[1, 2] = 6; masBumaga[2, 1] = 6;
                    masBumaga[1, 4] = 3; masBumaga[4, 1] = 3;
                }


                for (int i0 = 0; i0 < n; ++i0)
                {
                    dataGridView1.Rows[i0].HeaderCell.Value = elems[i0].ToString();//называю хедеры рядов(строк) именами elems
                    for (int j0 = 0; j0 < n; ++j0)
                    {
                        mas[i0, j0] = Double.PositiveInfinity;// на старте длины рёбер бесконечны(связей нет)
                        if ((checkBox2.Checked) && !(checkBox3.Checked)) mas[i0, j0] = masBumaga[i0, j0];//считываем массив отсюда если поставлена галочка
                        else if (!(checkBox2.Checked) && (checkBox3.Checked)) mas[i0, j0] = masBumaga2[i0, j0];
                        dataGridView1.Columns[j0].HeaderCell.Value = elems[j0].ToString();//называю хедеры колонок(столбцов) именами elems
                                                                                          // mas[i, j] = rand.Next(20);
                        dataGridView1.Rows[i0].Cells[j0].Value = mas[i0, j0];
                    }
                }
            }

            else
            {
                MessageBox.Show("N не может быть нулевым");
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
        }
        private void makeSymmetrical()
        {

        }
        private void button3_Click(object sender, EventArgs e)//это кнопка Check
        {
            int i = 0, j = 0;
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {//двойная некрасивая проверка на правильность матрицы бинарного отношения(проверяет, использованы ли допустимые символы)
                    try
                    {//это присвоение чисел из таблички и скорее всего проверка на символы, не являющиеся числами
                        mas[i, j] = Convert.ToDouble(dataGridView1.Rows[i].Cells[j].Value);
                    }
                    catch (Exception ee)//типа если не удалось конвертнуть, то это не было числом
                    {
                        MessageBox.Show("Значения ячеек м.б. только числами.\n" +
                            "Проверьте ячейку [" + i + "][" + j + "] (" + elems[i] + ", " + elems[j] + ")", "неверный ввод",
     MessageBoxButtons.OK, MessageBoxIcon.Error); Console.WriteLine(ee); return;
                    }
                }
            }
            symmetryCheck();
        }

        public void symmetryCheck()
        {
            int i = 0, j = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                {
                    if (mas[i, j] != mas[j, i])
                    {
                        textBox3.Text = "Матрица не симметрична, т.к. (" + elems[i] + ", " + elems[j] +
                            ") не равно (" + elems[j] + ", " + elems[i] + ")";
                        return;
                    }
                    else continue;
                }
            textBox3.Text = "Матрица симметрична, т.к. все симметричные относительно главной диагонали элементы матрицы равны";
        }
        public void antySymmetryCheck()
        {
        }
        public void transitivityCheck()
        {

        }
        private void sizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.Owner = this;
            f.ShowDialog();
        }
        private void button4_Click(object sender, EventArgs e)//AllInfinity
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = double.PositiveInfinity;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
        }
        private void button2_Click(object sender, EventArgs e)//All0
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = 0;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
        }
        private void button5_Click(object sender, EventArgs e) { }//TransExamp

        private void button6_Click(object sender, EventArgs e) { }//задать новое множество

        private void Button7_Click(object sender, EventArgs e)//кнопка "сделать неориентированным"
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = mas[j, i];
                }
            }
        }
        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ФИО: Алексеев С.В. \nГруппа:ИП-712");
        }
        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Реализую алгоритм Дейкстры");
        }
        private void DataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {
            Int32 i = e.RowIndex;
            Int32 j = e.ColumnIndex;
            if (i < 0 || j < 0) return;
            mas[i, j] = Convert.ToDouble(dataGridView1.Rows[i].Cells[j].Value);
            // Была пролблема: Не получется интерактивно менять значения datagridview и массива mas почему-то. 
            if (checkBox1.Checked)
            {  // получилось, просто забывал конвертнуть всё время                
                dataGridView1.Rows[j].Cells[i].Value = mas[i, j];
                mas[j, i] = mas[i, j];
            }
        }
        private void CheckBox1_CheckedChanged(object sender, EventArgs e) { }
        private void CheckBox1_CheckStateChanged(object sender, EventArgs e) { }
        protected struct MyEdge//вот эти рёбрышки надо добавлять/удалять в алгоритме Краскала
        {
            public string name;
            public void setF(int hh) { from = hh; }
            public int from;//из какой вершины направлен
            public void setv1(string hh) { vertice1 = hh; }
            public String vertice1;//типа может быть буду проверку полноты остова проверять именами
            public void setTo(int hh) { to = hh; }
            public int to;//в какую вершину направлен
            public void setv2(string hh) { vertice2 = hh; }
            public String vertice2;
            public void setW(double hh) { weight = hh; }
            public double weight;//длина ребра
        }
        protected List<MyEdge> arr;//Здесь соберу все рёбра
        public void Button7_Click_1(object sender, EventArgs e)//КРАСКАЛ
        {
            //double[] edges = new double[(n * (n - 1) / 2)];// формула максимального числа рёбер(полного графа)           
            arr = new List<MyEdge>();
            for (int i = 0; i < n; i++)//Отрезаю нижний треугольник, т.к. граф  неориентированный
            {
                for (int j = 0; j < i; j++)
                {
                    mas[i, j] = double.PositiveInfinity;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!Double.IsInfinity(mas[i, j]))//если не бесконечность, значит есть вершина
                    {
                        MyEdge me = new MyEdge();
                        me.from = i;//записал в ребро  всю инфу
                        me.to = j;
                        me.vertice1 = dataGridView1.Rows[i].HeaderCell.Value.ToString();
                        me.vertice2 = dataGridView1.Columns[j].HeaderCell.Value.ToString();
                        me.weight = mas[i, j];
                        arr.Add(me);
                    }
                }
            }
            if (arr.Count == 0) return;
            IEnumerable<MyEdge> query = arr.OrderBy(MyEdge => MyEdge.weight);//просто делает запрос, исходный массив не сортируется
            List<MyEdge> srtd = new List<MyEdge>();//список отсортированных рёбер
            for (int i = 0; i < arr.Count; i++)
            {//добавил ссылки в новый массив. srtd вроде как получился индексным             
                srtd.Add(query.ElementAt(i));
            }
            int edgesNumber = srtd.Count;
            double k = Convert.ToDouble(edgesNumber);
            cntKrusc += k * Math.Log(k, 2);
            MyEdge[] result = new MyEdge[n - 1];//в результирующем списке рёбер всегда будет n-1
            int ee = 0; // индекс для масива result
            int ii = 0; // индекс для отсортированных рёбер                       
            subset[] subsets = new subset[n];
            for (ii = 0; ii < n; ++ii)// выделяю память для n подмассивов
            {
                subsets[ii] = new subset();
                subsets[ii].parent = ii;
                subsets[ii].rank = 0;
            }
            ii = 0;
            while (ee < n - 1)//пока не набрали n-1 рёбер
            {
                cntKrusc++;//подсчет одной попытки добавления ребра, результативной или нет, не важно
                MyEdge next_edge = new MyEdge();
                next_edge = srtd[ii++];//беру очередное ребро из списка отсортированных
                //сабсет изначально содержит все вершины в виде объектов subset
                //эти вершины представлены просто индексами каждого объекта сабсет.
                //А вот принадлежность к дереву изначально сама на себя(индекс сабсета и номер родителя одинаковы).
                //Т.е. вершина сама как бы является деревом, ссылаясь на себя. При добавлении новой вершины
                //она направляется на сабсет с индексом-номером этой, добавляемой вершины и ищет там своего предка,
                //гляда на родителя этого сабсета. Находит его и назначает себе. А при присоединении к вершине
                // с меньшим рангом всё равно ворзвращаешься на того же родителя.
                //Остановка происходит, когда добавлено n-1 рёбер. До этого может несколько рёбер пропустить, если
                //у обеих их вершин будет одинаковый предок.
                int x = find(subsets, next_edge.from);//ищем вершинки. Если они обе(их общие предки) уже есть
                int y = find(subsets, next_edge.to);//в сабсетах,то включение данного ребра бессмысленно

                if (x != y)//Если включение данного ребра не создаёт цикл(если общие предки вершин разные), то
                {//добавить его в result и увеличить индекс для выбора следующего ребра
                    result[ee++] = next_edge;//добавить ребро в список
                    Union(subsets, x, y);//добавить вершины в сабсеты(по сути назначить им общего родителя)
                    cntKrusc++;//подсчет одной результативной попытки
                }//иначе игнорировать ребро                
            }
            for (int i = 0; i < n; i++)
            {//Все вершины в бесконечность перед обновлением матрицы
                for (int j = 0; j < n; j++)
                {
                    mas[i, j] = double.PositiveInfinity;
                    dataGridView1.Rows[i].Cells[j].Value = mas[i, j];
                }
            }
            for (int a = 0; a < result.Length; a++)
            {//засовываю в mas & datagridview пересчитанные Краскалом значения
                int i = result[a].from;
                int j = result[a].to;
                double w = result[a].weight;
                mas[i, j] = w;
                dataGridView1.Rows[i].Cells[j].Value = w;
            }
            textBox1.Text = Convert.ToString(Convert.ToInt32(cntKrusc));
            cntKrusc = 0;
        }
        public class subset
        {//класс для реализации сабсета для поиска/объединения
            public int parent, rank;
        };
        void Union(subset[] subsets, int x, int y)//Функция, объединяющая 
        {// два значения икс и игрек. Использует объединение по рангу
            int xroot = find(subsets, x);
            int yroot = find(subsets, y);

            if (subsets[xroot].rank < subsets[yroot].rank)// Присоединить дерево меньшего ранга под корень 
                subsets[xroot].parent = yroot;//дерева более высокого ранга
            else if (subsets[xroot].rank > subsets[yroot].rank)
                subsets[yroot].parent = xroot;

            else// Если ранги одинаковые, то сделать один из них корнем
            {//и увеличить его ранг на 1. В принципе эти ранги можно было бы назначать и по другому принципу                
                subsets[yroot].parent = xroot;//т.о.
                subsets[xroot].rank++;//ранг увеличивается только если оба ранга были равны изначально 
            }//т.о. в итоге у вершины с меньшим рангом назначенена родителем вторая вершина и её ранг выше 
        }//т.е. потом новые вершины будут ставить своим родителем того, у которого больший ранг и таким образом
         //задастся жесткая структура. У всех поддеревьев, ещё не добавленных в основное будут свои корневые вершины
         //в единственном экземпляре для каждого поддерева. Потом по этим вершинам будет проверяться 
        int find(subset[] subsets, int i)//вспомогательная функция для поиска элемента i
        {
            cntKrusc++;//переприсвоения оптимизированы, поэтому трудоёмкость n^2*(log2(n)) оказывается завышенной?
            if (subsets[i].parent != i)  //нашёл корень и сделал 
                subsets[i].parent = find(subsets, subsets[i].parent);//корень родителем i(сжатие пути) 
            return subsets[i].parent;
        }

        private void Button8_Click(object sender, EventArgs e)//     DEIKSTRA
        {//Дейкстра не работает с рёбрами, у которых отрицательные веса 
            try
            {
                iskm = Convert.ToInt32(textBox6.Text);//ИСКОМАЯ ВЕРШИНА
            }
            catch (Exception)
            {
                MessageBox.Show("Введите вершину для поиска"); return;
            }
            dist = new double[n];

            // sptSet[i] will true if vertex 
            // i is included in shortest path 
            // tree or shortest distance from 
            // src to i is finalized 
            bool[] sptSet = new bool[n];//sptSet будет истина, если вершина i включена в кратчайший путь 
            for (int i = 0; i < n; i++)
            {
                dist[i] = double.PositiveInfinity;
                sptSet[i] = false;
            }
            dist[iskm] = 0;

            // Find shortest path for all vertices 
            for (int count = 0; count < n - 1; count++)
            {
                // Pick the minimum distance vertex 
                // from the set of vertices not yet 
                // processed. u is always equal to 
                // src in first iteration. 
                int u = minDistance(dist, sptSet);
                // Mark the picked vertex as processed 
                sptSet[u] = true;
                // Update dist value of the adjacent vertices of the picked vertex. 
                for (int v = 0; v < n; v++)
                    // Update dist[v] only if is not in 
                    // sptSet, there is an edge from u 
                    // to v, and total weight of path 
                    // from src to v through u is smaller 
                    // than current value of dist[v] 
                    if (!sptSet[v] && mas[u, v] != double.PositiveInfinity &&
                        dist[u] != double.PositiveInfinity && dist[u] + mas[u, v] < dist[v])
                        dist[v] = dist[u] + mas[u, v];
            }
            textBox1.Text = Convert.ToString(cntDeik);
            Form3 f1 = new Form3();
            f1.Owner = this;
            f1.ShowDialog();
            dist = null;
        }

        private void Button9_Click(object sender, EventArgs e)//запоминаю матрицу в массив
        {
            masBumaga2 = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    masBumaga2[i, j] = Convert.ToDouble(dataGridView1.Rows[i].Cells[j].Value);
                }
            }
        }

        int minDistance(double[] dist, bool[] sptSet)//возвращаю индекс минимального расстояния
        {
            // Initialize min value 
            double min = int.MaxValue;
            int min_index = -1;

            for (int v = 0; v < n; v++)
                if (sptSet[v] == false && dist[v] <= min)
                {
                    min = dist[v];
                    min_index = v;
                }
            return min_index;
        }


        private void Button5_Click_1(object sender, EventArgs e)// BellmanFord
        {
            try
            {
                iskm = Convert.ToInt32(textBox6.Text);//ИСКОМАЯ ВЕРШИНА
            }
            catch (Exception)
            {

                MessageBox.Show("Введите вершину для поиска"); return;
            }

            List<MyEdge> arr = new List<MyEdge>();
            arr = new List<MyEdge>();
            for (int i = 0; i < this.n; i++)
            {
                for (int j = 0; j < this.n; j++)
                {
                    if (!double.IsInfinity(mas[i, j]))//если не бесконечность, значит есть вершина
                    {
                        MyEdge me = new MyEdge();
                        me.from = i;//записал в ребро  всю инфу
                        me.to = j;
                        me.weight = mas[i, j];
                        arr.Add(me);
                    }
                }
            }

            int edgesNumber = arr.Count;
            dist = new double[n];
            for (int i = 0; i < n; ++i)//сначала расстояния считаем бесконечностями
                dist[i] = double.PositiveInfinity;
            dist[iskm] = 0;//расстояние до самой себя, очевидно равно нулю

            for (int i = 1; i < n; ++i)//для каждой вершины проходимся по всем рёбрам n-1 раз
                                       //(максимальное число рёбер между двумя вершинами: n-1)
            {
                for (int j = 0; j < edgesNumber; ++j)
                {
                    int u = arr[j].from;
                    int v = arr[j].to;
                    double weight = arr[j].weight;
                    //если уже известное расстояние до вершины u не равно бесконечности и добавление нового ребра 
                    //с началом в u меньше известного расстояния до вершины v, то делаем расстояние до вершины v
                    // равным расстоянию до u + длина данного ребра
                    if (dist[u] != double.PositiveInfinity && dist[u] + weight < dist[v])
                    { dist[v] = dist[u] + weight; cntBellFord++; }
                    cntBellFord++;
                }
            }
            for (int j = 0; j < edgesNumber; ++j)//проверка на негативный цикл
            {
                int u = arr[j].from;
                int v = arr[j].to;
                double weight = arr[j].weight;
                if (dist[u] != double.PositiveInfinity && dist[u] + weight < dist[v])
                //с минимальными расстояниями 
                //что -то не то, если они негативные. Просто они накапливают мимнимальное значение 
                //за счет негативных путей.
                {
                    textBox2.Text = "Есть отрицательный цикл";
                }
            }
            textBox1.Text = Convert.ToString(cntBellFord);
            Form3 f1 = new Form3();
            f1.Owner = this;
            f1.ShowDialog();
            dist = null;
        }
    }
}









//for (int i = 0; i < srtd.Count; i++)
//{
//    bool v1 = false, v2 = false;
//    foreach (string str in vertices)//проходим по всем накопленным на данный момент вершинам
//    {
//        if (str.Equals(srtd[i].vertice1)) v1 = true;//если очередная вершина равна одной из тех, 
//        //что в добавляемом ребре ставим флаг v1 = true
//        else if (str.Equals(srtd[i].vertice2)) v2 = true;// если и вторая вершина нового ребра уже 
//        //присутствует в списке, то ставим флаг v2 = true
//    }//если хоть одна вершина оказалась новой для нас, то добавляем это ребро
//    if (!v1 || !v2)
//    {
//        resultEdges.Add(srtd[i]);
//        if (!v1) vertices.Add(srtd[i].vertice1);//также пополняем список вершин
//        if (!v2) vertices.Add(srtd[i].vertice2);
//    }//теперь для каждой вершины прохожу путь from to и записываю посещенные вершины...нет...
//     //если в итоге .... это должно быть рекурсивным вызовом... который можно произвести из любой вершины
//     //если не все вершины окажутся включёнными, нужно продолжать добавлять рёбра и запускать рекурсию
//     //каждый раз... круто конечно и полезно самому сделать, но изобретение велосипеда в моей ситуации - 
//    //слишком дорогое удовольствие. 
//     //resultEdges[0].from               

//}