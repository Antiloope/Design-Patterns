#include <iostream>
#include "Beverage.h"

using namespace std;

int main()
{
    Beverage* myStarBucksCoffe = new Caramel(new Caramel(new Coffe()));
    cout << "Your beverage cost: $" << myStarBucksCoffe->getCost() << endl;
    myStarBucksCoffe = new DiscountTicket(myStarBucksCoffe);
    cout << endl <<"Aplying the discount: $" << myStarBucksCoffe->getCost() << endl;
    return 0;
}
