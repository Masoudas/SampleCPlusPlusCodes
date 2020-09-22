/**
When mixing an unsigned and signed integral variable of the same type, the result is promoted to unsigned. Why is
this the case? Because supposedly the unsigned has a larger range than the signed variable.

int x = -10;
unsigned int y = 5;

cout << x + y << endl;

Now in this expression, we're mixing an int with an unsigned int. Hence, int is promoted to unsigned (2^w - x). 
Hence, the result is a gigantic number.

Note that the same situation happens with literals.

cout << -10 + 10u << endl; Here, 10 is promoted to uint. However, the result still fits a uint, so we're good.
cout << -10 + 9u << endl; Here, the result is a gigantic positive number, because we're assigning a negative value to an unsigned literal.
*/
