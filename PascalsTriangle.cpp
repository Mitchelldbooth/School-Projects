///////////MITCHELLL BOOTH/////////////

/////////////Project 1////////////////


	////Problem 0///////

#include <iostream>
#include <cmath>



int pascal_triangle(int n);
int pascal_triangle_recursive(int n);


#ifndef MARMOSET_TESTING


int main();

#endif

//////Variables for recursion////
int row = 0;
int col = 0;
int num = 1;
int counter = 0;



#ifndef MARMOSET_TESTING
int main()
{

	int n = 3;

	std::cout << pascal_triangle(n);
	std::cout << std::endl;
	std::cout << pascal_triangle_recursive(n);








return 0;

}
#endif


int pascal_triangle(int n)
{
///Iterative method/////

int count = 0;////counts how many integers are in triangle///

	for (int i = 0; i <= n; i++) ////where I is less than the number of rows requested/////
	 {

		int value = 1; //This is the value of the triangle that is displayed/////


		for (int x = 0; x <= i; x++) //// x is the column so this calculates value for some x column and i row////
		{
			/// adds a space before every new value is calculated/////
			std::cout << value << " ";

			////This is the equation to calculate the value that is displayed for selected row and column///
			value = value * (i-x) / (x + 1);


			count++;/////counter for how many integers are printed////
		}
		////every time the outer loop repeats we start a new row////
		std::cout << std::endl;

	 }

	return count;
}





int pascal_triangle_recursive(int n)
{

	////Recursive Method/////

	if ( row == (n+1))
	{
		int temp = counter;


		counter = 0;
		row = 0;
		col = 0; ///// variables need to be re initialized after the triangle is printed so another number can be passed through////
		num = 0;
		std::cout << temp;

		return temp;


	}

	else if (row <= n) /////where rows is less than n or equal to n, and so this will repeat until rows = n///

	{

		for ( int col = 0 ; col <= row; col++) /////////// loop repeats for every row to calculate all values in the row///
		{
			if (col == 0)
			{
				std::cout << num << " "; ///// the first number in every row is 1;///

			}
			else
			{
				num = num * (row + 1 - col ) / (col); ///// calculates value of integers in its row and column///
				std::cout << num << " ";


			}

			counter++;//////counter keeps track of every integer so needs to be inside loop to count hoe many times we calculate a value///


		}


		row++; //// after each row is calculated we need to go to the next row//

		std::cout << std::endl;

		pascal_triangle_recursive(n); ////recalls the function to print the next row//


	}

std::cout<<temp;
}





