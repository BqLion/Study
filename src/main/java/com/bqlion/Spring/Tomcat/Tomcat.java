package com.bqlion.Spring.Tomcat;

/* *
 * Created by BqLion on 2019/6/18
 */

/**
 *  1.TOMCAT 是提供能让别人访问自己写的页面的一个程序
 *
 *      (1).webapps文件夹
 *            新建文件夹web2{
 *                WEB-INF文件夹
 *                helloworld.html文件
 *                          }
 *            便可在localhost8080/web2中访问helloworld主页
 *
 *      (2).虚拟目录
 *          若把所有webapp都放在一个文件夹不易维护，空间也可能不够。
 *              虚拟映射：
 *                  a.在其他盘符创建例如web文件夹{
 *                       WEB-INFO文件夹
 *                       helloworld.html文件
 *                                              }
 *                  b.在tomcat/conf/server.xml 中的<Host>节点添加
 *                         <Context path="/web1" docBase="D:\web1"/>
 *                              Context path:项目名
 *                              docBase：站点目录的绝对路径
 *
 *
 *
 *
 *
 *
 */
