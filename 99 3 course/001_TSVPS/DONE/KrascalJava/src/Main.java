import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// data structure to store graph edges
class Edge {//ребро
    int src, dest, length;

    Edge(int src, int dest, int length) {
        this.src = src;//source
        this.dest = dest;//destination
    }
};

// class to represent a graph object
class Graph {
    // A list of lists to represent adjacency list
    List<List<Integer>> adj = new ArrayList<>();// создал список списков интеджеров

    // Constructor to construct graph
    public Graph(List<Edge> edges) {
        // allocate memory for adjacency list
        for (int i = 0; i < edges.size(); i++) {
            adj.add(i, new ArrayList<>());//выделил память для каждого внутреннгео листа уже как аррэйлиста
        }

        // add edges to the undirected graph
        for (Edge current : edges) {   // allocate new node in adjacency List from src to dest
            adj.get(current.src).add(current.dest);
            // allocate new node in adjacency List from dest to src
             adj.get(current.dest).add(current.src);// Uncomment line 39 for undirected graph
        }
    }
}
class Main {
    // print adjacency list representation of graph
    private static void printGraph(Graph graph) {
        int src = 0;
        int n = graph.adj.size();
        while (src < n) {
            // print current vertex and all its neighboring vertices
            for (int dest : graph.adj.get(src)) {
                System.out.print("(" + src + " --> " + dest + ")\t");
            }

            System.out.println();
            src++;
        }
    }
    // Directed Graph Implementation in Java
    public static void main(String[] args) {
        // Input: List of edges in a directed graph (as per above diagram)
        List<Edge> edges = Arrays.asList(new Edge(0, 1, 10), new Edge(1, 2, 5),
                new Edge(2, 0, 3), new Edge(2, 1, 2), new Edge(3, 2, 5),
                new Edge(4, 5, 8), new Edge(5, 4, 2), new Edge(1, 5, 7),
                new Edge(1, 3, 8));

        // construct graph from given list of edges
        Graph graph = new Graph(edges);

        // print adjacency list representation of the graph
        printGraph(graph);
    }
}