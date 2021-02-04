import java.io.IOException;
import java.io.PrintWriter;
import java.util.concurrent.FutureTask;

public class FirstServlet extends javax.servlet.http.HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {

    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        PrintWriter pw = response.getWriter();
        FutureTask futureTask = new FutureTask();
        pw.println("<html>");
        /**
         *
         */
        pw.println("<h1> Hellow world! </h1>");
        pw.println("</html>");
        /***
         *
         */
    }
}
