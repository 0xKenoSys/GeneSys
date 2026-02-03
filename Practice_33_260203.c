#include <stdio.h>
#include <stdlib.h>
#define _PAUSE() system("pause");
#if(defined DEBUG) || (defined _DEBUG)
#define _DEBUGNOW
#define _PUTSIL(NUM) printf("%d\n", NUM)
#define _PUTFD(NUM) printf("%f\n", NUM)\
    #else
#define _PUTSIL(NUM)((void)0)
#define _PUTFD(NUM)((void)0)

int main() {
#ifdef _DEBUGNOW
    printf("正在为调试做准备...\n");
#endif
    printf("程序正在运行...\n");
    _PUTSIL(12666);
    _PUTFD(3.1415926535898);
    printf("程序运行完毕...\n");
    _PAUSE();
    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//


//
//  函数： Convert2Jpeg(wchar_t*, wchar_t, int)
//
//  目的： 转换图片到 Jpeg 格式
//
//  orgiPath:   源文件路径
//  destPath:   目标路径
//  quality:    图像质量
//

bool Convert2Jpeg(wchar_t* orgiPath, wchar_t*destPath, int quality) {
    return true;
}









