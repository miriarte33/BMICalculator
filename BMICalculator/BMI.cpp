//
//
//  BMICalculator
//
//  Created by Manrique Iriarte on 10/5/17.
// Updated 1/3/18.
//  Copyright © 2017 Manrique Iriarte. All rights reserved.
//

#include <iostream>
using namespace std;

//Stores the users personal data
class BMICalculator {
public:
    BMICalculator();
    BMICalculator(int theFeet, int theInches, double theWeight);
    void setFeet(int x);
    void setInches(int x);
    void setWeight(double x);
    void setBMI();
    int getFeet();
    int getInches();
    double getBMI();
    double getWeight();
    friend ostream& operator << (ostream& outs, const BMICalculator &arg);
    friend istream& operator >> (istream & ins, BMICalculator &arg);
private:
    int feet;
    int inches;
    double BMI;
    double weight;
    double height();//converts the height to inches
    double convert_to_meters(); //converts the height from inches to meters
    double convert_to_kg();//converts the weight from pounds to kilograms
    double square_meters();//takes meters and squares it
};

int main()
{
    BMICalculator userdata;
    cout << "Welcome to my BMI calculator program!"<< endl;
    cout << "Enter your data. First enter your height in feet. Then enter inches. Then enter your weight." << endl;
    cin >> userdata;
    cout << "Your BMI is " << userdata << endl;
    
    return 0;
}

//operator overloading
ostream& operator << (ostream& outs,  const BMICalculator &arg)
{
    outs << arg.BMI;
    
    return outs;
}

istream& operator >> (istream& ins, BMICalculator &arg)
{
    ins >> arg.feet;
    
    do {
        ins >> arg.inches;
        if (arg.inches >=12|| arg.inches < 0)
        {
            cout << "The number for inches must be between 0 and 12."<<endl<<"Enter again: ";
        }
    } while (arg.inches >= 12 || arg.inches < 0);
    
    ins >> arg.weight;
    
    arg.setBMI();
    
    return ins;
}

//member functions
double BMICalculator::height()
{
    double height = (feet*12)+inches;//converts the height to inches
    return height;
}

double BMICalculator::convert_to_meters()
{
    double userheight = height ();
    double height_in_meters = userheight * 0.025; //approximately converts the height from inches to meters
    return height_in_meters;
}

double BMICalculator::convert_to_kg()
{
    double weight_in_kg = weight * 0.45; //approximately converts the weight from pounds to kilograms
    return weight_in_kg;
}

double BMICalculator::square_meters()
{
    double meters_squared = convert_to_meters() * convert_to_meters();//meters squared
    return meters_squared;
}

//setters
void BMICalculator::setFeet(int x)
{
    feet = x;
}

void BMICalculator::setInches(int x)
{
    inches = x;
}

void BMICalculator::setWeight(double x)
{
    weight = x;
}

void BMICalculator::setBMI()
{
    BMI = convert_to_kg()/square_meters();
}

//constructors
BMICalculator::BMICalculator()
{
    feet = 6;
    inches = 0;
    weight = 175;
    setBMI();
}

BMICalculator::BMICalculator(int theFeet, int theInches, double theWeight)
{
    feet = theFeet;
    inches = theInches;
    weight = theWeight;
    setBMI();
}

//getters
int BMICalculator::getFeet()
{
    return feet;
}

int BMICalculator::getInches()
{
    return inches;
}

double BMICalculator::getWeight()
{
    return weight;
}

double BMICalculator::getBMI()
{
    setBMI();
    return BMI;
}

