public class Test2 {
    public static void main(String[] args) throws Exception {
        try {
            throw new FirstException();
        }
        finally {
            throw new SecondException();
        }
    }
}

class FirstException extends Exception {
}

class SecondException extends Exception {
}