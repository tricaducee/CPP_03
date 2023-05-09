#include <iostream>
#include <string>

class A {
public:
    A() : _name("a"), _v1(1), _v2(2), _v3(3) {}
    A(std::string name, int v1, int v2, int v3) : _name(name), _v1(v1), _v2(v2), _v3(v3) {}
    ~A() {}
    void printValue() const {
        std::cout << "name : " << this->_name << std::endl;
        std::cout << "v1 : " << this->_v1 << std::endl;
        std::cout << "v2 : " << this->_v2 << std::endl;
        std::cout << "v3 : " << this->_v3 << std::endl;
    }

protected:
    std::string _name;
    int _v1;
    int _v2;
    int _v3;
};

class B : virtual public A {
public:
    B() : A("b", 4, 5, 6) {}
    B(int v1, int v2, int v3) : A("b", v1, v2, v3) {}
    ~B() {}
    void bUnique() const {
        std::cout << "bUnique" << std::endl;
    }
};

class C : virtual public A {
public:
    C() : A("c", 7, 8, 9) {}
    C(int v1, int v2, int v3) : A("c", v1, v2, v3) {}
    ~C() {}
    void cUnique() const {
        std::cout << "cUnique" << std::endl;
    }
};

class BC : public B, public C {
public:
    BC(std::string name) : A(name, 4, 8, 6), B(4, 5, 6), C(7, 8, 9) {}
    ~BC() {}
    void BCUnique() const {
        std::cout << "bcUnique" << std::endl;
    }
};

int main() {
    BC bc("bc");
    bc.printValue(); // Affiche les valeurs de v1 et v3 de B et v2 de C et le name de BC
    return 0;
}
