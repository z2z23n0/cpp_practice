//
// Created by Zeno on 2019/10/29.
//


//虚表 虚函数

//虚函数 virtual 可以被重写的函数
//当派生类继承基类后，如果基类中含有虚函数，子类可以对虚函数执行重写（覆盖）,方法是写一个跟它完全相同的函数(函数名、参数列表、返回值都相同),
//就会覆盖掉原来的函数
//覆盖后，无论用基类指针还是派生类指针都会调用覆盖后的函数

//虚析构函数：
//所有的析构函数在底层的函数名都是相同的
//虚析构函数是用来解决子类对象转化为父类对象进行析构的问题的

//final:不能被继承的类或者不能被重写的虚函数
//override:声明子类的某个函数必须重写父类的某个虚函数（子类）

//虚继承:在继承时使用virtual关键字


//抽象类
//纯虚函数：只有接口，没有实现的函数。
//包含纯虚函数的类叫抽象类，抽象类不能定义对象。

//虚表
//虚表是一个二级函数指针，只要类中包含虚函数，就会在对象的头部包含一个虚表指针(vfptr)
//虚表相当于一个函数指针数组，里面存放的就是虚函数的地址
//当子类继承父类时，会继承虚表，当子类有新的虚函数时，会在虚表后面新增新的项，当子类重写父类的虚函数时，会把虚表中原有的某一项覆盖

//多重继承(了解)
//一个派生类可以来源于多个基类，多个基类之间用逗号隔开，并且要加权限说明（public\private）
//如果多个父类中有重名的成员，那么会产生二义，必须用父类名::的方式指明用谁的成员
//如果继承的多个父类中有多个虚表，那么子类将全部继承下来。如果子类出现了新的虚函数，那么会加在第一个虚表（第一个继承的父类的虚表）的后面，
//如果多个父类中含有相同的虚函数，子类重写后，将会只出现一个虚函数

//菱形继承、虚继承
//菱形继承-->B、C继承自A，D继承自B、C(某个类的两个父类拥有一个相同的父类)
//冗余性：这个类包含了两份爷爷类
//二义性：两个爷爷长得一样，分不清

//虚继承只用在菱形继承内
//虚继承可以解决菱形继承带来的问题
//含有一个虚基类指针(vbptr)，指向自己的基类，作用是可以描述自己的父类。当发现被继承的另一个父类中也有这么一个相同的虚基类时，两个基类
//就会合并，只保留一个

