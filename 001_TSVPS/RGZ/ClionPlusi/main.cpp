#include <stdio.h>//СДЁРНУТО С АВС-а. КАК КУРСАЧ ДЛЯ ТСВПС ВРЯД ЛИ ПОДОЙДЕТ,
#include <stdlib.h>//Т.К. ВЫИГРЫШ ЗДЕСЬ НЕ В КОЛИЧЕСТВЕ ОПЕРАЦИЙ, А В СКОРОСТИ
#include <time.h>
#include <cmath>
int cnt = 0;
int cnt2 = 0;
void arrayRandomFill(double array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
}

void matrixRGZFill(double **matrix, int order) {
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            matrix[i][j] = pow(-1, (i + j));
        }
    }
}

void matrixRGZFill2(double **matrix, int order) {
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            matrix[i][j] = (i + j);
        }
    }
}

// Самое обычное перемножение матриц, имеет наихудшую производительность
void simpleMul(double **matrix1, double **matrix2, double **resultMatrix, int order) {
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            for (int k = 0; k < order; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                cnt++;
            }
        }
    }
}


// Блочный алгоритм умножения. Самый быстрый из всех.
void blockMul(double *matrix1, double *matrix2, double *resultMatrix, int order, int blockSize) {
    int i0, k0, j0;
    double *a0, *c0, *b0;
    for (int i = 0; i < order; i += blockSize) {
        for (int j = 0; j < order; j += blockSize) {
            for (int k = 0; k < order; k += blockSize) {
                for (i0 = 0, c0 = (resultMatrix + i * order + j), a0 = (matrix1 + i * order + k);
                     i0 < blockSize; ++i0, c0 += order, a0 += order) {
                    for (k0 = 0, b0 = (matrix2 + k * order + j); k0 < blockSize; ++k0, b0 += order) {
                        for (j0 = 0; j0 < blockSize; ++j0) {
                            c0[j0] += a0[k0] * b0[j0];
                            cnt2++;
                        }
                    }
                }
            }
        }
    }
}

// Запускает simpleMul или dgemm2 и возвращает время выполнения умножения
// Параметры: order - порядок матрицы, параметр dgemm определяет какой алгоритм запустить 1 или 2
double simpleMultiplicationTimer(int order, int func) {
    // Выделение динамической памяти, так как большие матрицы не влезают в стек
    double *matrix1[order];
    double *matrix2[order];
    double *resultMatrix[order];
    for (int i = 0; i < order; ++i) {
        matrix1[i] = static_cast<double *>(malloc(order * sizeof(double)));
        matrix2[i] = static_cast<double *>(malloc(order * sizeof(double)));
        // Матрицу с результатом умножения надо инициализировать нулями, т.е. при помощи calloc, а не malloc,
        // так как каждый элемент матрицы умножения является суммой произведений
        resultMatrix[i] = static_cast<double *>(calloc(order, sizeof(double)));
    }

    matrixRGZFill(matrix1, order);
    matrixRGZFill2(matrix2, order);

    clock_t start = clock();
    if (func == 1) {  // Выбор алгоритма в зависимости от параметра
        simpleMul(matrix1, matrix2, resultMatrix, order);
    }
    clock_t stop = clock();

    for (int i = 0; i < order; ++i) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatrix[i]);
    }
    return (double) (stop - start) / CLOCKS_PER_SEC;  // Время выполнения (в секундах)
}

// Запускает blockMul и возвращает время blockSize должен быть кратен порядку матрицы
double blockMultiplicationTimer(int order, int blockSize) {
    // В отличие от предыдущих алгоритмов, этот требует представление матриц в виде одномерных массивов размером
    // квадрата порядка матрицы.
    int size = order * order;

    // Выделение динамической памяти, так как большие матрицы не влезут в стек
    double *matrix1 = static_cast<double *>(malloc(size * sizeof(double)));
    double *matrix2 = static_cast<double *>(malloc(size * sizeof(double)));
    // Матрицу с результатом умножения надо инициализировать нулями, т.е. при помощи calloc, а не malloc
    double *resultMatrix = static_cast<double *>(calloc(size, sizeof(double)));

    clock_t start = clock();
    blockMul(matrix1, matrix2, resultMatrix, order, blockSize);
    clock_t stop = clock();

    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return (double) (stop - start) / CLOCKS_PER_SEC;
}

// Часть 1 - ввод порядка матриц и размера блока с клавиатуры
// Выводит на экран время работы двух способов умножения
void part1() {
    int order, blockSize;
    printf("Input matrix order: ");
    scanf("%d", &order);
    printf("Input size of block: ");
    scanf("%d", &blockSize);

    double simpleTime = simpleMultiplicationTimer(order, 1);
    double blockTime = blockMultiplicationTimer(order, blockSize);
    printf("\nSimple (simpleMul) multiplication time: %f sec\n", simpleTime);
    printf("Block multiplication time: %f sec\n", blockTime);
}
// Про вторую часть написал в readme
void part2() {
    int order = 500;
    int blockSize = order / 2;//
    printf("simpleMul\n");
    printf("%f sec\n", simpleMultiplicationTimer(order, 1));
    printf("trudoemkost: %d\n", cnt);
    printf("blockMul\n");
    printf("%f sec\nblockSize: %d\n", blockMultiplicationTimer(order, blockSize),blockSize);
    printf("trudoemkost: %d", cnt2);
}

int main() {
    part2();
}