public class GraphMatrixWeight {
    public int[][] adj; // 重み行列
    public int numV; // 頂点の数

    // コンストラクタ 初期化
    public GraphMatrixWeight(int numV) {
        this.numV = numV; // インスタンス変数numVに，引数 numVの値を代入．
        adj = new int[numV][numV]; // 重み行列の初期化
    }

    // 有向辺の追加
    public void addEdge(int i, int j, int weight) {
        adj[i][j] = weight; // 頂点iから頂点jへの有向辺に重みを追加
    }

    // 行列の表示
    public void printG() {
        StringBuilder s = new StringBuilder();
        // StringBuilder クラスは文字列を効率的に操作でき、文字列の結合や変更などの操作を高速に行える．
        for (int i = 0; i < numV; i++) {
            s.append(i + ": "); // 頂点の番号を追加
            // 重み行列の各要素に対して処理
            for (int j : adj[i]) {
                s.append(j + " "); // 重みを文字列に追加
            }
            s.append("\n"); // 行末に改行を追加
        }
        System.out.println(s); // 構築した文字列をコンソールに出力
    }
}
