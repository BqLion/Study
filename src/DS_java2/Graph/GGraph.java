package com.bqlion.After.DataStruct.Graph;

/**
 * 图里边的元素用唯一确定的标识符标注。
 *
 */
/* *
 * Created by BqLion on 2019/5/10
 */
public interface GGraph<E> {
    int vertexCount();
    E get(int i);
    boolean insertVertex(E vertex);
    boolean insertEdge(int i, int j, int weight);
    boolean removeVertex(int v);
    boolean removeEdge(int i, int j);
}
