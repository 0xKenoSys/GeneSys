//一个图形程序要用结构来表示一个长方形
struct rect {
    long llx;   /* X coordinate of lower-left corner */
    long lly;   /* Y coordinate of lower-left corner */ //变量名缩写可以用多个单词开头字母小写
    unsigned long width;    /* Width(in pixels) */   //how to show the rect in pixels?
    unsigned long height;   /* Height (in pixels) */
    unsigned color; /* Coding of color */
};

//可以声明一个struct rect类型的变量r，并将它的字段设置如下：
struct rect r;
r.llx = r.lly = 0;
r.color = 0xFF00FF;
r.width = 10;
r.height = 20;

//这里表达式r.llx就会选择结构r的llx字段
//另外，我们可以在一条语句中既声明变量又初始化它的字段：
struct rect r ={ 0, 0, 10, 20, 0xFF00FF };

//将指向结构的指针从一个地方传递到另一个地方，而不是复制它们，这是很常见的。例如，下面的函数计算长方形的面积，这里，传递给函数的就是一个指向长方形struct的指针
long area(struct rect *rp) {
    return (*rp).width * (*rp).height;  //居然可以直接return一个计算式子
}
//表达式(*rp).width间接引用了这个指针，并且选取所得结构的width字段，这里必须要用括号，因为编译器会将表达式*rp.width解释为* (rp.width)，而这是非法的。
//间接引用和字段选取结合起来使用非常常见，以至于C语言提供了一种替代的表示法->。即rp->width等价于表达式(*rp).width。例如，我们可以写一个函数，它将一个长方形逆时针旋转90度。


void rotate_left(struct rect *rp) {
    /* Exchange width and height */
    long t = rp->height;
    rp->height = rp->width; //这是啥操作？->是啥啊？答：间接引用和字段选取结合。可是具体是啥意思呢？
    rp->width = t;
    /* Shift to new lower-left corner */
    rp->llx -= t;   //-=是什么？
}
//C++和Java的对象比C语言中的结构要复杂精细得多，因为它们将一组可以被调用来执行计算的方法与一个对象联系起来。在C语言中，我们可以简单地把这些方法写成普通函数，就像上面所示的函数area和rotate_left

/* Struct{

float Long = 10;
float Short = 5;
float temp;
float *pr;
    *pr = Long;
    temp = Short;
    Short = *pr;
    Long = temp;
}   //这些是我尝试默写的。发现有void，而且struct包含在一个函数的()里，以及还有->的操作。每一步还得认真研究。明天要默写加仿写这一段。以及用GDB调试这一段代码。
*/



// Created by Madeleine on 2026/5/7.