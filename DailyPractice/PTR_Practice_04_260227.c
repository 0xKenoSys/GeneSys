#include <stdio.h>

//第一步：定义最底层的函数
//这些函数接收int*，返回int

int add_ten(int *p) {return *p + 10;}   //这个return是在干嘛？return用于将计算结果交还给调用这个函数的人。
int add_twenty(int *p) {return *p +20;} //函数名本身就是函数的入口地址
int add_thirty(int *p) {return *p + 30;}
int add_forty(int *p) {return *p + 40;}
int add_fifty(int *p) {return *p + 50;}

//第二步：定义一个包含5个底层函数指针的数组（全局：定义在函数之外，整个程序运行期间它一直存在于内存的数据段中）（）
int (*g_func_array[5])(int *) = {add_ten, add_twenty, add_thirty, add_forty, add_fifty};
//什么是(int *)？(int *)就是指向整型数据的指针类型。*代表指针，本质上是个内存地址。(int *)表示：这是一个地址，顺着这个地址找过去，内存里存着一个整数
//主要出现在两种情景里：
//1.作为函数的参数类型：在函数声明里，比如int add_ten(int *p)，意思是：请不要直接传给我一个具体的数字，而是把存放这个数字的内存地址给我。末尾的(int *)指的是那个底层函数需要接收一个整数的地址作为参数
//2.作为强制类型转换(type casting)：把(int *)放在一个变量或者数值前面，表示不管它原来是什么类型，现在请把它当成一个指向整数的地址来看待。比如在使用malloc分配内存时最常见：
//malloc分配完内存后，返回的是通用的无类型指针(void *)，我们在前面加上(int *)把它强制转换成整型指针，然后才能赋值给int指针变量p。int *p = (int *)malloc(sizeof(int));

//这个“传”是什么意思，和赋值有什么区别
//传递参数。分两种类型：数值和地址

//第三步：定义一个函数，接收int*，并返回上面那个数组的指针
//它的返回类型是：指向“包含5个函数指针的数组”的指针
int (*(*get_array_ptr(int *flag))[5])(int *){   //*get_array_ptr(int *flag) 也是在定义指针类型是个指向整型变量的指针吧？那这个指针名是什么意思？//这是一个函数，接收一个整型指针作为参数。不是指针名。这个函数的返回值类型是“指向数组的指针”，而不是指向整型变量的指针。
                                                //前面有个*：这个函数返回一个指针。//[5]:包含5个元素的数组的指针。//int(*...)(int *)：那个数组的元素，是接收int*返回的int函数指针 //右左法则：以名字（唯一真身）为中心，向右看是否有[]和()，再向左看有没有*，这些（*、()、[]、int）是修饰名字的类型修饰符，=把右边的值装进真身的盒子
    printf("[Log] get_array_ptr被调用，传入的flag值为：%d\n", *flag);
    //返回全局数组的地址  //什么是全局数组的地址？//&g_func_array的作用是获取这一整块包括5个函数指针的数组的起始内存地址，然后作为函数的返回值交出去
    return &g_func_array;
}

int main() {
    printf("开始测试终极复杂指针\n\n");

//第四步：终于轮到主角登场
    //声明题图中的复杂指针pfunc，并让它指向我们刚刚定义的get_array_ptr函数
    int (*(*(*pfunc)(int *))[5])(int *) = get_array_ptr;    //这个嵌套是什么含义？//pfunc是一个指针，它指向一个函数get_array_ptr，这个函数执行后返回一个指针，这个返回的指针指向一个元素为5个的数组g_func_array，这个数组里装的是指针，指向函数：接收int *并返回int的函数。就是add_ten,add_twenty,add_thirty,add_forty,add_fifty这五个函数。指向get_array_ptr这个函数。接收：进料口。返回：出货口。看int add_ten(int *p)，括号里要进料int *（接收），左边是一个int（返回）

    int flag = 99;
    int value = 5;
    //法一：一步步拆解调用
    printf("1.分步调用演示：\n");
    //（1）调用pfunc指向的函数，得到一个指向数组的指针
    int(*(*array_ptr)[5])(int *) = pfunc(&flag); //函数执行后，返回了全局数组的地址

    //（2）遍历调用数组里的函数
    for (int i = 0; i < 5; i++) {
        //(*array_ptr)先解引用拿到数组本身
        //[i]拿到第i个函数指针
        //(&value)传入参数执行函数
        int result = (*array_ptr)[i](&value);
        printf("调用数组第%d个函数，计算%d的结果：%d\n", i, value, result);
    }

    //法二：终极“一行流”调用（炫技版）
    printf("\n2.一行流调用：\n");
    //解析：
    //pfunc(&flag)  ->执行函数，返回数组指针
    //*(pfunc(&flag))   ->解引用，得到数组本身
    //(*(pfunc(&flag)))[2]  ->取数组第二个元素(add_thirty)函数
    //(...)(&value) ->传入&value执行
    int ultimate_result = (*(pfunc(&flag)))[2](&value); //pfunc(&flag):呼叫get_array_ptr。 //*(pfunc(&flag)):打开g_func_array。//(*(pfunc(&flag)))[2]：打开数组第三个抽屉，里面有add_thirty的地址 //(*(pfunc(&flag)))[2](&value)把value交给add_thirty处理
    printf("直接调用(*(pfunc(&flag)))[2](&value)的结果是：%d\n", ultimate_result);

    return 0;
}

//如果在公司的代码库里写int (*(*(*pfunc)(int *))[5])(int *);会被同事追着打。在实际工程中，为了可读性，要用typedef一层层剥开
//1.定义底层函数指针类型（接收int * ，返回int）
//typedef int (*BaseFuncPtr)(int *);

//2.定义包含5个底层函数指针的数组类型
//typedef BaseFuncPtr FuncArray[5];

//3.定义指向这个数组的指针类型
//typedef FuncArray* PtrToFuncArray;

//4.定义题图中那个终极的函数指针类型（接收int *，返回PtrToFuncArray）
//typedef PtrToFuncArray(*TheUltimateFuncPtr)(int *);

//现在声明pfunc就变得极其优雅了：
//TheUltimateFuncPtr pfunc = get_array_ptr;


//
// Created by Madeleine on 2026/2/27.