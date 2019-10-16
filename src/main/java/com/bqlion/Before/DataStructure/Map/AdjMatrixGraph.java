package com.bqlion.Before.DataStructure.Map;
import com.bqlion.Before.DataStructure.List.SeqList;

/* *
 * Created by BqLion on 2019/5/11
 */
public class AdjMatrixGraph<E>implements GGraph<E> {
    protected SeqList<E> vertexlist;            //顺序表存储顶点
    protected int [][] adjmatrix;               //图的邻接矩阵
    private final int MAX_WEIGHT = Integer.MAX_VALUE;

    public AdjMatrixGraph(int n){
        this.vertexlist  = new SeqList<E>(n);
        this.adjmatrix = new int[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                this.adjmatrix[i][j] = (i == j) ? 0:MAX_WEIGHT;
    }
    public AdjMatrixGraph(E[] vertices,Edge[] edges){
        this(vertices.length);
        for(int i = 0; i < vertices.length;i++)
            insertVertex(vertices[i]);
        for(int j = 0; j < edges.length; j++)
            insertEdge(edges[j]);
    }

    public AdjMatrixGraph(SeqList<E>list,Edge[] edges){
        this(list.length());
        this.vertexlist = list;
        for(int j = 0;j < edges.length;j++)
            insertEdge(edges[j]);
    }

    public int vertexCount(){
        return this.vertexlist.length();
    }

    public E get(int i){
        return this.vertexlist.get(i);
    }

    public boolean insertVertex(E vertex){
        return this.vertexlist.add(vertex);
    }

    public boolean insertEdge(int i,int j,int weight){
        if(i >= 0 && i < vertexCount() && j >=0 && j < vertexCount() && i != j && adjmatrix[i][j] == MAX_WEIGHT){
            this.adjmatrix[i][j] = weight;
            return true;
        }
        return false;
    }

    public boolean insertEdge(Edge edge) {
        if(edge != null)
            return insertEdge(edge.start,edge.dest,edge.weight);
        return false;
    }

    public String toString(){
        String str = "顶点集合: " +  vertexlist.toString() + "\n";
        str += "领接矩阵： \n ";
        int n = vertexCount();
        for(int i = 0; i<n;i++){
            for(int j = 0;j < n; j++){
                if(adjmatrix[i][j] == MAX_WEIGHT)
                    str += " ∞";
                else
                str += "  " + adjmatrix[i][j];
            }
            str += "\n";
        }
        return str;
    }

    public boolean removeEdge(int i,int j){
        if(i >= 0 && i < vertexCount() && j >= 0 && j < vertexCount() && i!=j && this.adjmatrix[i][j] !=MAX_WEIGHT){
            this.adjmatrix[i][j] = MAX_WEIGHT;
            return true;
        }
        return false;
    }

    public boolean removeVertex(int v){
        int n = vertexCount();
        if(v >= 0 && v < n){
            this.vertexlist.remove(v);
            for(int i = v;i < n -1;i++)
                for(int j = 0; j <n; j++)
                    this.adjmatrix[i][j] = this.adjmatrix[i+1][j];

                for(int j = v;j < n-1;j++)
                    for(int i = 0; i< n-1;i++)
                        this.adjmatrix[i][j] = this.adjmatrix[i][j+1];
                    return true;
        }
        return false;
    }

}
