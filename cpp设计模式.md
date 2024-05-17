# 什么是工厂模式（Factory Pattern）？

## 工厂模式

是最常用的实例化对象模式，用工厂方法代替new操作的一种模式。它是创建行模式

工厂模式有三种：简单工厂模式，工厂方法模式和抽象工厂模式

## 简单工厂模式

要用程序实现女娲造人，首先要确定好有哪些对象。经过分析该过程涉及三个对象：女娲，八卦炉和三种肤色的人。女娲相当于调用方client，八卦炉相当于生产人的工厂，三种肤色的人都是人类，所以定义一个人类接口，让三种肤色的人实现这个接口。

![img](cpp设计模式/v2-0258b293c8e48320209c1c70b21cdb7b_1440w.webp)

HumanFactory是一个创建人类的工厂（八卦炉），它有一个创建人类的方法 createHuman，具体创建什么肤色的人来根据方法的入参决定。

### 简单工厂模式的优缺点

* 优点：将对象的创建交给专门的工厂类负责，实现了对象的创建和对象的使用分离
* 缺点：工厂类不够灵活，增加新的具体产品需要修改工厂类的判断逻辑代码，比如都看过X战警吧，里面的魔形女是绿皮肤，上面的工厂类显然满足不了，需要增加一个 if 判断分支才能支持。而且当产品类型较多时，简单工厂的 if 判断将会非常多，不容易维护。

## 工厂方法模式

定义：定义一个用于创建对象的接口或抽象类，让子类决定实例化哪一个类。

![img](cpp设计模式/v2-7de47f223e0bb6df3da6c38da50ba06d_1440w.webp)

其中，Human接口及其子类的代码不变，增加了一个抽象工厂AbstractHumanFactory，里面定义了一个造人的方法 createHuman()，具体创造什么类型的人由其子工厂实现。

### 工厂方法模式的优缺点

* 工厂方法模式的优点：遵循了开闭原则，扩展性极强。比如现在要增加一个绿皮肤的人类，我们只需要增加一个创建绿皮肤人类的工厂，这个工厂继承自抽象工厂即可，不需要改变原有代码，可维护性高。

* 工厂方法模式的缺点：增加了类的数量，当有成千上万个类型的产品时，就需要有成千上万个工厂类来生产这些产品



## 抽象工厂模式

在工厂方法模式中，一个具体的工厂负责生产一类具体的产品，即一对一的关系，但是，如果需要一个具体的工厂生产多种产品对象，比如，生产不同肤色的男人和女人，那么就需要抽象工厂模式。

![img](cpp设计模式/v2-97662da92d12ea9566b67c985e0ad33d_1440w.webp)

抽象工厂我们定义了两个方法，createMan() 和 createWoman()用来表示生产男人和女人，不管男人或女人，都有不同的肤色，所以我们定义了三个子工厂用来创建不同肤色的人（包括男人和女人），这三个子工厂重写了父类工厂的两个方法。

### 抽象工厂模式的优缺点

* 抽象工厂模式的优点：增加固定类型产品的不同具体工厂比较方便。例如现在女娲要创造一个绿皮肤的人，只需要再创建一个绿皮肤人的工厂继承抽象8工厂就可以了。

* 抽象工厂模式的缺点：类图优点复杂，可读性没有工厂方法模式那么好。

## C++中如何实现简单的工厂模式？

[C++ 深入浅出工厂模式（初识篇） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/83535678)

* 在工厂模式中，我们创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象
* 简单来说，使用了C++的多态特性，将存在继承关系的类，通过一个工厂类创建对应的子类对象。在项目复杂的情况下，可以便于子类对象的创建。

### C++实现简单工厂模式的示例代码

鞋厂可以指定生产耐克，阿迪达斯和李宁牌子的鞋子。哪个鞋炒的火爆，老板就生产哪个。

![img](cpp设计模式/v2-f75c5b1c3ef8624fbb424d5a48401848_720w.webp)

#### 简单工厂模式的结构组成

1. 工厂类：工厂模式的核心类，会定义一个用于创建指定的具体实例对象的接口
2. 抽象产品类：是具体产品类的继承的父类或实现的接口
3. 具体产品类：工厂类所创建的对象就是此具体产品实例

* 特点：封装了创建具体产品对象的函数
* 缺陷：拓展性差

#### 代码

Shoes为鞋子的抽象类（基类），接口函数为Show()，用于显示鞋子广告。NiKeShoes、AdidasShoes、LiNingShoes为具体鞋子的类，分别是耐克、阿迪达斯和李宁鞋牌的鞋，它们都继承于Shoes抽象类。

```c++
class Shoes{
	public:
    	virtual ~Shoes(){}
    	virtual void Show()=0;
};
// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};

// 阿迪达斯鞋子
class AdidasShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是阿迪达斯球鞋，我的广告语:Impossible is nothing" << std::endl;
    }
};

// 李宁鞋子
class LiNingShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是李宁球鞋，我的广告语：Everything is possible" << std::endl;
    }
};
```

ShoesFactory为工厂类，类里实现根据鞋子类型创建对应鞋子产品对象的CreateShoes(SHOES_TYPE type)函数

```c++
enum SHOES_TYPE{
    NIKE,
    LINING,
    ADIDAS
};
//总鞋厂
class ShoesFactory{
	public:
    	Shoes *CreateShoes(SHOEE_TYPE type){
			switch(type){
                case NIKE:
                    return new NikeShoes();
                    break;
                case LINING:
            		return new LiNingShoes();
            		break;
        		case ADIDAS:
            		return new AdidasShoes();
            		break;
        		default:
            		return NULL;
            		break;
            }
        }
};
```

main函数，先是构造了工厂对象，后创建指定类型的具体鞋子产品对象，创建了具体鞋子产品的对象可直接打印广告，因为采用的是new的方式创建了对象，用完了要通过delete释放资源

```c++
int main(){
    ShoesFactory shoesFactory;
    //从鞋厂工厂对象创建nike鞋子对象
    Shoes *pNikeShoes=shoesFactory.CreateShoes(NIKE);
    if (pNikeShoes != NULL)
    {
        // 耐克球鞋广告喊起
        pNikeShoes->Show();

        // 释放资源
        delete pNikeShoes;
        pNikeShoes = NULL;
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    Shoes *pLiNingShoes = shoesFactory.CreateShoes(LINING);
    if (pLiNingShoes != NULL)
    {
        // 李宁球鞋广告喊起
        pLiNingShoes->Show();

        // 释放资源
        delete pLiNingShoes;
        pLiNingShoes = NULL;
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    Shoes *pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
    if (pAdidasShoes != NULL)
    {
        // 阿迪达斯球鞋广告喊起
        pAdidasShoes->Show();

        // 释放资源
        delete pAdidasShoes;
        pAdidasShoes = NULL;
    }

    return 0;
}
```

## 工厂模式有哪些缺点或需要注意的地方？

* 增加复杂性：类的个数容易过多，增加系统复杂度，在添加新的产品时，除了编写新的产品类之外，还要编写该产品类对应的工厂类
* 增加难度：增加系统抽象性和理解难度，工厂方法本身利用了抽象，该模式中会引入抽象层。



# 观察者模式

## 什么是观察者模式

[观察者模式（c++学习笔记） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/119308881)

* 观察者模式面向的需求是：A对象（观察者）对B对象（被观察者）的某种变化高度敏感，需要在B变化的一瞬间作出反应
* 观察者模式，又叫发布-订阅模式，定义对象间一种一对多的关系，使得每当一个对象改变状态，则所有依赖于它的对象都会得到通知并自动更新

## C++如何实现观察者模式

**观察者模式的核心思想是一对多**

例：下半时会告诉孩子和他妈，我要开车往回走了

* 孩子妈收到消息开始做饭
* 孩子收到消息，收起手机

传统写法：

```c++
#include<iostream>
class Son{
public:
    void DoSomething(){
        std::cout<<"爸爸回来了，赶紧去写作业"<<std::endl;
    }
};

class Wife{
public:
    void DoSomething(){
        std::cout<<"老公回来了，去做饭"<<std::endl;
    }
};

class Me{
public:
    void Gohome(){
        wife.DoSomething();
        son.DoSomething();
    }
private:
    Wife wife;
    Son son;
};

int main(){
    Me me;
    me.Gohome();
    return 0;
}
```

这样写的不足如下：

1. 如果关心我的人变多了，比如我又加了我老妈、老爸 ，这时候我们不得不去修改Me的类
2. 人数少的时候，还可以应付，假如关心我的人有1000人，那这时候我们该怎么办

### 1. 重构，简单观察者模式，面向抽象编程

1. 观察者接口

```c++
class ObserverInterface{
	public:
    	virtual void dosomething()=0;
    	virtual ~ObserverInterface(){}
};
```

2. 被观察者接口

```c++
class SubjectInterface{
  	public:
    	virtual void add(ObserverInterface* obr)=0;
    	virtual void Remove(ObserverInterface* obr)=0;
		virtual void Notify()=0;
		virtual ~SubjectInterface(){}
};
```

3. 我自己

```c++
class Me:public SubjectInterface{
public:
    void Add(ObserverInterface* obr) override{
        observers.push_back(obr);
    }

    void Remove(ObserverInterface* obr) override{
        auto pos=std::find(observers.begin(),observers.end(),obr);
        if(pos!=observers.end()){
            observers.erase(pos);
        }
    }

    void Notify() override{
        for(const auto& obs:observers){
            obs->dosomething();
        }
    }

private:
    std::vector<ObserverInterface*> observers;
};
```

4. 孩子妈

```c++
class Wife:public ObserverInterface{
public:
    void dosomething() override{
        std::cout<<"老公快回来了，开始做饭"<<std::endl;
    }
};
```

5. 孩子

```c++
class Son:public  ObserverInterface{
public:
    void dosomething() override {
        std::cout<<"爸爸快回来了，不能玩游戏了"<<std::endl;
    }
};
```

6. main函数

```c++
int main(){
    Me me;
    ObserverInterface* wife=new Wife;
    ObserverInterface* son=new Son;
    me.Add(wife);
    me.Add(son);

    //下班了 发消息
    me.Notify();

    delete wife;
    delete son;
}
```

这样的好处是

1. 再增加新的观察者，不用修改Me的类了，只需要添加到vector中就可以了
2. 需要自己做内存管理去delete

### 2. 优化，使用智能指针shared_ptr代替*

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class ObserverInterface{
	public:
    	virtual viod dosomething()=0;
};

using pOberverInterface=std::shared_ptr<ObserverInterface>;


```



### 观察者模式的优缺点

* 观察者和被观察者之间建立了一个抽象的耦合
* 观察者模式支持广播通讯。被观察者会向所有的登记过的观察者发出通知
* 如果一个被观察者对象有很多的直接和间接的观察者，将所有观察者都通知到会花费很多时间
* 如果在被观察者之间有循环依赖的话，被观察者会触发它们之间进行循环调用，导致系统崩溃。在使用观察者模式是要特别注意这一点。
* 如果对观察者的通知是通过另外的线程进行异步投递的话，系统必须保证投递是以自恰的方式进行的。



* 应用场景
  * 对一个对象状态的更新，需要其他对象同步更新，而且其他对象的数量动态可变
  * 对象仅需要将自己的更新通知给其他对象而不需要知道其他对象的细节

# 建造者模式

## 什么是建造者模式

* 建造者模式是一种对象创建型模式之一，用来隐藏复合对象的创建过程，它把复合对象的创建过程加以抽象，通过子类继承和重载的方式，动态地创建具有复合属性的对象。官方说法就是将一个复杂对象的构造与它的表示分离，使同样的构建过程可以创建不同的表示。

## 实现步骤

1. 提供抽象建造者类：为创建产品各个部分，统一抽象接口
2. 提供具体建造者：具体实现抽象建造者各个部件的接口
3. 提供多个产品类：具体的创建产品的各个部分
4. 提供一个指挥类：负责安排和调度复杂对象的各个建造过程

## **建造者模式优缺点**

**优点**

- 封装性好，构建和表示分离
- 扩展性好，各个具体的建造者相互独立，有利于系统的解耦
- 控制细节风险，客户端无需详知细节，建造者细化创建过程

**缺点**

- 产品的组成部分必须相同，这限制了其使用范围
- 产品内部发生变化，建造者需同步修改，后期维护成本较大

# 桥接模式

## 含义

桥接模式是一种结构型设计模式，用于将抽象部分与其实现部分分离，使他们可以独立地变化。通过这种方式，桥接模式提供了更好的代码组织结构，可以减少类之间的继承关系，并提供更灵活的设计以应对变化

## 核心思想

桥接模式的核心思想是**分离抽象和实现**，使得二者可以独立地变化。在这种模式中，抽象部分指的是有高层的控制逻辑，而实现部分则是底层的具体操作。桥接模式通过提供一个桥接结构，使得抽象层和实现层不直接交互，而是通过桥接接口来进行通信，从而实现解耦。

## 优缺点

1. **改善可扩展性：** 当抽象和实现可以独立变化时，增加新的实现或抽象变得更容易。
2. **避免固定绑定：** 最初设计时不需要预见所有可能的变化，新增功能只需扩展实现部分。
3. **减少类的数量：** 桥接模式可以帮助折叠多维度的继承结构，减少系统中的类的数量。



1. **理解设计的复杂性：** 引入桥接模式会增加系统的设计复杂性，应当在多维度变化的情况下使用，以避免过度设计。
2. **抽象和实现的适当分离：** 需要仔细设计抽象部分和实现部分的界限，确保两者的独立性。

## 工程的应用场景

1. **当一个系统需要在多个维度上变化，或者它需要独立于其实现的不同部分时**：如不同的用户界面和业务逻辑的组合
2. **避免类的爆炸性增长**：特别是在有多种变化因素时，桥接模式可以有效管理这种复杂性。
3. **分享实现**： 允许多个对象共享一个实现，而不需关心外界如何使用它



# 适配器模式

## 什么适配器模式

适配器模式，说白了就是由于目标接口与已有接口不一致，但是功能相似，只要对目标接口稍作处理（这里的处理就是适配器工作方式）就可以实现目标功能。

我们知道不同国家的电压可能不同，而生产的电器也不是所有电压都能正常工作，总不能针对不同国家的电压生产专门的电器吧，于是电源适配器就产生了，它的作用就是把不同电压变成电器需要的电压，这就是适配器模式的一种应用。



1. 目标接口（Target）定义了客户端使用的特定接口。
2. 适配器（Adapter）实现了目标接口，并持有一个被适配者的实例。
3. 被适配者（Adaptee）是需要被适配的类，其接口与目标接口不兼容。

# 原型模式

