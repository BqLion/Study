package com.bqlion.After.DataStruct.Graph;
/* *
 * Created by BqLion on 2019/5/14
 */

/**
 * 领接表表示的图是用一个顺序表存储的 vertex表示
 * 其中vertex 由 data（节点） + 循环链表（边）构成。
 */

/**
public class AdjListGraph<E>implements GGraph<E>{
    protected SeqList<Vertex<E>>vertexlist;

    public void AdjMatrixGraph(int n){
        this.vertexlist = new SeqList<Vertex<E>>(n);
    }

    public AdjListGraph(E[] vertices,Edge[] edges){     //直接用顶点和边的数组来构造图
        for(int i = 0; i < vertices.length;i++)
            insertVertex(vertices[i]);
        for(int j = 0; j < edges.length;j++)
            insertEdge(edges[j]);
    }

    public int vertexCount(){
        return this.vertexlist.length();
    }

    public E get(int i){
        return this.vertexlist.get(i).data;
    }

    public boolean insertVertex(E vertex){
        return this.vertexlist.add(new Vertex<E>(vertex));
    }

    public boolean insertEdge(int i,int j,int weight){
        if(i >=0 && i < vertexCount() && j >=0 && j <vertexCount() && i != j){
            HSLiinkedList slink = this.vertexlist.get(i).adjlink;
            return slink.add(new Edge(i,j,weight));         //领接表表示法的边的插入就是直接在slinklist队列尾插入
        }
        return false;
    }

    public boolean insertEdge(Edge edge){
        if(edge != null)
            return insertEdge(edge.start,edge.dest,edge.weight);
        return false;
    }

    public String toString(){
        String str = "顶点集合 ：" + vertexlist.toString() + "\n";
        str += "边表格 ：  \n";

        for(int i = 0; i <vertexCount(); i++)
            str += this.vertexlist.get(i).adjlink.toString() + "\n";
        return str;
    }

    public boolean removeEdge(int i,int j){
        if(i >= 0 && i < vertexCount() && j >=0 && j < vertexCount() && i != j){
            HSLiinkedList<Edge>slink = this.vertexlist.get(i).adjlink;

            return slink.remove(new Edge(i,j,1));
        }
        return false;
    }

    public boolean removeVertex(int v) {     //删除序号为V的顶点和相关的边。
        int n = vertexCount();
        if (v >= 0 && v < n) {
            HSLiinkedList<Edge> slink = this.vertexlist.get(v).adjlink;//把所有的边都拿出来过一遍，对称删除

            int i = 0;
            Edge edge = slink.get(i);
            while (edge != null) {
                this.removeEdge(edge.dest, edge.start);
                i++;
                edge = slink.get(i);
            }
            this.vertexlist.remove(v);

            for (i = 0; i < n - 1; i++) {
                slink = this.vertexlist.get(i).adjlink;
                int j = 0;
                edge = slink.get(j);
                while (edge != null) {
                    if (edge.start > v)
                        edge.start--;
                    if (edge.dest > v)
                        edge.dest--;
                    j++;
                    edge = slink.get(j);
                }
            }
                return true;
            }
            return false;
        }


        public int getFirstNeighbor(int v){
            return getNextNeighbor(v,-1);
        }

        public int getNextNeighbor(int v,int w){
            if(v >= 0 && v < vertexCount() && w >= -1 && w < vertexCount()){
                HSLiinkedList<Edge>slink = this.vertexlist.get(v).adjlink;

                Edge edge = slink.get(0);
                int i = 0;
                while(edge != null){
                    if(edge.dest > w)
                        return edge.dest;
                    i++;
                    edge= slink.get(i);
                }
            }
            return -1;
        }
    }
*/



