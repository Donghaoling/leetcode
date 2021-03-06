#include "stdafx.h"  
  
#include<iostream>  
#include<iomanip>  
using namespace std;  
  
int tile=0;  
int *(*board) = NULL;//定义指向指针的指针用于动态的创建用于存储骨牌号的数组  
  
int main()  
{  
    void chessBoard(int tr, int tc, int dr, int dc, int size);//声明函数  
    int tx=0,ty=0,dx,dy,zsize;//定义棋盘的左上角方格、特殊方格的行号和列号以及棋盘大小  
    cout<<"请输入特殊方格的行号、列号以及棋盘的大小\n";//其实用户输入  
    cin>>dx>>dy>>zsize;  
    /*********动态的创建二维数组**********/  
    board=new int *[zsize];  
    for(int i=0;i<zsize;i++)  
    {  
        board[i]=new int[zsize];  
    }  
    /*********动态创建数组结束************/  
    board[dx][dy]=0;//特殊方格用0填充  
    chessBoard(tx,ty,dx,dy,zsize);  
    //输出结果  
    for(int j=0;j<zsize;j++)  
    {  
        for(int m=0;m<zsize;m++)  
        {  
            cout<<setw(4)<<board[j][m];//用来控制输出间隔  
        }  
        cout<<endl;  
    }  
  
  
    system("pause");  
    free(board);  
    board = NULL;  
    return 0;  
}  
void chessBoard(int tr, int tc, int dr, int dc, int size)  
{  
    if (size == 1) return;  
    int t = tile++,  // L型骨牌号  
        s = size/2;  // 分割棋盘  
    // 覆盖左上角子棋盘  
    if (dr < tr + s && dc < tc + s)  
        // 特殊方格在此棋盘中  
        chessBoard(tr, tc, dr, dc, s);  
    else   
    {// 此棋盘中无特殊方格  
        // 用 t 号L型骨牌覆盖右下角  
        board[tr + s - 1][tc + s - 1] = t;  
        // 覆盖其余方格  
        chessBoard(tr, tc, tr+s-1, tc+s-1, s);  
    }  
    // 覆盖右上角子棋盘  
    if (dr < tr + s && dc >= tc + s)  
        // 特殊方格在此棋盘中  
        chessBoard(tr, tc+s, dr, dc, s);  
    else   
    {// 此棋盘中无特殊方格  
        // 用 t 号L型骨牌覆盖左下角  
        board[tr + s - 1][tc + s] = t;  
        // 覆盖其余方格  
        chessBoard(tr, tc+s, tr+s-1, tc+s, s);  
    }  
    // 覆盖左下角子棋盘  
    if (dr >= tr + s && dc < tc + s)  
        // 特殊方格在此棋盘中  
        chessBoard(tr+s, tc, dr, dc, s);  
    else   
    {// 用 t 号L型骨牌覆盖右上角  
        board[tr + s][tc + s - 1] = t;  
        // 覆盖其余方格  
        chessBoard(tr+s, tc, tr+s, tc+s-1, s);  
    }  
    // 覆盖右下角子棋盘  
    if (dr >= tr + s && dc >= tc + s)  
        // 特殊方格在此棋盘中  
        chessBoard(tr+s, tc+s, dr, dc, s);  
    else  
    {// 用 t 号L型骨牌覆盖左上角  
        board[tr + s][tc + s] = t;  
        // 覆盖其余方格  
        chessBoard(tr+s, tc+s, tr+s, tc+s, s);  
    }  
}  
