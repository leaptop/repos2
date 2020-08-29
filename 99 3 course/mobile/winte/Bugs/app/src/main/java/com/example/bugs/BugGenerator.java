package com.example.bugs;

import java.util.Random;

public class BugGenerator extends Thread {
    private boolean isAlive = false;

    private GameView view;
    private final Random rnd = new Random();

    BugGenerator(GameView view) {
        this.view = view;
    }

    @Override
    public void run() {
        while (isAlive) {
            if (view.getCountBugs() < 7) {
                switch (rnd.nextInt(3)) {
                    case 0:
                        Bug bigbug = new Bug(view, R.drawable.bigbug, 0.1, 5, 1);
                        new Thread(bigbug).start();
                        view.bugs.add(bigbug);

                        break;

                    case 1:
                        Bug fastbug = new Bug(view, R.drawable.fastbug, 0.02, 15, 5);
                        new Thread(fastbug).start();
                        view.bugs.add(fastbug);

                        break;

                    case 2:
                        Bug middlesizebug = new Bug(view, R.drawable.middlesizebug, 0.1, 10, 3);
                        new Thread(middlesizebug).start();
                        view.bugs.add(middlesizebug);

                        break;
                }
            }

            try {
                Thread.sleep(1000 / (8 - view.getCountBugs()));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        for (Bug bug : view.bugs) {
            bug.setAlive(false);
        }

        view.bugs.clear();
    }

    void setAlive(boolean statue) {
        isAlive = statue;
    }
}
