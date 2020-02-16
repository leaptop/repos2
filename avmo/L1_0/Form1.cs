
using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
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
            Console.WriteLine("HIIIIII");
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
                    //masBumaga[0, 1] = 5; masBumaga[1, 0] = 5; masBumaga[0, 2] = 7; masBumaga[2, 0] = 7;
                    //masBumaga[0, 4] = 1; masBumaga[4, 0] = 1; masBumaga[4, 3] = 4; masBumaga[3, 4] = 4;
                    //masBumaga[3, 2] = 2; masBumaga[2, 3] = 2; masBumaga[1, 2] = 6; masBumaga[2, 1] = 6;
                    //masBumaga[1, 4] = 3; masBumaga[4, 1] = 3;

                    //masBumaga[0, 1] = 10; masBumaga[0, 3] = 30; masBumaga[0, 4] = 100; masBumaga[1, 2] = 50;
                    //masBumaga[2, 4] = 10; masBumaga[3, 2] = 20; masBumaga[2, 4] = 10;//из ютуба по Дейкстре

                    masBumaga[0, 1] = 3; masBumaga[1, 0] = 3; //masBumaga[0, 2] = 7; masBumaga[2, 0] = 7;     
                    masBumaga[0, 7] = 1; //masBumaga[7, 0] = 1;
                    masBumaga[4, 0] = 2; masBumaga[0, 4] = 2;
                    masBumaga[4, 7] = 2; masBumaga[7, 4] = 3;
                    masBumaga[4, 8] = 5; masBumaga[8, 4] = 5;
                    // masBumaga[7, 8] = 2;
                    masBumaga[8, 7] = 2;
                    masBumaga[4, 1] = 5; masBumaga[1, 4] = 5;
                    masBumaga[1, 5] = 2; masBumaga[5, 1] = 2;
                    masBumaga[5, 8] = 3; masBumaga[8, 5] = 3;
                    masBumaga[1, 2] = 1; masBumaga[2, 1] = 1;
                    masBumaga[3, 2] = 3; masBumaga[2, 3] = 3;
                    masBumaga[4, 5] = 1; masBumaga[5, 4] = 1;
                    masBumaga[2, 6] = 1; masBumaga[6, 2] = 1;
                    masBumaga[2, 5] = 6; masBumaga[5, 2] = 6;
                    masBumaga[5, 9] = 8; masBumaga[9, 5] = 8;
                    masBumaga[8, 9] = 4; masBumaga[9, 8] = 4;
                    masBumaga[6, 9] = 2; masBumaga[9, 6] = 2;
                    masBumaga[9, 10] = 4; masBumaga[10, 9] = 4;
                    masBumaga[2, 5] = 6; masBumaga[5, 2] = 6;
                    masBumaga[6, 10] = 8; masBumaga[10, 6] = 8;
                    masBumaga[3, 6] = 7; masBumaga[6, 3] = 7;
                    masBumaga[3, 10] = 1; masBumaga[10, 3] = 1;

                    //расписать пути как идти до конечных вершин
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
        {//отслеживаю изменение DataGridViewCellEventArgs, 
            Console.WriteLine("sender.ToString() = " + sender.ToString());
            Int32 i = e.RowIndex;//получаю координаты изменённой ячейки
            Int32 j = e.ColumnIndex;
            if (i < 0 || j < 0) return;
            mas[i, j] = Convert.ToDouble(dataGridView1.Rows[i].Cells[j].Value);//и добавляю их в массив
            // Была пролблема: Не получется интерактивно менять значения datagridview и массива mas почему-то. 
            // if (checkBox1.Checked)// checkBox1 это про неориентированный
            if (false)
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
            cntKrusc++;
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
                subsets[i].parent = find(subsets, subsets[i].parent);
            return subsets[i].parent;
        }

        private void Button8_Click(object sender, EventArgs e)//     DEIKSTRA
        {//Дейкстра не работает с рёбрами, у которых отрицательные веса 
            try//расписать пути как идти до конечных вершин
            {
                iskm = Convert.ToInt32(textBox6.Text);//ИСКОМАЯ ВЕРШИНА
            }
            catch (Exception)
            {
                MessageBox.Show("Введите вершину для поиска"); return;
            }
            dist = new double[n];

            //List<string> strn = new List<string>(n);
            //strn.Add("V" + iskm);

            string[,] strn = new string[n, n];

            for (int i = 0; i < n; i++)
            {
                strn[i, 0] = "V" + i;
            }

            bool[] sptSet = new bool[n];//sptSet будет истина, если вершина i включена в кратчайшее дерево или 
            for (int i = 0; i < n; i++)//кратчайшее расстояние от src до i финально
            {
                //strn[i,0]
                dist[i] = double.PositiveInfinity;
                sptSet[i] = false;
            }

            dist[iskm] = 0;
            int[,] way = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                way[i, 0] = iskm;
            }
            for (int count = 0; count < n - 1; count++)
            {// u - начало, v - продолжение    
                int sch = 1;
                int u = minDistance(dist, sptSet);//где-то здесь на первой итерации находим ребро, 
                                                  //исходящее из первой вершины и имеющее минимальны вес. 
                                                  //Включаем эту вершину(на противоположном конце ребра) в список.               
                sptSet[u] = true;//помечаю выбранное ребро как обработанное. Т.е. кратчайший путь до него найден. По крайней мере он кратчайший по результатам предыдущих итераций
                for (int v = 0; v < n; v++)//ищу длины путей из вершины с минимальным dist до смежных с ней. Обновляю значения dist смежных вершин с выбранной(до которой минимальное расстояние от исходной)
                {//здесь перебираем все рёбра из u 
                    if//короче походу u - исходная вершинка, из которой по итерациям ищем ближайшую к ней
                    //у чувака в видео она даже заносится отдельно и начинает называться w временно до след. итерации
                        ((!sptSet[v]) && //обновляю dist[v] только если  она не в sptSet 
                        (mas[u, v] != double.PositiveInfinity) &&//и есть ребро из u в v
                        (dist[u] != double.PositiveInfinity) &&
                        (dist[u] + mas[u, v]) < dist[v])//и если весь вес пути из src в v через u меньше,  
                    {                                   //чем текущее значение dist[v] 
                        dist[v] = dist[u] + mas[u, v];
                        way[count, sch++] = v;
                        cntDeik++;
                    }
                    cntDeik++;
                }//с какого-то места(на какой-то итерации) проверка идёт только от наименее удалённого ребра
            }
            dijkstra(mas, iskm);
            textBox1.Text = Convert.ToString(cntDeik);
            Form3 f1 = new Form3();
            f1.Owner = this;
            f1.ShowDialog();
            dist = null;
            cntDeik = 0;
            
            
        }

        int minDistance(double[] dist, bool[] sptSet)//возвращаю индекс минимального dist
        {
            double min = int.MaxValue;
            int min_index = -1;

            for (int v = 0; v < n; v++)
                if (sptSet[v] == false && dist[v] <= min)//однако пропускаем уже добавленные вершины if(sptSet[v] == false...)
                {
                    min = dist[v];
                    min_index = v;
                }
            return min_index;//возвращает индекс вершины dist с минимальным числом
        }





        public static readonly int NO_PARENT = -1;
        private static void dijkstra(double[,] mas, int startVertex)
        {

            int nVertices = mas.GetLength(0);

            // shortestDistances[i] will hold the 
            // shortest distance from src to i 
            double[] shortestDistances = new double[nVertices];

            // added[i] will true if vertex i is 
            // included / in shortest path tree 
            // or shortest distance from src to 
            // i is finalized 
            bool[] added = new bool[nVertices];

            // Initialize all distances as 
            // INFINITE and added[] as false 
            for (int vertexIndex = 0; vertexIndex < nVertices;
                                                vertexIndex++)
            {
                shortestDistances[vertexIndex] = int.MaxValue;
                added[vertexIndex] = false;
            }

            // Distance of source vertex from 
            // itself is always 0 
            shortestDistances[startVertex] = 0;

            // Parent array to store shortest 
            // path tree 
            int[] parents = new int[nVertices];

            // The starting vertex does not 
            // have a parent 
            parents[startVertex] = NO_PARENT;

            // Find shortest path for all 
            // vertices 
            for (int i = 1; i < nVertices; i++)
            {

                // Pick the minimum distance vertex 
                // from the set of vertices not yet 
                // processed. nearestVertex is 
                // always equal to startNode in 
                // first iteration. 
                int nearestVertex = -1;
                double shortestDistance = int.MaxValue;
                for (int vertexIndex = 0;
                        vertexIndex < nVertices;
                        vertexIndex++)
                {
                    if (!added[vertexIndex] &&
                        shortestDistances[vertexIndex] <
                        shortestDistance)
                    {
                        nearestVertex = vertexIndex;
                        shortestDistance = shortestDistances[vertexIndex];
                    }
                }

                // Mark the picked vertex as 
                // processed 
                added[nearestVertex] = true;

                // Update dist value of the 
                // adjacent vertices of the 
                // picked vertex. 
                for (int vertexIndex = 0;
                        vertexIndex < nVertices;
                        vertexIndex++)
                {
                    double edgeDistance = mas[nearestVertex, vertexIndex];

                    if (edgeDistance > 0
                        && ((shortestDistance + edgeDistance) <
                            shortestDistances[vertexIndex]))
                    {
                        parents[vertexIndex] = nearestVertex;
                        shortestDistances[vertexIndex] = shortestDistance +
                                                        edgeDistance;
                    }
                }
            }

            printSolution(startVertex, shortestDistances, parents);
        }

        private static void printSolution(int startVertex,
                                        double[] distances,
                                        int[] parents)
        {
            int nVertices = distances.Length;
            Console.Write("Vertex\t Distance\tPath");

            for (int vertexIndex = 0;
                    vertexIndex < nVertices;
                    vertexIndex++)
            {
                if (vertexIndex != startVertex)
                {
                    Console.Write("\n" + startVertex + " -> ");
                    Console.Write(vertexIndex + " \t\t ");
                    Console.Write(distances[vertexIndex] + "\t\t");
                    printPath(vertexIndex, parents);
                }
            }
        }
        private static void printPath(int currentVertex, int[] parents)
        {

            if (currentVertex == NO_PARENT)
            {
                return;
            }
            printPath(parents[currentVertex], parents);
            Console.Write(currentVertex + " ");
        }







        private void Button10_Click(object sender, EventArgs e)//записываю матрицу в файл
        {
            List<string> list = new List<string>();
            for (int rows = 0; rows < dataGridView1.Rows.Count; rows++)
            {
                for (int col = 0; col < dataGridView1.Rows[rows].Cells.Count; col++)
                {
                    string value = dataGridView1.Rows[rows].Cells[col].Value.ToString();
                    list.Add(value);
                }
                list.Add("\n");
            }
            System.IO.StreamWriter file = new System.IO.StreamWriter(@"test.txt");
            foreach (var item in list)
            {
                if (item != "\n")//если не конец строки
                {
                    file.Write(item + "\t");// - записываю просто в одну сроку
                }
                else
                {
                    file.WriteLine(item);//иначе заканчиваю строку последним символом
                }

            }
            file.Close();
        }

        private void Button11_Click(object sender, EventArgs e)//вытаскиваю матрицу из файла
        {
            System.IO.StreamReader file = new System.IO.StreamReader(@"test.txt");

            List<string> list = new List<string>();
            for (int rows = 0; rows < dataGridView1.Rows.Count; rows++)
            {
                //string str = file.ReadLine();
                //str.Trim();
                // str.Split('\t');
                list.Add(file.ReadLine());

                // str.
                for (int col = 0; col < dataGridView1.Rows[rows].Cells.Count; col++)
                {
                    dataGridView1.Rows[rows].Cells[col].Value =
                        list[col];
                    //list.Add(value);
                }

            }

            file.Close();
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
            dijkstra(mas, iskm);
            textBox1.Text = Convert.ToString(cntBellFord);
            Form3 f1 = new Form3();
            f1.Owner = this;
            f1.ShowDialog();
            dist = null;
            cntBellFord = 0;
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