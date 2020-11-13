package com.example.water;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.ShortBuffer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.Matrix;
import android.os.SystemClock;
import android.util.Log;

public class MyClassRenderer implements GLSurfaceView.Renderer{
    // интерфейс GLSurfaceView.Renderer содержит
    // три метода onDrawFrame, onSurfaceChanged, onSurfaceCreated
    // которые должны быть переопределены
    //
    // текущий контекст
    private Context context;
    //координаты камеры
    private float xСamera, yCamera, zCamera;
    //координаты источника света
    private float xLightPosition, yLightPosition, zLightPosition;

    //матрицы
    private float[] modelMatrix;
    private float[] viewMatrix;
    private float[] modelViewMatrix;
    private float[] projectionMatrix;
    private float[] modelViewProjectionMatrix;
    //размеры сетки
    private int imax=100;
    private int jmax=100;
    //размер индексного массива
    private int sizeindex;
    //начальная координата x
    private float x0=-3.5f;
    //начальная координата z
    private float z0=-3.5f;
    //шаг сетки по оси x
    private float dx=0.07f;
    //шаг сетки по оси z
    private float dz=0.05f;
    // массив для хранения координаты x
    private float [] x;
    // массив для хранения координаты y
    private float [][] y;
    //массив для хранения координаты z
    private float [] z;
    //массив для хранения координат вершин для записи в буфер
    private float [] vertex;
    //массивы для хранения координат вектора нормали
    private float [][] normalX;
    private float [][] normalY;
    private float [][] normalZ;
    //массив для хранения координат вектора нормали для записи в буфер
    private float [] normal;
    //буферы для координат вершин и нормалей
    private FloatBuffer vertexBuffer, normalBuffer;
    //буфер индексов
    private ShortBuffer indexBuffer;
    //шейдерный объект
    private Shader mShader;
    //
    //объект текстуры
    Texture mTexture0;

    private int countframe;
    private long time1, time2;
    private float timekadr;
    private float fps;



    //конструктор
    public MyClassRenderer(Context context) {
        // запомним контекст
        // он нам понадобится в будущем для загрузки текстур
        this.context=context;
        //координаты точечного источника света
        xLightPosition=5f;
        yLightPosition=30f;
        zLightPosition=5f;

        //матрицы
        modelMatrix=new float[16];
        viewMatrix=new float[16];
        modelViewMatrix=new float[16];
        projectionMatrix=new float[16];
        modelViewProjectionMatrix=new float[16];
        //мы не будем двигать объекты
        //поэтому сбрасываем модельную матрицу на единичную
        Matrix.setIdentityM(modelMatrix, 0);
        //координаты камеры
        xСamera=1.3f;
        yCamera=2.5f;
        zCamera=0.3f;
        //пусть камера смотрит на начало координат
        //и верх у камеры будет вдоль оси Y
        //зная координаты камеры получаем матрицу вида
        Matrix.setLookAtM(
                viewMatrix, 0, xСamera, yCamera, zCamera, 0, 0, 0, 0, 1, 0);
        // умножая матрицу вида на матрицу модели
        // получаем матрицу модели-вида
        Matrix.multiplyMM(modelViewMatrix, 0, viewMatrix, 0, modelMatrix, 0);
        // создаем массивы
        x=new float [imax+1];
        z=new float [jmax+1];
        y=new float [jmax+1][imax+1];
        vertex=new float[(jmax+1)*(imax+1)*3];
        normalX=new float[jmax+1][imax+1];
        normalY=new float[jmax+1][imax+1];
        normalZ=new float[jmax+1][imax+1];
        normal=new float[(jmax+1)*(imax+1)*3];
        //заполним массивы x и z координатами сетки
        for (int i=0; i<=imax; i++){
            x[i]=x0+i*dx;
        }
        for (int j=0; j<=jmax; j++){
            z[j]=z0+j*dz;
        }
        //создадим буфер для хранения координат вершин
        // он заполняется в методе getVertex()
        ByteBuffer vb = ByteBuffer.allocateDirect((jmax+1)*(imax+1)*3*4);
        vb.order(ByteOrder.nativeOrder());
        vertexBuffer = vb.asFloatBuffer();
        vertexBuffer.position(0);
        //создадим буфер для хранения координат векторов нормалей
        // он заполняется в методе getNormal()
        ByteBuffer nb = ByteBuffer.allocateDirect((jmax+1)*(imax+1)*3*4);
        nb.order(ByteOrder.nativeOrder());
        normalBuffer = nb.asFloatBuffer();
        normalBuffer.position(0);
        //индексы
        // временный массив индексов
        short[] index;
        // 2*(imax+1) - количество индексов в ленте
        // jmax - количество лент
        // (jmax-1) - добавленные индексы для связки лент
        sizeindex=2*(imax+1)*jmax + (jmax-1);
        index = new short[sizeindex];
        // расчет массива индексов для буфера
        int k=0;
        int j=0;
        while (j < jmax) {
            // лента слева направо
            for (int i = 0; i <= imax; i+=2) {
                index[k] = chain(j,i);
                k++;
                index[k] = chain(j+1,i);
                k++;
            }
            if (j < jmax-1){
                // вставим хвостовой индекс для связки
                index[k] = chain(j+1,imax);
                k++;
            }
            // переводим ряд
            j++;
            //
            // проверяем достижение конца
            if (j < jmax){
                // лента справа налево
                for (int i = imax; i >= 0; i-=2) {
                    index[k] = chain(j,i);
                    k++;
                    index[k] = chain(j+1,i);
                    k++;
                }
                if (j < jmax-1){
                    // вставим хвостовой индекс для связки
                    index[k] = chain(j+1,0);
                    k++;
                }
                // переводим ряд
                j++;
            }
        }
        // буфер индексов - тип short содержит 2 байта
        ByteBuffer bi = ByteBuffer.allocateDirect(sizeindex * 2);
        bi.order(ByteOrder.nativeOrder());
        indexBuffer = bi.asShortBuffer();
        // заполняем буфер индексов
        indexBuffer.put(index);
        indexBuffer.position(0);
        // уничтожаем временный массив индексов,
        // т.к. в дальнейшем нужен только буфер индексов
        index = null;
        //начальное заполнение буферов вершин и нормалей
        getVertex();
        getNormal();
    }//конец конструктора


    // вспомогательная функция
    // возвращает порядковый номер вершины по известным j и i
    private short chain(int j, int i){
        return (short) (i+j*(imax+1));
    }

    //метод выполняет расчет координат вершин
    private void getVertex(){
        double time=System.currentTimeMillis();
        // заполним массив Y значениями функции
        for (int j=0; j<=jmax; j++){
            for (int i=0; i<=imax; i++){
                y[j][i]=0.2f*(float)Math.cos(0.005*time+5*(z[j]+x[i]));
            }
        }
        // заполним массив координат vertex
        int k=0;
        for (int j=0; j<=jmax; j++){
            for (int i=0; i<=imax; i++){
                vertex[k]=x[i];
                k++;
                vertex[k]=y[j][i];
                k++;
                vertex[k]=z[j];
                k++;
            }
        }
        //перепишем координаты вершин из массива vertex в буфер
        vertexBuffer.put(vertex);
        vertexBuffer.position(0);
    }

    //метод выполняет расчет векторов нормалей
    //по известным координатам вершин
    private void getNormal(){
        for (int j=0; j<jmax; j++){
            for (int i=0; i<imax; i++){
                normalX [j] [i] =  - ( y [j] [i+1] - y [j] [i] ) * dz;
                normalY [j] [i] = dx *0.6f;
                normalZ [j] [i] =  dx * -( y [j+1] [i] - y [j] [i] );
            }
        }
        //нормаль для i=imax
        for (int j=0; j<jmax; j++){
            normalX [j] [imax] = -( y [ j ] [ imax -1] - y [ j ] [ imax] ) * dz;
            normalY [j] [imax] = dx ;
            normalZ [j] [imax] = dx * ( y [ j+1 ] [ imax] - y [ j ] [ imax ] );
        }
        //нормаль для j=jmax
        for (int i=0; i<imax; i++){
            normalX [jmax] [ i ] = - ( y [ jmax ] [ i+1 ] - y [ jmax ] [ i ] ) * dz;
            normalY [jmax] [ i ] = dx ;
            normalZ [jmax] [ i ] = -dx * ( y [ jmax-1 ] [ i ] - y [ jmax ] [ i ] );
        }
        //нормаль для i=imax и j=jmax
        normalX [jmax] [ imax ]= (y [ jmax] [ imax-1] - y [ jmax] [imax]) * dz;
        normalY [jmax] [ imax ] = dx ;
        normalZ [jmax] [ imax ] = dx * (y [jmax-1] [imax] - y[jmax ] [imax]);
        //переписываем координаты вектора нормали в одномерный массив normal
        int k=0;
        for (int j=0; j<=jmax; j++){
            for (int i=0; i<=imax; i++){
                normal[k]=normalX[j][i];
                k++;
                normal[k]=normalY[j][i];
                k++;
                normal[k]=normalZ[j][i];
                k++;
            }
        }
        //отправляем одномерный массив normal в буфер
        normalBuffer.put(normal);
        normalBuffer.position(0);
    } // конец метода


    //метод, который срабатывает при изменении размеров экрана
    //в нем мы получим матрицу проекции и матрицу модели-вида-проекции
    public void onSurfaceChanged(GL10 unused, int width, int height) {
        // устанавливаем glViewport
        GLES20.glViewport(0, 0, width, height);
        float ratio = (float) width / height ;
        float k=0.055f;
        float left = -k*ratio;
        float right = k*ratio;
        float bottom = -k;
        float top = k;
        float near = 0.11f;
        float far = 10.0f;
        // получаем матрицу проекции
        Matrix.frustumM(projectionMatrix, 0, left, right, bottom, top, near, far);
        // матрица проекции изменилась,
        // поэтому нужно пересчитать матрицу модели-вида-проекции
        Matrix.multiplyMM(
                modelViewProjectionMatrix, 0, projectionMatrix, 0, modelViewMatrix, 0);
    }

    //метод, который срабатывает при создании экрана
    //здесь мы создаем шейдерный объект
    public void onSurfaceCreated(GL10 unused, EGLConfig config) {
        //включаем тест глубины
        GLES20.glEnable(GLES20.GL_DEPTH_TEST);
        //включаем отсечение невидимых граней
        GLES20.glEnable(GLES20.GL_CULL_FACE);
        //включаем сглаживание текстур, это пригодится в будущем
        GLES20.glHint(GLES20.GL_GENERATE_MIPMAP_HINT, GLES20.GL_NICEST);

        // шейдеры
        String vertexShaderCode=
                "uniform mat4 u_modelViewProjectionMatrix;"+
                        "attribute vec3 a_vertex;"+
                        "attribute vec3 a_normal;"+
                        "varying vec3 v_vertex;"+
                        "varying vec3 v_normal;"+
                        "void main() {"+
                        "v_vertex=a_vertex;"+
                        "vec3 n_normal=normalize(a_normal);"+
                        "v_normal=n_normal;"+
                        "gl_Position = u_modelViewProjectionMatrix * vec4(a_vertex,1.0);"+
                        "}";
        String fragmentShaderCode=
                "precision mediump float;"+
                        "uniform vec3 u_camera;"+
                        "uniform vec3 u_lightPosition;"+
                        "uniform sampler2D u_texture0;"+
                        "varying vec3 v_vertex;"+
                        "varying vec3 v_normal;"+
                        //функция преломления света
                        "vec3 myrefract(vec3 IN, vec3 NORMAL, float k){"+
                        // скалярное произведение нормали и вектора входящего луча
                        "float nv=dot(NORMAL,IN);"+
                        // квадрат длины входящего вектора
                        "float v2 = dot(IN,IN);"+
                        // коэффициент перед вектором нормали
                        "float knormal=(sqrt(((k*k+1.0)*v2)/(nv*nv)+1.0)-1.0)* nv;"+
                        // вектор исходящего луча
                        "vec3 OUT = IN + (knormal * NORMAL);"+
                        "return OUT;"+
                        "}"+
                        "void main() {"+
                        "vec3 n_normal=normalize(v_normal);"+
                        "vec3 lightvector = normalize(u_lightPosition - v_vertex);"+
                        "vec3 lookvector = normalize(u_camera - v_vertex);"+
                        "float ambient=0.1;"+
                        "float k_diffuse=0.7;"+
                        "float k_specular=0.3;"+
                        "float diffuse = k_diffuse * max(dot(n_normal, lightvector), 0.0);"+
                        "vec3 reflectvector = reflect(-lightvector, n_normal);"+
                        "float specular = k_specular * pow( max(dot(lookvector,reflectvector),0.0), 40.0 );"+
                        "vec4 one=vec4(1.0,1.0,1.0,1.0);"+
                        //цвет освещения
                        "vec4 lightColor=(ambient+diffuse+specular)*one;"+

                        //входящий вектор IN это (-lookvector)
                        //преломленный вектор OUT с показателем преломления 1.2
                        "vec3 OUT=myrefract(-lookvector, n_normal, 1.2);"+
                        //глубина дна
                        "float ybottom=-1.0;"+
                        //точка пересечения преломленного вектора и плоскости дна
                        "float xbottom=v_vertex.x+OUT.x*(ybottom-v_vertex.y)/OUT.y;"+
                        "float zbottom=v_vertex.z+OUT.z*(ybottom-v_vertex.y)/OUT.y;"+
                        //координаты текстуры
                        "vec2 texCoord = vec2(0.5*xbottom,0.5*zbottom);"+
                        //цвет текстуры, извлеченный из текстуры по координатам
                        "vec4 textureColor=texture2D(u_texture0, texCoord);"+
                        //цвет пикселя - комбинация цвета освещения и цвета текстуры
                        "gl_FragColor=lightColor*textureColor;"+
                        "}";


        //создадим текстуру
        mTexture0=new Texture(context,R.drawable.wtr);
        //создадим шейдерный объект
        mShader=new Shader(vertexShaderCode, fragmentShaderCode);
        //свяжем буфер вершин с атрибутом a_vertex в вершинном шейдере
        mShader.linkVertexBuffer(vertexBuffer);
        //свяжем буфер нормалей с атрибутом a_normal в вершинном шейдере
        mShader.linkNormalBuffer(normalBuffer);
        //связь атрибутов с буферами сохраняется до тех пор,
        //пока не будет уничтожен шейдерный объект

        //свяжем текстуру с шейдерным оьъектом
        mShader.linkTexture(mTexture0, null);


        //передаем в шейдерный объект матрицу модели-вида-проекции
        mShader.linkModelViewProjectionMatrix(modelViewProjectionMatrix);
        //передаем в шейдерный объект координаты камеры
        mShader.linkCamera(xСamera, yCamera, zCamera);
        //передаем в шейдерный объект координаты источника света
        mShader.linkLightSource(xLightPosition, yLightPosition, zLightPosition);


    }

    //метод, в котором выполняется рисование кадра
    public void onDrawFrame(GL10 unused) {
        //передаем в шейдерный объект матрицу модели-вида-проекции
        mShader.linkModelViewProjectionMatrix(modelViewProjectionMatrix);
        //передаем в шейдерный объект координаты камеры
        mShader.linkCamera(xСamera, yCamera, zCamera);
        //передаем в шейдерный объект координаты источника света
        mShader.linkLightSource(xLightPosition, yLightPosition, zLightPosition);

        //вычисляем координаты вершин
        getVertex();
        //вычисляем координаты нормалей
        getNormal();
        //очищаем кадр
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT | GLES20.GL_DEPTH_BUFFER_BIT);
        //рисуем поверхность
        GLES20.glDrawElements(GLES20.GL_TRIANGLE_STRIP, sizeindex,
                GLES20.GL_UNSIGNED_SHORT, indexBuffer);

        getfps(2000);


    }//конец метода


    ////////////////////////////////////////////////////////////////////////////
    private void getfps(int maxframe){
        if (countframe == 0) {
            time1 = System.currentTimeMillis();
        }
        countframe = countframe + 1;
        if (countframe > maxframe) {
            time2 = System.currentTimeMillis();
            timekadr = (float)(time2 - time1) / (float)maxframe;
            fps = 1000f / timekadr;
            //
            // сбрасываем счетчик кадров
            countframe = 0;
            //
            Log.d("fps","fps ="+fps+", timekadr="+ timekadr);
        }
        //

    }

}//конец класса
