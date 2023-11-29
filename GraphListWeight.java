import java.util.LinkedList;

public class GraphListWeight {
    int numV;
    LinkedList<Edge>[] adj; // Edgeクラスをもつリストを作る

    // Edgeクラスの定義
    public static class Edge {
        int node;
        int next;
        int weight;

        // コンストラクタ
        public Edge(int node, int next, int weight) {
            this.node = node;
            this.next = next;
            this.weight = weight;
        }
    }

    // コンストラクタ
    public GraphListWeight(int numV) {
        this.numV = numV;
        adj = new LinkedList[numV];
        for (int i = 0; i < numV; i++) {
            adj[i] = new LinkedList<Edge>(); // 初期化
        }
    }

    // addEdgeメソッド
    public void addEdge(int node, int next, int weight) {
        Edge edge = new Edge(node, next, weight); // Edgeクラスのインスタンスを作成
        adj[node].add(edge); // 隣接リストにEdgeクラスのインスタンスを加える
    }

    // printGメソッド
    public void printG() {
        for (int i = 0; i < numV; i++) {
            LinkedList<Edge> list = adj[i];
            System.out.print(i);
            for (int j = 0; j < list.size(); j++) {
                Edge edge = list.get(j);
                System.out.print(" -> " + edge.next + ":" + edge.weight);
            }
            System.out.println();
        }
    }
}
