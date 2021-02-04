package com.example.phong;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;

import android.opengl.Matrix;
import android.os.SystemClock;

import static android.opengl.GLES20.GL_FRAGMENT_SHADER;
import static android.opengl.GLES20.GL_VERTEX_SHADER;


public class MyGL20Renderer implements GLSurfaceView.Renderer {

	private static Context context;
	public volatile float mXAngle;
	public volatile float mYAngle;
	public volatile float mZoom;

	private final static long TIME = 15000;
	private final float[] mVMatrix = new float[16];
	private final float[] mProjMatrix = new float[16];
	private final float[] mNormalMatrix = new float[16]; 
	private final float[] mMVPMatrix = new float[16];
	private final float[] mRotationMatrixX = new float[16];
	private final float[] mRotationMatrixY = new float[16];
	private final float[] mPVMatrix = new float [16];
	private final float[] mTempMatrix = new float[16];
	private final float[] mMVMatrix = new float[16];

	private Sphere sphere;

	public MyGL20Renderer(Context context) {
		this.context = context;
	}

	//для установки параметров состояния OpenGL и для загрузки текстур из графических файлов (вызывается при создании экрана)
	@Override
	public void onSurfaceCreated(GL10 unused, EGLConfig cfg) {
		
		GLES20.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		GLES20.glEnable(GL10.GL_DEPTH_TEST);
	    GLES20.glDepthFunc(GL10.GL_LEQUAL);
	    
	    mZoom = -5f; //удаление сферы от нас
		sphere = new Sphere(1, 10, 40); //создаем сферу, если поставить мальенкий longs будет квадрат и r и lats маленькие, сфера не нарисуется

	}

	// метод, вызываемый перед отрисовкой кадра, здесь в основном располагается вся реализация для отображения какого либо объекта
	@Override
	public void onDrawFrame(GL10 unused) {
		GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT|GLES20.GL_DEPTH_BUFFER_BIT);

		Matrix.setLookAtM(mVMatrix, 0, 0, 0, mZoom, 0f, 0f, 0f, 0f, 1.0f, 0.0f);

		Matrix.multiplyMM(mPVMatrix, 0, mProjMatrix, 0, mVMatrix, 0);

		Matrix.setRotateM(mRotationMatrixX,  0,  mXAngle,  0,  1.0f,  0f);

		Matrix.setRotateM(mRotationMatrixY, 0, mYAngle, 1.0f, 0, 0);

		Matrix.multiplyMM(mTempMatrix,  0,  mPVMatrix, 0, mRotationMatrixX,  0);
		Matrix.multiplyMM(mMVPMatrix, 0, mTempMatrix, 0, mRotationMatrixY, 0);

		Matrix.multiplyMM(mTempMatrix, 0, mVMatrix, 0, mRotationMatrixX, 0);
		Matrix.multiplyMM(mMVMatrix, 0, mTempMatrix, 0, mRotationMatrixY, 0);

		Matrix.invertM(mTempMatrix, 0, mMVMatrix, 0);
		Matrix.transposeM(mNormalMatrix, 0, mTempMatrix, 0);
		drawBalls();
	}

	// принято определять область просмотра на экране и задавать параметры проекции трехмерного изображения на экран
	@Override
	public void onSurfaceChanged(GL10 unused, int width, int height) {
		GLES20.glViewport(0, 0, width, height);
		float ratio = (float) width / height;
		Matrix.frustumM(mProjMatrix, 0, -ratio, ratio, -1, 1, 1, 20);
	}

	//Использование glCreateShaderProgram считается эквивалентным как компиляции шейдера, так и операции связывания программы.
	//Поскольку он выполняет и то, и другое одновременно, могут возникнуть ошибки компилятора или компоновщика.
	// Однако, поскольку эта функция возвращает только программный объект, ошибки типа компилятора будут сообщаться как ошибки компоновщика через следующий API.
	public static int createShaderProgram() {
		int vertexShaderId = ShaderUtils.createShader(context, GL_VERTEX_SHADER, R.raw.vertex_shader);
		int fragmentShaderId = ShaderUtils.createShader(context, GL_FRAGMENT_SHADER, R.raw.fragment_shader);
		int programId = ShaderUtils.createProgram(vertexShaderId, fragmentShaderId);
		return programId;
	}
		
	private void drawBalls() {
		float[] scalerMatrix = new float[16];
		float[] finalMVPMatrix = new float[16];
		float[] tempMatrix = new float[16];

		createViewMatrix();
		setModelMatrix();

		Matrix.setIdentityM(scalerMatrix, 0); //сбрасываем model матрицу
		Matrix.scaleM(scalerMatrix, 0, 3.2f, 3.2f, 1.5f); //задают коэффициент сжатия по каждой оси
		Matrix.multiplyMM(tempMatrix, 0, mMVPMatrix, 0, scalerMatrix, 0); //Умножает две матрицы 4x4 вместе и сохраняет результат в третьей матрице 4x4 матрица.

		//Метод translateM настраивает матрицу на перемещение
		//В нем мы указываем model матрицу и нулевой отступ
		Matrix.translateM(finalMVPMatrix, 0, tempMatrix, 0, 0.0f, 0.0f, 2f); //положение в пространстве (xyz) Offset(смещение)
		sphere.draw(finalMVPMatrix, mNormalMatrix, mVMatrix);
		setModelMatrix();
	}

	private void setModelMatrix() {
		//float angle = (float)(SystemClock.uptimeMillis() % TIME) / TIME * 360;
		//Matrix.rotateM(mNormalMatrix, 0, angle, 0, 1, 1);
	}

	//Здесь происходит движение пучка этого
	private void createViewMatrix() {

		float time = (float)(SystemClock.uptimeMillis() % TIME) / TIME; //используем рандом для вращения луча освещения
		float angle = time  *  2 * 3.1415926f;


		float eyeX = 0f;
		float eyeY = 0f;
		float eyeZ = 0f;

		//если в X и Z поставить константы, пучок света будет рассеиваться при вращении в некуоторых местах.
		eyeX = (float) (Math.cos(angle) * 4f);
		eyeY = 1f;
		eyeZ = (float) (Math.sin(angle) * 4f);

		//если поставить большие значения (>3) пучок будет за сферу уходить, при =0 небольшой радиус движения пучка будет
		float centerX = 1.5f;
		float centerY = 1.5f;
		float centerZ = 1.5f;

		//движение пучка по координатам xyz
		float upX = 0.5f;
		float upY = 0.5f;
		float upZ = 0;

		//Определяет преобразование просмотра в терминах точки зрения, Центра зрения и вектора вверх.
		Matrix.setLookAtM(mVMatrix, 0, eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	}
}
