//电脑组装:显示器、鼠标、键盘、主机（主机又包括cpu、显卡、主板等）
//1.找到店铺老板告诉需求
//2.客服安排技术员工组装
//3.产品组装完成

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//电脑组装:显示器、鼠标、键盘、主机（主机又包括cpu、显卡、主板等）
//1.找到店铺老板告诉需求
//2.客服安排技术员工组装
//3.产品组装完成
//抽象产品类

//抽象产品类
class AbstractProduct{
    public:
        virtual void SetDisplay(string displayer)=0;
        virtual void SetMouse(string name)=0;
        virtual void SetHost(string host)=0;
        virtual void Show()=0;
};

//具体产品类
class Computer:public AbstractProduct{
    vector<string>m_list;
    void SetDisplay(string displayer){
        m_list.push_back(displayer);
    }
    void SetMouse(string mouse)
    {
        m_list.push_back(mouse);
    }
    void SetKeyBoard(string keyBoard) 
    {
        m_list.push_back(keyBoard);
    }
    void SetHost(string host) 
    {
        m_list.push_back(host);
    }
    void Show() 
    {
        cout << "电脑配置结果:" << endl;
        for (auto v : m_list) 
        {
            cout << v << endl;
        }
    }
};

class AbstractBuilder{
    protected:
        AbstractProduct* product;
    public:
    AbstractBuilder():product(new Computer) {}
    //抽象构造过程
    virtual void BuildDisplayer(string displayer) = 0;
    virtual void BuildMouse(string mouse) = 0;
    //virtual void BuildKeyBoard(string keyBoard) = 0;
    virtual void BuildHost(string host) = 0;
    AbstractProduct* Getproduct() 
    {
        return product;
    }
};

//具体的建造者类--->组装电脑的技术员
class ConcreteBuilder :public AbstractBuilder 
{
public:
    void BuildDisplayer(string displayer) override
    {
        product->SetDisplay(displayer);
    }
    void BuildMouse(string mouse) override
    {
        product->SetMouse(mouse);
    }
    void BuildHost(string host) override
    {
        product->SetHost(host);
    }
};

//指挥者类
class Director 
{
public:
    Director(AbstractBuilder* pBuilder) :pBuilder(pBuilder) {}
    AbstractProduct* createProduct(string displayer, string mouse, string keyBoard, string host) 
    {
        pBuilder->BuildDisplayer(displayer);
        pBuilder->BuildMouse(mouse);
        //pBuilder->BuildKeyBoard(keyBoard);
        pBuilder->BuildHost(host);
        return pBuilder->Getproduct();
    }
private:
    AbstractBuilder* pBuilder;
};

int main() 
{
    AbstractBuilder* pB = new ConcreteBuilder;
    Director* pD = new Director(pB);
    AbstractProduct* computer = pD->createProduct("华为显示器", "牧马人鼠标", "雷蛇键盘", "外星人");
    computer->Show();
    return 0;
}