#include <iostream>
#include <map>
class Context {};

class ProStategy {
public:
    virtual double CalcPro(const Context& ctx) = 0;
    virtual ~ProStategy() {};
};

class VAC_Spring : public ProStategy {
    double CalcPro(const Context& ctx) {
        std::cout << "VAC_Spring";
        return 0.0L;
    };

};

class VAC_QiXi : public ProStategy {
    double CalcPro(const Context& ctx) {
        std::cout << "VAC_QiXi";
        return 0.0L;
    };
};

class VAC_Wuyi : public ProStategy {
    virtual double CalcPro(const Context& ctx) {};
};

class VAC_GuoQing : public ProStategy {
    virtual double CalcPro(const Context& ctx) {};
};

class Vac_Shengdan : public ProStategy {
    virtual double CalcPro(const Context& ctx) {};
};

class Promotion {
public:
    Promotion(ProStategy *sss = nullptr) :s(sss) {}
    ~Promotion() {};
    void choose(ProStategy *sss)
    {
        if (sss != nullptr)
            s = sss;
    }
    double CalcPromotion(const  Context& ctx) {
        if (s != nullptr)
            s->CalcPro(ctx);
        return 0.0L;
    }
private:
        ProStategy *s;
};

int main()
{
    std::map<int,ProStategy*> Fun;
    Context ctx;
    ProStategy *s = new VAC_Spring();
    Fun[1] = s;
    auto a = Fun.find(1);
    Promotion *p = new Promotion(a->second);
    p->CalcPromotion(ctx);
}
