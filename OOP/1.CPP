#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Cars{
    private:
    //member variables or data member
    string c_name;
    string model_name;
    string fuel_type;
    float mileage;
    double price;
    
    public:
    ///member functions
         void setData(string cname,string mname, string ftype, float m,double p){
             c_name=cname;
             model_name=mname;
             fuel_type=ftype;
             mileage=m;
             price=p;
         }
         void display_Data(){
             cout<<"Company: "<<c_name;

         }



};
int main()
{
    Cars car1;
    car1.setData("tata","nexon","diesel",20,200000);
    car1.display_Data();
    return 0;

}