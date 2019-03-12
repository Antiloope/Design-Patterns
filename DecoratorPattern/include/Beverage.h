#ifndef BEVERAGE_H
#define BEVERAGE_H



///////////////////////

//      Component

///////////////////////

/// Abstract class Beverage
class Beverage {
    public:
        Beverage(){};
        float virtual getCost()=0;
    protected:
    private:
};


////////////////////////////////

//      Concrete Component

////////////////////////////////

///One kind of beverage
class Coffe : public Beverage{
    public:
        Coffe(){};
        float getCost(){
            return 10.0; //This is the base cost of a Coffe
        }
     protected:
     private:
};

///Another kind of beverage
class Tea : public Beverage{
    public:
        Tea(){};
        float getCost(){
            return 5.0; //This is the base cost of a Coffe
        }
     protected:
     private:
};

///////////////////////

//      Decorator

///////////////////////

class Tops : public Beverage{
    public:
        Tops(Beverage *toDecorate){
            m_toDecorate = toDecorate;
        }
    protected:
        Beverage *m_toDecorate;
    private:
};

//////////////////////////////

//      Concrete Decorator

//////////////////////////////

///One kind of decorator
class Caramel : public Tops{
    public:
        Caramel(Beverage *toDecorate) : Tops(toDecorate){}
        float getCost(){
            return this->m_toDecorate->getCost() + 5.5; //5.5 is the cost of the caramel
        }
    protected:
    private:
};

///Another kind of decorator
class Cream : public Tops{
    public:
        Cream(Beverage *toDecorate) : Tops(toDecorate){}
        float getCost(){
            return this->m_toDecorate->getCost() + 3.3; //3.3 is the cost of the cream
        }
    protected:
    private:
};

///Another kind of decorator could be a discount ticket
class DiscountTicket : public Tops{
    public:
        DiscountTicket(Beverage *toDecorate) : Tops(toDecorate){}
        float getCost(){
            return this->m_toDecorate->getCost() - this->m_toDecorate->getCost() / 10; //A discount of 10%
        }
    protected:
    private:
};

#endif // BEVERAGE_H
