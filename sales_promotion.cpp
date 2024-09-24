/* This program calculates the sales price of two items with a "buy two items get the cheapest
 * one half price" promotion (base price). If the customer has  discount card a 10% discount 
 * is applied (discount prize). The final price is calculated by adding tax (final price).
 * The base, discount and final prices are displayed. 
 */

#include <iostream> 
using namespace std;

int main(){

    int price1, price2;
    char clubCard;
    float tax, basePrice, discountPrice, halfPrice, finalPrice;

    cout<<"Enter price of first item: ";
    cin>>price1;

    cout<<"Enter price of second item: ";
    cin>>price2;

    cout<<"Does the costumer have a club card? (Y/N) ";
    cin>>clubCard;

    cout<<"Tax rate, e.g. 5.5 for 5.5% tax:";
    cin>>tax;

    basePrice=price1+price2;

    if (price1 != price2){                              // Selects the cheapest item for 50% discount
        if (price2 < price1)
        {
            halfPrice = price1 + 0.5 * price2;
        }
        if (price1 < price2)
        {
            halfPrice = price2 + 0.5 * price1;
        }
    }
    else{
        halfPrice = price1 + 0.5 * price2;
    }


    if(clubCard=='y'){                                   //applies extra discount if member
        discountPrice = halfPrice*0.9;                   
    }
    else{
        discountPrice = halfPrice;
    }

    finalPrice=discountPrice*(1+(tax/100));

    cout<<"Base price: "<<basePrice<<endl;
    cout<<"Price after discounts: "<<discountPrice<<endl;
    cout<<"Total price: "<<finalPrice<<endl;










}
