#include<iostream>
using namespace std;

class Distance{
    private:
         int meters;
    public:
        ///constructor function
        Distance()
        {
            meters=0;
        }
        void displayData()
        {
            cout<<"Metres value:"<< meters;

        }

        friend void addValue(Distance &d);


};

void addValue(Distance &d){
    d.meters=d.meters+5;
}

int main(){
    Distance d1;
    d1.displayData();

    addValue(d1); //pass  by refrence
    d1.displayData();
    return 0;
}