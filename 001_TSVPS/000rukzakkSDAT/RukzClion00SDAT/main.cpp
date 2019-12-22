#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
int ind, cnt = 0;//cnt - трудоёмкость, ind - индекс товара с максимальным весом
vector<int> set;

int search_min(vector<int> m) {//возвращает элемент с минимальнм числом(весом)
    int min = m[0];
    for (int i = 1; i < m.size(); i++) {
        if (m[i] < min) min = m[i];
    }
    return min;
}

double search_max(vector<double> m) {//возвращает элемент с максимальным числом (для f)
    double max = m[0];
    for (int i = 1; i < m.size(); i++) {
        if (m[i] > max) {
            max = m[i];
            ind = i;
        }
    }
    return max;
}
//для последней оптимальной комбинации тупо берём товар из последнего индекса prev(23), это товар m[0], весом 5,
//дальше по остатку вместимости f обращаемся к соответствующей f(18). В ней индекс 1, берем товар с индексом 1 из m[1] и т.д.
vector<int> get_set_products(vector<int> prev, vector<int> m, int W) {
    vector<int> indexes;//индексы взятых товаров
    int weight = W;
    while (weight != 0) {//пока рюкзак не заполнен
        //идём с конца массива prev
        int temp = m[prev[weight]];//здесь как в саоде prev - индексный массив для доступа к элементам weight
        if (weight - temp < 0) break;
        indexes.push_back(prev[weight]);
        weight -= temp;
    }
    return indexes;
}

double knapsackSolver(vector<int> m, vector<double> c, int W, int n) {//m - mass,  c -cost
    vector<double> f, sums;
    vector<int> prev;//список, каждый элемент которого хранит индекс добавленного на данной итерации товара,
    //добавление которого обеспечило оптимальную загруженность мешка
    int min_mass = search_min(m);//нашёл минимальную массу
    for (int i = 0; i < W; i++) {
        if (i < min_mass) {//загнал все "элементы" с весами меньше минимально существующего в векторы(нули в нули)
            f.push_back(0);
            prev.push_back(0);
        } else break;
    }
    for (size_t i = f.size(); i <= W; i++) {//сделал i размером f.size, а это вес минимального элемента
        //cnt++;
        for (int k = 0; k < n; k++) {//проходимся по товарам
            cnt++;
            int temp = i - m[k];//на первой итерации из i вычел первое значение списка масс
            if (temp < 0) sums.push_back(-1);//если на текущую сумму очередной товар купить нельзя, то в sums добавляем элемент -1
            else sums.push_back(f[i - m[k]] + c[k]);//иначе добавляем (f[i - m[k]] + c[k]) прямо как в методичке
        }
        double max = search_max(sums);//ищем максимальное значение в sums (то, что я выделял хайлайтером)
        // Всё оказалось так просто
        //а я уже начал придумывать как же находить максимальное число среди параметров рекурсивной функции
        prev.push_back(ind);// добавляем индекс добавленного товара в prev.
        // Он является индексом этого товара, потому что в списке sums именно этот элемент дал максимальное число
        f.push_back(max);//выбираем максимальное f(...) и включаем в список f, всё как в методичечке
        sums.clear();
        ind = 0;
    }
    set = get_set_products(prev, m, W);
    return f[f.size() - 1];
}

int main() {
    system("chcp 65001");
    int W, N;
    char ch;
    int num;
    double num_1;
    vector<int> masses;//  C:\Users\Stepan\source\repos2\001_TSVPS\000rukzakkSDAT\RukzClion00SDAT
    vector<double> costs;//C:\Users\Stepan\source\repos2\001_TSVPS\rukzakk\RukzClion00
    ifstream fin    (R"(C:\Users\Stepan\source\repos2\001_TSVPS\000rukzakkSDAT\RukzClion00SDAT\input.txt)");
    fin >> W >> N;// первые составляющие файла(первая строка) - вместимость рюкзака, длина массива весов/цен
    for (int i = 0; i < N; i++) {
        int tmp;
        fin >> tmp;
        masses.push_back(tmp);//далее веса
        fin >> tmp;
        costs.push_back(tmp);//далее стоимости
    }

    double max_cost = knapsackSolver(masses, costs, W, N);
// set[i] + 1 == продукт по счету
    for (int i = 0; i < set.size(); i++) {
        printf("Вес\t\t %d\t\tЦена\t\t %d\n", masses[set[i]], (int) costs[set[i]]);
    }
    cout << "----------------------------------" << endl;
    printf("Полный вес %d\t\t Полная стоимость %d\n", W, (int) max_cost);
    printf("\nТрудоёмкость: %d\n\n", cnt);
//трудоёмкость равна асортименту товаров умноженному на общую грузоподъёмность
    return 0;
}