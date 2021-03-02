class Base {
    void method1() {
    }

    void method2() {
    }
}

class AAA { // нормальный класс

    static class B {
    } // статический вложенный класс

    class C {
    } // внутренний класс

    void f() {
        class D {
        } // локальный внутренний класс
    }

    void g() {
        // анонимный класс
        Base bref = new Base() {
            void method1() {
            }
        };
    }
}