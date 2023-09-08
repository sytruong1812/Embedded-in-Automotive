#include <iostream>
#include <string>

// Component Interface
class Pizza {
public:
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
};

// Concrete Component Class
class PlainPizza : public Pizza {
public:
    std::string getDescription() override {
        return "Thin crust pizza";
    }

    double getCost() override {
        return 5.99;
    }
};

// Decorator Class
class PizzaDecorator : public Pizza {
public:
    PizzaDecorator(Pizza* pizza) : pizza_(pizza) {}

    std::string getDescription() override {
        return pizza_->getDescription();
    }

    double getCost() override {
        return pizza_->getCost();
    }

protected:
    Pizza* pizza_;
};

// Concrete Decorator Classes
class Cheese : public PizzaDecorator {
public:
    Cheese(Pizza* pizza) : PizzaDecorator(pizza) {}

    std::string getDescription() override {
        return pizza_->getDescription() + ", Cheese";
    }

    double getCost() override {
        return pizza_->getCost() + 1.50;
    }
};

class TomatoSauce : public PizzaDecorator {
public:
    TomatoSauce(Pizza* pizza) : PizzaDecorator(pizza) {}

    std::string getDescription() override {
        return pizza_->getDescription() + ", Tomato Sauce";
    }

    double getCost() override {
        return pizza_->getCost() + 0.75;
    }
};

int main() {
    Pizza* pizza = new TomatoSauce(new Cheese(new PlainPizza()));

    std::cout << "Description: " << pizza->getDescription() << std::endl;
    std::cout << "Cost: $" << pizza->getCost() << std::endl;

    delete pizza;

    return 0;
}
