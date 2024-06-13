//#include "iostream"
//using namespace std;
//
//class Complex{
//private:
//    double rel,vir;//分别存储复数的实部和虚部
//public:
//    Complex(double rel,double vir){//参数构造
//        this->rel=rel;
//        this->vir=vir;
//    }
//    //重载运算符,用于计算两个对象相加
//    Complex operator+(Complex complex) const{
//        Complex t_complex(0,0);
//        t_complex.rel= this->rel+complex.rel;
//        t_complex.vir= this->vir+complex.vir;
//        return t_complex;
//    }
//    //重载运算符,用于计算对象与整数的相加
//    Complex operator+(double rel) const{
//        Complex t_complex(0,0);
//        t_complex.rel= this->rel+rel;
//        t_complex.vir= this->vir;
//        return t_complex;
//    }
//
//    void display() const{
//        cout<<rel<<"+"<<vir<<"i"<<endl;
//    }
//};
//int main(){
//    Complex c1(1,2.4);
//    Complex c2(2,2);
//
//    Complex c3=c1+c2;
//    c3.display();
//
//    c3=c1+2;
//    c3.display();
//}
