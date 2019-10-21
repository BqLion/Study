package com.bqlion.After.DataStruct.Graph;

import com.bqlion.After.DataStruct.List.Iterator;
import com.bqlion.After.DataStruct.List.Node;
import com.bqlion.Before.DataStructure.Map.Vertex;

public interface Graph {
/********************field**********************************/
    public static final int UndirectedGraph = 0;
    public static final int DirectedGraph = 1;
/********************field**********************************/


/********************Constructor****************************/

/********************Constructor****************************/


/********************Method*********************************/
public int getType();
    //返回图的顶点数
    public int getVexNum();
    //返回图的边数
    public int getEdgeNum();
    //返回图的所有顶点
    public Iterator getVertex();
    //返回图的所有边
    public Iterator getEdge();
    //删除一个顶点 v
    public void remove(Vertex v);
    //删除一条边 e
    public void remove(Edge e);
    //添加一个顶点 v
    public Node insert(Vertex v);
    //添加一条边 e
    public Node insert(Edge e);
    //判断顶点 u、v 是否邻接,即是否有边从 u 到 v
    public boolean areAdjacent(Vertex u, Vertex v);
    //返回从 u 指向 v 的边,不存在则返回 null
    public Edge edgeFromTo(Vertex u, Vertex v);
    //返回从 u 出发可以直接到达的邻接顶点
    public Iterator adjVertexs(Vertex u);
    //对图进行深度优先遍历
    public Iterator DFSTraverse(Vertex v);
    //对图进行广度优先遍历
    public Iterator BFSTraverse(Vertex v);
    //求顶点 v 到其他顶点的最短路径
    public Iterator shortestPath(Vertex v);
    //求无向图的最小生成树,如果是有向图不支持此操作

/********************Method*********************************/


}
