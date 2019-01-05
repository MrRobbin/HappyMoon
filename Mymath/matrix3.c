#include "matrix3.h"

/**********************************************************************************************************
*函 数 名: Matrix3_Add
*功能说明: 3维矩阵加法: c=a+b
*形    参: 矩阵a 矩阵b 矩阵c
*返 回 值: 无
**********************************************************************************************************/
void Matrix3_Add(float *a,float *b,float *c)
{
    uint8_t i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            c[i*3+j] = a[i*3+j] + b[i*3+j];
        }
    }
}

/**********************************************************************************************************
*函 数 名: Matrix3_Sub
*功能说明: 3维矩阵减法: c=a-b
*形    参: 矩阵a 矩阵b 矩阵c
*返 回 值: 无
**********************************************************************************************************/
void Matrix3_Sub(float *a,float *b,float *c)
{
    uint8_t i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            c[i*3+j] = a[i*3+j] - b[i*3+j];
        }
    }
}

/**********************************************************************************************************
*函 数 名: Matrix3_Mul
*功能说明: 3维矩阵乘法: c=a×b
*形    参: 矩阵a 矩阵b 矩阵c
*返 回 值: 无
**********************************************************************************************************/
void Matrix3_Mul(float *a,float *b,float *c)
{
    uint8_t i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            c[i*3+j] = a[i*3+0] * b[0*3+j] + a[i*3+1] * b[1*3+j] + a[i*3+2] * b[2*3+j];
        }
    }
}

/**********************************************************************************************************
*函 数 名: Matrix3_Copy
*功能说明: 3维矩阵复制： b=a
*形    参: 矩阵a 矩阵b
*返 回 值: 无
**********************************************************************************************************/
void Matrix3_Copy(float *a, float *b)
{
    uint8_t i;
    for(i=0; i<9; i++)
    {
        b[i] = a[i];
    }
}

/**********************************************************************************************************
*函 数 名: Matrix3_Tran
*功能说明: 3维矩阵求转置
*形    参: 矩阵a 矩阵b
*返 回 值: 无
**********************************************************************************************************/
void Matrix3_Tran(float *a, float *b)
{
    b[0] = a[0];
    b[1] = a[3];
    b[2] = a[6];
    b[3] = a[1];
    b[4] = a[4];
    b[5] = a[7];
    b[6] = a[2];
    b[7] = a[5];
    b[8] = a[8];
}

/**********************************************************************************************************
*函 数 名: Matrix3_Det
*功能说明: 3维矩阵求逆 b= aˉ1
*形    参: 矩阵a 矩阵b
*返 回 值: 无
**********************************************************************************************************/
void Matrix3_Det(float *a,float *b)
{
    float det;

    det = a[0] * a[4] * a[8]
          + a[1] * a[5] * a[6]
          + a[2] * a[3] * a[7]
          - a[2] * a[4] * a[6]
          - a[5] * a[7] * a[0]
          - a[8] * a[1] * a[3];

    b[0] = (a[4] * a[8] - a[5] * a[7]) / det;
    b[1] = (a[2] * a[7] - a[1] * a[8]) / det;
    b[2] = (a[1] * a[7] - a[4] * a[6]) / det;

    b[3] = (a[5] * a[6] - a[3] * a[8]) / det;
    b[4] = (a[0] * a[8] - a[2] * a[6]) / det;
    b[5] = (a[2] * a[3] - a[0] * a[5]) / det;

    b[6] = (a[3] * a[7] - a[4] * a[6]) / det;
    b[7] = (a[1] * a[6] - a[0] * a[7]) / det;
    b[8] = (a[0] * a[4] - a[1] * a[3]) / det;
}





