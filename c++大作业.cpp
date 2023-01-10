#include<iostream>
#include <fstream>
using namespace std;
//=================================基类_商品==================================
class good
{
public:
    good(int price1, int num1, string region1, int inprice);
    virtual ~good();//析构函数写成虚函数

    virtual void subgood(int howmany) {
        num -= howmany;
        cout << "某商品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << "某商品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << "商品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << "商品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << "商品的产地是：" << region << endl;
    }
    int price;//商品的价格
    int num;//数量
    string region;//产地 区域
private:
    int inprice;//进货价格
};

good::good(int price1, int num1, string region1, int inprice1)
{
    price = price1;
    num = num1;
    region = region1;
    inprice = inprice1;
}

good::~good()
{
    cout << "某商品已经下架" << endl;
}
//===================================基类_商品（上面）============================================
//===================================派生1_电子产品（下面）=====================================
class electronics :public good
{
public:
    electronics(int price1, int num1, string region1, int inprice1, int power_dissipation1, int watt1) :good(price1, num1, region1, inprice1) {
        power_dissipation = power_dissipation1;
        watt = watt1;//做普通的初始化
    }
    virtual void getpower() {
        cout << "电器的续航为：" << power_dissipation << "瓦特" << endl;
    }
    virtual void getwatt() {
        cout << "充电器功耗为：" << watt << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << "某电器库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << "某电器进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << "某电器的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << "某电器的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << "某电器的产地是：" << region << endl;
    }
    virtual ~electronics();
    int power_dissipation;//功耗
    int watt;//充电器多少瓦特
private:

};

electronics::~electronics()
{
    cout << "某电器已下架" << endl;//写的是虚函数，因此是
}

//===================================派生1-1_电脑（下面）=================================
class computer : public electronics
{
public:
    computer(int price1, int num1, string region1, int inprice1, int power_dissipation1, int watt1,
        string cpu1, string name1, int size1, string company1, int memorysize1) :
        electronics(price1, num1, region1, inprice1, power_dissipation1, watt1) {
        cpu = cpu1;
        name = name1;
        size = size1;
        company = company1;
        memorysize = memorysize1;
    }
    ~computer();
    virtual void getpower() {
        cout << name << "的续航为：" << power_dissipation << "小时" << endl;
    }
    virtual void getwatt() {
        cout << name << "充电器功耗为：" << watt << "瓦特" << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "台" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "台" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "的产地是：" << region << endl;
    }
    void getcpu() {
        cout << name << "的cpu是：" << cpu << endl;
    }
    void getsize() {
        cout << name << "的size是：" << size << endl;
    }
    void getcompany() {
        cout << name << "的company是：" << company << endl;
    }
    void getmemorysize() {
        cout << name << "的memorysize是：" << memorysize << "GB" << endl;
    }
    string cpu;
    string name;
    int size;//单位 寸
    string company;//公司
    int memorysize;
private:

};
computer::~computer()
{
    cout << name << "电脑已经下架" << endl;
}

//===================================派生1-2_手机（下面）=================================
class phone : public electronics
{
public:
    phone(int price1, int num1, string region1, int inprice1, int power_dissipation1, int watt1,
        string cpu1, string name1, int size1, string company1, int memorysize1) :
        electronics(price1, num1, region1, inprice1, power_dissipation1, watt1) {
        cpu = cpu1;
        name = name1;
        size = size1;
        company = company1;
        memorysize = memorysize1;
    }
    ~phone();
    virtual void getpower() {
        cout << name << "的功耗为：" << power_dissipation << endl;
    }
    virtual void getwatt() {
        cout << name << "充电器功耗为：" << watt << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "台" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "台" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "的产地是：" << region << endl;
    }
    void getcpu() {
        cout << name << "的cpu是：" << cpu << endl;
    }
    void getsize() {
        cout << name << "的size是：" << size << endl;
    }
    void getcompany() {
        cout << name << "的company是：" << company << endl;
    }
    void getmemorysize() {
        cout << name << "的memorysize是：" << memorysize << "GB" << endl;
    }
    string cpu;
    string name;
    int size;//单位 寸
    string company;//公司
    int memorysize;
private:

};
phone::~phone()
{
    cout << name << "手机已经下架" << endl;
}
//===================================派生1-3_手表（下面）=================================
class watch : public electronics
{
public:
    watch(int price1, int num1, string region1, int inprice1, int power_dissipation1, int watt1,
        string name1, int size1, string company1, int memorysize1) :
        electronics(price1, num1, region1, inprice1, power_dissipation1, watt1) {

        name = name1;
        size = size1;
        company = company1;
        memorysize = memorysize1;
    }
    ~watch();
    virtual void getpower() {
        cout << name << "的功耗为：" << power_dissipation << endl;
    }
    virtual void getwatt() {
        cout << name << "充电器功耗为：" << watt << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "台" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "台" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "的产地是：" << region << endl;
    }
    void getsize() {
        cout << name << "的size是：" << size << endl;
    }
    void getcompany() {
        cout << name << "的company是：" << company << endl;
    }
    void getmemorysize() {
        cout << name << "的memorysize是：" << memorysize << "GB" << endl;
    }
    string name;
    int size;//单位 寸
    string company;//公司
    int memorysize;
private:

};
watch::~watch()
{
    cout << name << "智能手表已经下架" << endl;
}

//------------------------------派生2-食物-----------------------------------
class food :public good
{
public:
    food(int price1, int num1, string region1, int inprice1, int produceyear1, int producemonth1, int howlongcanlast1)
        :good(price1, num1, region1, inprice1) {
        producemonth = producemonth1;
        produceyear = produceyear1;
        howlongcanlast = howlongcanlast1;//这里是构造函数 初始化相关内容
    }
    virtual void getproducedate() {
        cout << "生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    virtual void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << "商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << "商品已经过期，请管理员及时处理！" << endl;
        }
    }
    virtual void gethowlonglast() {
        cout << "食品的保质期是：" << howlongcanlast << "月" << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << "某食品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << "某食品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << "某食品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << "某食品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << "某食品的产地是：" << region << endl;
    }
    virtual ~food();
    int produceyear;//生产年份
    int producemonth;//生产日期，月份
    int howlongcanlast;//保质期 月份


private:

};

food::~food()
{
    cout << "某食物已下架" << endl;//写的是虚函数，因此是
}
//---------------------------------2-1饮料 引入 毫升 类别---------------------------------------

class drink : public food {
public:
    drink(int price1, int num1, string region1, int inprice1,
        int produceyear1, int producemonth1, int howlongcanlast1,
        int howmany_ml1, int status1, string name1) :
        food(price1, num1, region1, inprice1, produceyear1, producemonth1, howlongcanlast1)
    {
        howmany_ml = howmany_ml1;
        status = status1;
        name = name1;
    }
    virtual void getproducedate() {
        cout << name << "该批次生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    virtual void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << name << "该批次商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << name << "该批次已经过期，请管理员及时处理！" << endl;
        }
    }
    void healthsuggest() {
        if (status == 1) {
            cout << "该饮品为营养饮品，每日一杯更加有利于健康哦";
        }
        else if (status == 2) {
            cout << "该饮品为饮料，饮料少喝为好！！" << endl;
        }
        else if (status == 3) {
            cout << "酒精类饮品，青少年禁止饮酒，禁止向青少年出售！！" << endl;
        }
        return;
    }
    void gethowlonglast() {
        cout << name << "的保质期是：" << howlongcanlast << "月" << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~drink();
    int howmany_ml;
    int status;//1-健康饮品，2-软饮料，3-酒精类产品
    string name;

private:

};

drink::~drink() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}
//---------------------------------2-2零食 保健食品 充饥食品 垃圾食品---------------------------------------

class snack : public food {
public:
    snack(int price1, int num1, string region1, int inprice1,
        int produceyear1, int producemonth1, int howlongcanlast1,
        int howmany_g1, int status1, string name1) :
        food(price1, num1, region1, inprice1, produceyear1, producemonth1, howlongcanlast1)
    {
        howmany_g = howmany_g1;
        status = status1;
        name = name1;
    }
    virtual void getproducedate() {
        cout << name << "该批次生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    virtual void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << name << "该批次商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << name << "该批次已经过期，请管理员及时处理！" << endl;
        }
    }
    void healthsuggest() {
        if (status == 1) {
            cout << "该零食为营养饮品，每日一点更加有利于健康哦";
        }
        else if (status == 2) {
            cout << "该零食为充饥零食，常备一点更加保险哦！！" << endl;
        }
        else if (status == 3) {
            cout << "膨化食品，少吃为好哦！！" << endl;
        }
        return;
    }
    void gethowlonglast() {
        cout << name << "的保质期是：" << howlongcanlast << "月" << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~snack();
    int howmany_g;
    int status;//2-2零食 保健食品 充饥食品 垃圾食品
    string name;

private:

};

snack::~snack() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}
//==============================================================================
//---------------------------------2-3水果类 夏季水果 春秋季水果 冬季水果---------------------------------------

class fruits : public food {
public:
    fruits(int price1, int num1, string region1, int inprice1,
        int produceyear1, int producemonth1, int howlongcanlast1,
        int howmany_g1, int status1, string name1) :
        food(price1, num1, region1, inprice1, produceyear1, producemonth1, howlongcanlast1)
    {
        howmany_g = howmany_g1;
        status = status1;
        name = name1;
    }
    virtual void getproducedate() {
        cout << name << "该批次生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    virtual void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << name << "该批次商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << name << "该批次已经过期，请管理员及时处理！" << endl;
        }
    }
    void healthsuggest() {
        if (status == 1) {
            cout << "该水果为夏季产品，可以清热解暑哦" << endl;
        }
        else if (status == 2) {
            cout << "春秋季水果，原你也有一个美好的春秋！" << endl;
        }
        else if (status == 3) {
            cout << "冬季水果，在冬天依然可以感受温暖！！" << endl;
        }
        return;
    }
    void gethowlonglast() {
        cout << name << "的保质期是：" << howlongcanlast << "月" << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~fruits();
    int howmany_g;
    int status;//-2-3水果类 夏季水果 春秋季水果 冬季水果(状态类分别为123)
    string name;

private:

};

fruits ::~fruits() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}
//==============================================================================

//------------------------------派生3-运动-----------------------------------
class sport :public good
{
public:
    sport(int price1, int num1, string region1, int inprice1, int produceyear1, string start1)
        :good(price1, num1, region1, inprice1) {
        produceyear = produceyear1;//这里是构造函数 初始化相关内容
        start = start1;
    }
    virtual void date() {
        cout << "发售年份是" << produceyear << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << "某运动产品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << "某运动产品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << "某运动产品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << "某运动产品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << "某运动产品的产地是：" << region << endl;
    }
    virtual void getstart() = 0;//纯虚函数
    virtual void getstatus() = 0;
    virtual ~sport();
    int produceyear;//发售年份
    string start;//代言明星
    //设计了代言明星

private:

};

sport::~sport()
{
    cout << "该运动产品已下架" << endl;//写的是虚函数，因此是
}
//==============================3-1足球======================================

class football : public sport {
public:
    football(int price1, int num1, string region1, int inprice1, int produceyear1, string start1, int status1, string name1) :
        sport(price1, num1, region1, inprice1, produceyear1, start1)
    {
        status = status1;
        name = name1;
    }
    void getstart() {
        cout << "这款产品是由超级巨星" << start << "代言!!!" << endl;
    }
    void getstatus() {
        if (status == 1) {
            cout << "该产品为足球服饰以及护具类，在运动过程中注意安全哦！！" << endl;
        }
        else if (status == 2) {
            cout << "这是踢足球必不可少的足球鞋，祝你能踢出贝氏弧线哦！！！" << endl;
        }
        else if (status == 3) {
            cout << "足球当然是必备品啦！！不必多说！！！" << endl;
        }
        return;
    }
    virtual void date() {
        cout << name << "发售年份是" << produceyear << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << " 产品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "产品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "产品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "产品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~football();
    int year;//使用寿命
    int status;//服饰类，护具 鞋 球
    string name;

private:

};

football ::~football() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}

//================================================== 3 - 2篮球==== ==
class basketball : public sport {
public:
    basketball(int price1, int num1, string region1, int inprice1, int produceyear1, string start1, int status1, string name1) :
        sport(price1, num1, region1, inprice1, produceyear1, start1)
    {
        status = status1;
        name = name1;
    }
    void getstart() {
        cout << "这款产品是由超级巨星" << start << "代言!!!" << endl;
    }
    void getstatus() {
        if (status == 1) {
            cout << "该产品为篮球服饰以及护具类，在运动过程中注意安全哦！！" << endl;
        }
        else if (status == 2) {
            cout << "篮球鞋能够帮助尽量减少崴脚风险" << endl;
        }
        else if (status == 3) {
            cout << "篮球当然是必备品啦！！不必多说！！！" << endl;
        }
        return;
    }
    virtual void date() {
        cout << name << "发售年份是" << produceyear << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << " 产品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "产品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "产品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "产品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~basketball();
    int year;//使用寿命
    int status;//服饰类，护具 鞋 球
    string name;

private:

};

basketball ::~basketball() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}

//======================================3-3 乒乓球===========================================
class pingpong : public sport {
public:
    pingpong(int price1, int num1, string region1, int inprice1, int produceyear1, string start1, int status1, string name1) :
        sport(price1, num1, region1, inprice1, produceyear1, start1)
    {
        status = status1;
        name = name1;
    }
    void getstart() {
        cout << "这款产品是由超级巨星" << start << "代言!!!" << endl;
    }
    void getstatus() {
        if (status == 1) {
            cout << "乒乓球其他类产品" << endl;
        }
        else if (status == 2) {
            cout << "乒乓毛球本身" << endl;
        }
        else if (status == 3) {
            cout << "球拍，这是打球最为讲究的，一定要买好哦！！！" << endl;
        }
        return;
    }
    virtual void date() {
        cout << name << "发售年份是" << produceyear << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << " 产品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "产品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "产品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "产品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~pingpong();
    int year;//使用寿命
    int status;//其他 球 球拍（123）
    string name;

private:

};

pingpong ::~pingpong() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}

//======================================3-3 羽毛球===========================================
class badminton : public sport {
public:
    badminton(int price1, int num1, string region1, int inprice1, int produceyear1, string start1, int status1, string name1) :
        sport(price1, num1, region1, inprice1, produceyear1, start1)
    {
        status = status1;
        name = name1;
    }
    void getstart() {
        cout << "这款产品是由超级巨星" << start << "代言!!!" << endl;
    }
    void getstatus() {
        if (status == 1) {
            cout << "羽毛球其他类产品" << endl;
        }
        else if (status == 2) {
            cout << "羽毛球本身" << endl;
        }
        else if (status == 3) {
            cout << "球拍，这是打球最为讲究的，一定要买好哦！！！" << endl;
        }
        return;
    }
    virtual void date() {
        cout << name << "发售年份是" << produceyear << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << name << " 产品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << name << "产品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "产品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "产品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    virtual ~badminton();
    int year;//使用寿命
    int status;//其他 球 球拍（123）
    string name;

private:

};

badminton ::~badminton() {
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}
//==================================4 日常用品==============================================
class daily :public good
{
public:
    daily(int price1, int num1, string region1, int inprice1, int produceyear1, int producemonth1, int howlongcanlast1)
        :good(price1, num1, region1, inprice1) {
        producemonth = producemonth1;
        produceyear = produceyear1;
        howlongcanlast = howlongcanlast1;//这里是构造函数 初始化相关内容
    }
    virtual void getproducedate() {
        cout << "生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    virtual void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << "商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << "商品已经过期，请管理员及时处理！" << endl;
        }
    }
    virtual void gethowlonglast() {
        cout << "日用品的保质期是：" << howlongcanlast << "月" << endl;
    }
    virtual void subgood(int howmany) {
        num -= howmany;
        cout << "某日用品库存减少" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void addgood(int howmany) {
        num += howmany;
        cout << "某日用品进货" << howmany << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << "某日用品的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << "某日用品的库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << "某日用品的产地是：" << region << endl;
    }
    virtual void suggest() = 0;

    virtual ~daily();
    int produceyear;//生产年份
    int producemonth;//生产日期，月份
    int howlongcanlast;//保质期 月份


private:

};

daily::~daily()
{
    cout << "某日用品已下架" << endl;//写的是虚函数，因此是
}
//===========================================================
//===========================4-1 卫生用品==================================================
class clean : public daily {
public:
    clean(int price1, int num1, string region1, int inprice1,
        int produceyear1, int producemonth1, int howlongcanlast1,
        int howmany_g1, int status1, string name1) :
        daily(price1, num1, region1, inprice1, produceyear1, producemonth1, howlongcanlast1)
    {
        howmany_g = howmany_g1;
        status = status1;
        name = name1;
    }
    void getproducedate() {
        cout << name << "该批次生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << name << "该批次商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << name << "该批次已经过期，请管理员及时处理！" << endl;
        }
    }
    void suggest() {
        if (status == 1) {
            cout << "随身携带更方便哦" << endl;
        }
        else if (status == 2) {
            cout << "让家里更卫生！" << endl;
        }
        else if (status == 3) {
            cout << "感情更协调！！" << endl;
        }
        return;
    }
    void gethowlonglast() {
        cout << name << "的保质期是：" << howlongcanlast << "月" << endl;
    }
    void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    ~clean();
    int howmany_g;
    int status;//1.小巧卫生类（纸巾，牙线等小件） 大件（拖把，消毒水等 ） 成人用品（）
    string name;

private:

};

clean::~clean()
{
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}
//===========================4-2 衣物==================================================
class cloths : public daily {
public:
    cloths(int price1, int num1, string region1, int inprice1,
        int produceyear1, int producemonth1, int howlongcanlast1,
        int howmany_g1, int status1, string name1) :
        daily(price1, num1, region1, inprice1, produceyear1, producemonth1, howlongcanlast1)
    {
        howmany = howmany_g1;
        status = status1;
        name = name1;
    }
    void getproducedate() {
        cout << name << "该批次生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << name << "该批次商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << name << "该批次已经过期，请管理员及时处理！" << endl;
        }
    }
    void suggest() {
        if (status == 1) {
            cout << "配饰让你锦上添花" << endl;
        }
        else if (status == 2) {
            cout << "衣裤，体现品味" << endl;
        }
        else if (status == 3) {
            cout << "贴身更贴心！！" << endl;
        }
        return;
    }
    void gethowlonglast() {
        cout << name << "的保质期是：" << howlongcanlast << "月" << endl;
    }
    void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "件" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "件" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    ~cloths();
    int howmany;//容量
    int status;//1.配饰 2.上衣 裤子 3.贴身衣物
    string name;

private:

};

cloths::~cloths()
{
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}

//===========================4-3 学习==================================================
class study : public daily {
public:
    study(int price1, int num1, string region1, int inprice1,
        int produceyear1, int producemonth1, int howlongcanlast1,
        int howmany_g1, int status1, string name1) :
        daily(price1, num1, region1, inprice1, produceyear1, producemonth1, howlongcanlast1)
    {
        howmany_g = howmany_g1;
        status = status1;
        name = name1;
    }
    void getproducedate() {
        cout << name << "该批次生产日期为：" << produceyear << "年" << producemonth << "月" << endl;
    }
    void checkdate(int year, int month) {
        //该函数是检查是否过期，入口参数是年份还有月份
        int detayear = year - produceyear;
        int detamonth = month - producemonth;
        detamonth += (detayear) * 12;
        if (detamonth < 0) {
            cout << "输入日期有误，或该商品生产日期录入有误！" << endl;
        }
        else if (detamonth < howlongcanlast) {
            cout << name << "该批次商品没有过期，请放心购买！" << endl;
        }
        else {
            cout << name << "该批次已经过期，请管理员及时处理！" << endl;
        }
    }
    void suggest() {
        if (status == 1) {
            cout << "文科提升您的修为！！！" << endl;
        }
        else if (status == 2) {
            cout << "理科提升您的智慧！！！" << endl;
        }
        else if (status == 3) {
            cout << "工科让您成为大国工匠！！" << endl;
        }
        return;
    }
    void gethowlonglast() {
        cout << name << "的保质期是：" << howlongcanlast << "月" << endl;
    }
    void subgood(int howmany) {
        num -= howmany;
        cout << name << "库存减少" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    void addgood(int howmany) {
        num += howmany;
        cout << name << "进货" << howmany << "瓶" << endl;
    }//为什么写某商品，因为虚函数，具体商品可以调用派生类函数具体实现
    virtual void getprice() {
        cout << name << "的单价是：" << price << endl;
    }
    virtual void getnum() {
        cout << name << "库存是：" << num << endl;
    }
    virtual void getregion() {
        cout << name << "产地是：" << region << endl;
    }
    ~study();
    int howmany_g;
    int status;//1.文科 2.理科 3.工科
    string name;

private:

};

study::~study()
{
    cout << name << "已下架" << endl;//写的是虚函数，因此是
}
//定义
computer  macbook_pro2021(14999, 100, "America", 13000, 21, 55, "m1pro", "macbookpro", 14, "apple_canifornia", 512);
computer  macbook_air2020(7999, 200, "America", 6777, 21, 35, "m1", "macbookair", 13, "apple_canifornia", 256);

phone HUAWEI_MATE_80(5999, 100, "China", 4888, 30, 40, "Harmony", "Huawei Mate80", 8, "Huawei", 256);
phone iPhone18(9999, 20, "Canada", 4000, 48, 50, "Inter pro+++", "iPhone", 9, "apple_Canada", 512);

watch MI(998, 20, "India", 98, 72, 1, "MI_watch", 5, "Xiaomi", 64);
watch Apple_watch(2998, 20, "Canada", 1198, 48, 1, "Apple_watch", 5, "Apple", 64);

drink Cocacola(3, 200, "Fujian", 2, 2022, 2, 12, 1, 2, "可口可乐");//只买一杯
drink maguey(58, 10, "America", 30, 2022, 6, 10, 1, 3, "龙舌兰");
drink suda(10, 20, "Wuhan", 8, 2022, 4, 12, 1, 1, "苏打水");

snack Leshi(5, 58, "Lanzhou", 3, 2021, 10, 9, 1, 3, "乐事");
snack biscuits(7, 58, "Lanzhou", 3, 2021, 10, 9, 1, 2, "压缩饼干");
snack protein(188, 58, "Lanzhou", 100, 2022, 5, 9, 1, 1, "蛋白粉");

fruits waterm(55, 50, "China", 30, 2022, 6, 1, 1, 1, "西瓜");
fruits banana(55, 50, "China", 30, 2022, 6, 1, 1, 2, "香蕉");
fruits orange(25, 50, "China", 20, 2022, 6, 1, 1, 3, "柑橘");

football ball1(120, 50, "Argentina", 70, 2022, "Beckham", 3, "2022卡塔尔世界杯用球");
football shoes1(1200, 50, "Argentina", 1000, 2022, "Lionel Messi", 2, "猎鹰");
football cloth1(400, 50, "Liverpool", 300, 2022, "萨拉赫", 1, "利物浦11号球衣");

basketball ball2(120, 50, "Amercia", 70, 2022, "张瑞鹏", 3, "标准用球");
basketball sheos2(9999, 50, "Putian", 1000, 2022, "James", 2, "AJ1");
basketball cloth2(400, 50, "LA", 300, 2022, "Jordan", 1, "Laker");

pingpong pingpongball(2, 100, "Beijing", 1, 2022, "马龙", 1, "乒乓球");
pingpong pingpongbat(200, 100, "Beijing", 100, 2022, "马龙", 3, "红双喜球拍");

badminton badball(2, 100, "Beijing", 1, 2022, "林丹", 1, "羽毛球");
badminton badbat(121, 100, "Beijing", 100, 2022, "林丹", 3, "羽毛球拍");

clean towel(25, 50, "Shanghai", 20, 2022, 6, 100, 1, 2, "毛巾");
clean Duleis(25, 50, "Shanghai", 20, 2022, 6, 100, 1, 2, "杜蕾斯");

cloths LV(2555, 50, "France", 20, 2022, 6, 1, 1, 2, "LV");

study  WUSAN1(42, 50, "China", 20, 2022, 6, 1, 1, 1, "五年高考，三年模拟（文科）");
study  WUSAN2(42, 50, "China", 20, 2022, 6, 1, 1, 2, "五年高考，三年模拟（理科）");
void outInform_electronic(electronics& x) {
    x.getprice(); x.getregion(); x.getwatt(); x.getpower(); x.getnum();
    cout << "是否购买(y/n)"; char choice; cin >> choice;
    if (choice == 'y') {
        cout << "购买数量："; int num; cin >> num;
        if (num > x.num) {
            cout << "库存不足" << endl;
        }
        else
            x.subgood(num);
    }

}
void menu_electronic() {
    cout << "\t\t\t\t\t电子产品类商品如下\t\t\t\t\t" << endl;
    cout << "1、" << macbook_pro2021.name << endl << "2、" << macbook_air2020.name << endl << "3、" << iPhone18.name << endl << "4、" << HUAWEI_MATE_80.name << endl << "5、" << MI.name << endl << "6、" << Apple_watch.name << endl;
    int choice = 1;
    while (choice) {
        cin >> choice;
        switch (choice) {
        case 1:
            outInform_electronic(macbook_pro2021);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 2:
            outInform_electronic(macbook_air2020);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 3:
            outInform_electronic(iPhone18);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 4:
            outInform_electronic(HUAWEI_MATE_80);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 5:
            outInform_electronic(MI);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 6:
            outInform_electronic(Apple_watch);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        }
    }
}
void outInform_electronic_m(electronics& x) {
    x.getprice(); x.getregion(); x.getwatt(); x.getpower(); x.getnum();
    cout << "是否进货(y/n)"; char choice; cin >> choice;
    if (choice == 'y') {
        cout << "进货数量："; int num; cin >> num;
        x.addgood(num);
    }

}
void menu_electronic_m() {
    cout << "\t\t\t\t\t电子产品类商品如下\t\t\t\t\t" << endl;
    cout << "1、" << macbook_pro2021.name << endl << "2、" << macbook_air2020.name << endl << "3、" << iPhone18.name << endl << "4、" << HUAWEI_MATE_80.name << endl << "5、" << MI.name << endl << "6、" << Apple_watch.name << endl;
    int choice = 1;
    while (choice) {
        cin >> choice;
        switch (choice) {
        case 1:
            outInform_electronic_m(macbook_pro2021);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 2:
            outInform_electronic_m(macbook_air2020);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 3:
            outInform_electronic_m(iPhone18);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 4:
            outInform_electronic_m(HUAWEI_MATE_80);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 5:
            outInform_electronic_m(MI);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 6:
            outInform_electronic_m(Apple_watch);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        }
    }
}
void outInform_food(food& x) {
    x.getprice(); x.getregion(); x.getnum(); x.gethowlonglast(); x.checkdate(x.produceyear, x.producemonth);
    cout << "是否购买(y/n)"; char choice; cin >> choice;
    if (choice == 'y') {
        cout << "购买数量："; int num; cin >> num;
        if (num > x.num) {
            cout << "库存不足" << endl;
        }
        else
            x.subgood(num);
    }

}
void menu_food() {
    cout << "\t\t\t\t\t食品酒水类商品如下\t\t\t\t\t" << endl;
    cout << "1、" << Cocacola.name << endl << "2、" << maguey.name << endl << "3、" << suda.name << endl << "4、" << Leshi.name << endl << "5、" << biscuits.name << endl << "6、" << protein.name << endl << "7、" << waterm.name << endl << "8、" << banana.name << endl << "9、" << orange.name << endl;
    int choice = 1;
    while (choice) {
        cin >> choice;
        switch (choice) {
        case 1:
            outInform_food(Cocacola);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 2:
            outInform_food(maguey);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 3:
            outInform_food(suda);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 4:
            outInform_food(Leshi);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 5:
            outInform_food(biscuits);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 6:
            outInform_food(protein);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 7:
            outInform_food(waterm);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 8:
            outInform_food(banana);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 9:
            outInform_food(orange);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        }
    }
}
void outInform_sports(sport& x) {
    x.getprice(); x.getregion(); x.date(); x.getnum(); x.getstart(); x.getstatus();
    cout << "是否购买(y/n)"; char choice; cin >> choice;
    if (choice == 'y') {
        cout << "购买数量："; int num; cin >> num;
        if (num > x.num) {
            cout << "库存不足" << endl;
        }
        else
            x.subgood(num);
    }
}
void menu_sports() {
    cout << "\t\t\t\t\t运动装备类商品如下\t\t\t\t\t" << endl;
    cout << "1、" << ball1.name << endl << "2、" << ball2.name << endl << "3、" << shoes1.name << endl << "4、" << sheos2.name << endl << "5、" << cloth1.name << endl << "6、" << cloth2.name << endl << "7、" << pingpongball.name << endl << "8、" << pingpongbat.name << endl << "9、" << badball.name << endl << "10、" << badbat.name << endl;
    int choice = 1;
    while (choice) {
        cin >> choice;
        switch (choice) {
        case 1:
            outInform_sports(ball1);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 2:
            outInform_sports(ball2);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 3:
            outInform_sports(shoes1);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 4:
            outInform_sports(sheos2);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 5:
            outInform_sports(cloth1);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 6:
            outInform_sports(cloth2);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 7:
            outInform_sports(pingpongball);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 8:
            outInform_sports(pingpongbat);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 9:
            outInform_sports(badball);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 10:
            outInform_sports(badbat);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        }
    }
}
void outInform_daily(daily& x) {
    x.getprice(); x.getregion(); x.getnum(); x.checkdate(x.produceyear, x.producemonth); x.gethowlonglast();
    x.suggest();
    cout << "是否购买(y/n)"; char choice; cin >> choice;
    if (choice == 'y') {
        cout << "购买数量："; int num; cin >> num;
        if (num > x.num) {
            cout << "库存不足" << endl;
        }
        else
            x.subgood(num);
    }
}
void menu_daily() {
    cout << "\t\t\t\t\t运动装备类商品如下\t\t\t\t\t" << endl;
    cout << "1、" << towel.name << endl << "2、" << Duleis.name << endl << "3、" << LV.name << endl << "4、" << WUSAN1.name << endl << "5、" << WUSAN2.name << endl;
    int choice = 1;
    while (choice) {
        cin >> choice;
        switch (choice) {
        case 1:
            outInform_daily(towel);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 2:
            outInform_daily(Duleis);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 3:
            outInform_daily(LV);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 4:
            outInform_daily(WUSAN1);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        case 5:
            outInform_daily(WUSAN2);
            cout << "是否继续，退出请按0，继续请选择\n";
            break;
        }
    }
}

void menu_shopping() {
    cout << "\t\t\t\t\t欢迎光临，随意挑选\t\t\t\t\t" << endl;
    cout << "\t电子产品类请按1，食品酒水类请按2，运动装备类请按3，日用商品类请按4，退出请按0" << endl;
    int choice;
    cin >> choice;
    while (choice) {
        switch (choice) {
        case 1:
            menu_electronic();
            break;
        case 2:
            menu_food();
            break;
        case 3:
            menu_sports();
            break;
        case 4:
            menu_daily();
            break;
        default:
            break;
        }
        cout << "\t电子产品类请按1，食品酒水类请按2，运动装备类请按3，日用商品类请按4，退出请按0" << endl;
        cin >> choice;
    }
}

void write_in_file(const string filename, int num, string name) {
    ofstream outfile;
    outfile.open(filename, ofstream::app | ofstream::out);
    outfile << name << "库存：" << num << endl;
    outfile.close();
}
void Write(const string filename) {
    printf("正在写入......\n");
    write_in_file(filename, macbook_pro2021.num, macbook_pro2021.name);
    write_in_file(filename, macbook_air2020.num, macbook_air2020.name);
    write_in_file(filename, HUAWEI_MATE_80.num, HUAWEI_MATE_80.name);
    write_in_file(filename, iPhone18.num, iPhone18.name);
    write_in_file(filename, MI.num, MI.name);
    write_in_file(filename, Apple_watch.num, Apple_watch.name);
    write_in_file(filename, Cocacola.num, Cocacola.name);
    write_in_file(filename, maguey.num, maguey.name);
    write_in_file(filename, suda.num, suda.name);
    write_in_file(filename, Leshi.num, Leshi.name);
    write_in_file(filename, biscuits.num, biscuits.name);
    write_in_file(filename, protein.num, protein.name);
    write_in_file(filename, waterm.num, waterm.name);
    write_in_file(filename, banana.num, banana.name);
    write_in_file(filename, orange.num, orange.name);
    write_in_file(filename, ball1.num, ball1.name);
    write_in_file(filename, ball2.num, ball2.name);
    write_in_file(filename, shoes1.num, shoes1.name);
    write_in_file(filename, sheos2.num, sheos2.name);
    write_in_file(filename, cloth1.num, cloth1.name);
    write_in_file(filename, cloth2.num, cloth2.name);
    write_in_file(filename, pingpongball.num, pingpongball.name);
    write_in_file(filename, pingpongbat.num, pingpongbat.name);
    write_in_file(filename, badball.num, badball.name);
    write_in_file(filename, badbat.num, badbat.name);
    write_in_file(filename, towel.num, towel.name);
    write_in_file(filename, Duleis.num, Duleis.name);
    write_in_file(filename, LV.num, LV.name);
    write_in_file(filename, WUSAN2.num, WUSAN2.name);
    write_in_file(filename, WUSAN1.num, WUSAN1.name);
}
void menu_manager() {
    cout << "\t电子产品类请按1，食品酒水类请按2，运动装备类请按3，日用商品类请按4，退出请按0" << endl;
    int choice; cin >> choice;
    if (choice == 1) {
        menu_electronic_m();
    }
    else if (choice == 2) {
        menu_food();
    }
    else if (choice == 3) {
        menu_sports();
    }
    else if (choice == 4) {
        menu_daily();
    }
    else
        return;
}
void menu() {
    cout << "\t\t\t\t\t欢迎使用，请选择您的身份\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t1、管理者；2、消费者\t\t\t\t\t" << endl;
    int choice;
    cin >> choice;
    if (choice == 2) {
        menu_shopping();
    }
    else if (choice == 1) {
        menu_manager();
    }
}
int main(void) {
    menu();
    const string filename = "/Users/macbook/Desktop/C++_result.txt";
    Write(filename);
    return 0;
}
