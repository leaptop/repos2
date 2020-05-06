package com.example.lab01_1;

import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.TextView;

import java.text.ParseException;

public class MainActivity extends AppCompatActivity {
    private double result = 0;
    private double a = 0;
    private double b = 0;
    private int operationNum = 0;


    public void pressed7() {
//        TextView tw = (TextView) findViewById(R.id.textView2) ;
//        tw.setText("7");
//        TextView textView = new TextView(this);
//        textView.setText("Hey, one more TextView");
        //System.out.println("pressed 7");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        add7();
        add8();
        add9();
        clear();
        addDiv();
        equals();
        add4();
        add5();
        add6();
        add1();
        add2();
        add3();
        add0();
        mul();
        plus();
        minus();




    }


    private void add7() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button7);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "7");
            }
        });
    }

    private void add8() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button8);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "8");
            }
        });
    }

    private void add9() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button9);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "9");
            }
        });
    }

    private void clear() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.buttonClear);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText("");
            }
        });
    }




    private void add4() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button4);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "4");
            }
        });
    }

    private void add5() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button5);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "5");
            }
        });
    }

    private void add6() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button6);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "6");
            }
        });
    }
    private void add1() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button1);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "1");
            }
        });
    }

    private void add2() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button2);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "2");
            }
        });
    }

    private void add3() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button3);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "3");
            }
        });
    }
    private void add0() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.button0);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tw.setText(tw.getText() + "0");
            }
        });
    }
    private void mul() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.buttonMul);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    a = Double.parseDouble(tw.getText().toString());
                }
                catch( NumberFormatException e){
                    tw.setText("not a number");
                }
                tw.setText("");
                operationNum = 1;
            }
        });
    }
    private void plus() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.buttonPlus);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    a = Double.parseDouble(tw.getText().toString());
                }
                catch(NumberFormatException e){
                    tw.setText("not a number");
                }
                tw.setText("");
                operationNum = 2;
            }
        });
    }
    private void minus() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.buttonMinus);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    a = Double.parseDouble(tw.getText().toString());
                }
                catch(NumberFormatException e){
                    tw.setText("not a number");
                }
                tw.setText("");
                operationNum = 3;
            }
        });
    }
    private void addDiv() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.buttonDiv);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    a = Double.parseDouble(tw.getText().toString());
                }
                catch(NumberFormatException e){
                    tw.setText("not a number");
                }

                tw.setText("");
                operationNum = 0;
            }
        });
    }
    private void equals() {
        final TextView tw = (TextView) findViewById(R.id.textView2);
        Button ctb = (Button) findViewById(R.id.buttonEquals);
        ctb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    b = Double.parseDouble(tw.getText().toString());
                }
                catch(NumberFormatException e){
                    tw.setText("not a number");
                }

                try{
//                    if (b == 0.0 && operationNum == 0) {
//                        tw.setText("can't divide by zero");
//                    } else
                    if(operationNum == 0){
                        result = a / b;
                        tw.setText(String.valueOf(result));
                    }
                    else if(operationNum == 1){
                        result = a * b;
                        tw.setText(String.valueOf(result));
                    }
                    else if(operationNum == 2){
                        result = a + b;
                        tw.setText(String.valueOf(result));
                    }
                    else if(operationNum == 3){
                        result = a - b;
                        tw.setText(String.valueOf(result));
                    }

                }catch(ArithmeticException e) {
                    tw.setText("wrong math");
                }


            }
        });
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
