#include <immintrin.h>
#include <iostream>
using namespace std;

void add(float *a, float *b, float *c)
{
   int i;
   for (i = 0; i < 4; i++) {
       c[i] = a[i] + b[i];
    }
}

void add2(float *a, float *b, float *c)
{
    __m128 t0, t1;
    t0 = _mm_load_ps(a);//载入数据到寄存器
    t1 = _mm_load_ps(b);//载入数据到寄存器
    t0 = _mm_add_ps(t0, t1);
    _mm_store_ps(c, t0);//将数据从寄存器写入到内存变量里面
}


int main()
{
	cout<<"Hello World"<<endl;
	float a[4] = {1,2,3,4};
	float b[4] = {0.1,0.2,0.3,0.4};
	float c[4] = {0,0,0,0};
	// add(a,b,c);
	// for(int i=0;i<3;i++)
	// {
	// 	cout<<c[i]<<endl;
	// }
	add2(a,b,c);
	for(int i=0;i<3;i++)
	{
		cout<<c[i]<<endl;
	}
	return 0;
}