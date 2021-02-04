package com.example.trafficlight;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity {
    private LinearLayout b_1, b_2, b_3;
    private boolean startStop = true;
    private Button button1;
    private int counter = 0;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b_1 = findViewById(R.id.bulb_1);
        b_2 = findViewById(R.id.bulb_2);
        b_3 = findViewById(R.id.bulb_3);
        button1 = findViewById(R.id.button1);
        //b_1.setBackgroundColor(Color.BLACK);
    }

    public void onClickStart(View view) {
        if (!startStop) {
            button1.setText(("Stop"));
            startStop = true;//типа чтобы только один раз запускался код(cоздавался поток)
            new Thread(new Runnable() {
                @Override
                public void run() {
                    while (startStop) {
                        counter++;
                        switch (counter) {
                            case 1:
                                b_1.setBackgroundColor(getResources().getColor(R.color.red));
                                b_2.setBackgroundColor(getResources().getColor(R.color.grey));
                                b_3.setBackgroundColor(getResources().getColor(R.color.grey));
                                break;
                            case 2:
                                b_1.setBackgroundColor(getResources().getColor(R.color.grey));
                                b_2.setBackgroundColor(getResources().getColor(R.color.yellow));
                                b_3.setBackgroundColor(getResources().getColor(R.color.grey));
                                break;
                            case 3:
                                b_1.setBackgroundColor(getResources().getColor(R.color.grey));
                                b_2.setBackgroundColor(getResources().getColor(R.color.grey));
                                b_3.setBackgroundColor(getResources().getColor(R.color.green));
                                counter = 0;
                                break;
                        }
                        try {
                            Thread.sleep(00);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }).start();
        } else {
            startStop = false;
            button1.setText(("Start"));

        }


    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        startStop = false;
    }
}
