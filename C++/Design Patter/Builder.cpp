#include <iostream>
#include <string>

// Product class
class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void showPizza() {
        std::cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce, and " << topping_ << " topping." << std::endl;
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

// Builder abstract class
class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza* getPizza() = 0;
};

// Concrete builder class
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() {
        pizza_ = new Pizza();
    }

    void buildDough() override {
        pizza_->setDough("cross");
    }

    void buildSauce() override {
        pizza_->setSauce("mild");
    }

    void buildTopping() override {
        pizza_->setTopping("ham and pineapple");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_;
};

// Director class
class Waiter {
public:
    void setPizzaBuilder(PizzaBuilder* builder) {
        pizzaBuilder_ = builder;
    }

    Pizza* getPizza() {
        return pizzaBuilder_->getPizza();
    }

    void constructPizza() {
        pizzaBuilder_->buildDough();
        pizzaBuilder_->buildSauce();
        pizzaBuilder_->buildTopping();
    }

private:
    PizzaBuilder* pizzaBuilder_;
};

int main() {
    Waiter waiter;

    PizzaBuilder* hawaiianPizzaBuilder = new HawaiianPizzaBuilder();

    waiter.setPizzaBuilder(hawaiianPizzaBuilder);
    waiter.constructPizza();

    Pizza* pizza = waiter.getPizza();
    pizza->showPizza();

    delete hawaiianPizzaBuilder;
    delete pizza;

    return 0;
}
