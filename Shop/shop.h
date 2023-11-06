#ifndef SHOP_HPP
#define SHOP_HPP

#include <vector>

enum CustomerSM {Init, Approaching, Inspecting, Checkout, Leaving, Gone} customer_status;

void tick_custr(){
    switch(customer_status){            // State Transitions
        case Init:  customer_status = Init; break;

        default: customer_status = Init; break;    
    }
    switch(customer_status){            // State Actions
        case Init: break;
    }
}

struct Customer{    // These are the only objects required for shop interaction. 
    int money;    
    int customer_status = Init;   
};

class Shop{     // A status-check for a shop. {Customers, Products, Services, Operations}
private:
    std::vector<Customer> population;       
    // queue for checkout
    // collection of items. this list must have constant status-checks to ensure no-thefts. 
    // collection of containers containing items. 
    // collection of stations
    // collection of shop-services
public:
    // Constructor
    Shop();

    // Accessor
    void addCustomer(Customer new_person);
    void removeCustomer(int this_person);
    Customer inspectCustomer();

    // Functions
    void shop_status();
    
};  



#endif // SHOP_HPP