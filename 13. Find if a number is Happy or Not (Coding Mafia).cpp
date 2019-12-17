#include<iostream>


using namespace std;

int main()
{
  int k[20], number,tens_digit,units_digit;
  cout << " Enter the two digit number you want to check for happiness : \n";
  cin >> number;
  for ( int i=0; i<100 ; i++)
  {
      units_digit = number%10;
      tens_digit = number-units_digit;
      number = (tens_digit * tens_digit) + (units_digit * units_digit) ;
      k[i] = number;
      for ( int j=0; j<i ; j++)
        if ( k[j]==k[i] )
        {
            number = 0;
            goto l;
        }
        else if ( k[i] == 1)
            goto m;
  }
   l: if( number ==0 )
    {
        cout << "The number you entered is not a Happy number ";
     return 0;
    }
   m:
      cout << "The number you entered is a happy number";
      return number;
}
