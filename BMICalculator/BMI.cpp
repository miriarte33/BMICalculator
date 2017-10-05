//
//  BMI.cpp
//  BMICalculator
//  Manrique Iriarte
// 10/5/17
// c++

#include <iostream>

using namespace std;

//Stores the users personal data
class BMICalculator {
public:
    int feet;
    int inches;
    double weight;//in pounds
    void output();//outputes the user's personal info
    
private:
    double height();//converts the height to inches
    double convert_to_meters(); //converts the height from inches to meters
    double convert_to_kg();//converts the weight from pounds to kilograms
    double square_meters();//takes meters and squares it
    double BMI_results();//calculates the users BMI
};

int main()
{
    BMICalculator userdata;//will be input by the users and will store it into the class
    
    cout << "Welcome to my BMI calculator program!"<< endl;
    cout << "How tall are you? First, enter feet, then enter inches." << endl << "Feet: ";
    cin >> userdata.feet;
    cout << "Inches: ";
    do {
        cin >> userdata.inches;
        
        if (userdata.inches >=12|| userdata.inches <=0)
        {
            cout << "The number for inches must be between 0 and 12."<<endl<<"Enter again: ";
        }
    } while (userdata.inches >= 12 || userdata.inches <= 0);//ensures the user enters a valid answer
    
    cout << "How much do you weigh in pounds? Decimal values are OK." << endl;
    cin >> userdata.weight;
    
    userdata.output();
    
    return 0;
}

void BMICalculator::output ()
{
    //int userheight = height ();
    cout << "You are "<< feet << "' " << inches << "'' " << endl << "You weigh " << weight << " pounds."<<endl << "Your BMI is " << BMI_results() <<" kilograms per meters squared."<<endl;
}

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

double BMICalculator::BMI_results()
{
    double BMI = convert_to_kg()/square_meters();
    return BMI;
}





