package com.bqlion.study.Polymorphism;
import java.util.*;

public interface RandVals {
    int rint = (int)(Math.random() * 10);
    long rlong = (long)(Math.random() * 10);
    float rfloat = (float)(Math.random() * 10);
    double rdouble = Math.random() * 10;
}
//均为默认的static 字段
