#ifndef CAR_H
#define CAR_H

using namespace std;


//Place your code here

class Car {
    string sBrand;

    string sModel;

    int nYear;
public:
    Car(string & brand, string & model, int & year);

    string GetBrand() const;
    string  GetModel() const;
    int GetYear() const;

};

string Car::GetBrand() const
{
    return sBrand;
}

string Car::GetModel() const
{
    return sModel;
}

int Car::GetYear() const
{
    return nYear;
}


/////////////////////////////////////////////////////


Car::Car(string& brand, string& model, int& year)
{
     sBrand = brand;
     sModel = model;
     nYear = year;
}




#endif // !CAR_H
