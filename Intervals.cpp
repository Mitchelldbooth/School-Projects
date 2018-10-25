/////////Mitchell Booth///////////
//////// Project 1 Part B////////

////////Intervals.cpp////////


#include<iostream>
#include<cmath>
#include<algorithm>

int main();
void print(double a,double b);


int main()
{
	std::string input; //////reads the entered commands

	double parameters[2] = {0,0};  /////parameters that the user inputs
	double interval_parameters[2] = {0,0};

	double immediate[2] = {0,0}; ///immediate memory that in stored once entered
	bool immediate_initalized = false; ///// boolean keeps track of when or not any memory is stored

	double memory[2] = {0,0};	////when mr command is entered immediate memory is copied here
	bool memory_initalized = false; //// boolean to keep track of wether or not any memory is stored




	while (true) ////if the input is anything other then "exit" then continuosly run these commands
	{
		std::cout << "input :> ";
		std::cin >> input;


		if(input == "exit" )
		{
			break;
		}


		else if(input == "enter") ////allows user to enter values and copies them to immediate memeory
		{

			std::cin >> parameters[0] >> parameters[1];

			if(parameters[0] > parameters[1]) ///// invalid intervals are when a > b
			{								/////// first number must always be less than second


				//////////a must be less than b is true for ALL entered commands, you will see this repeated at the top of each command////

				if(!immediate_initalized)
				{

					std::cout << "Error: invalid interval as " << parameters[0] << " > " << parameters[1];
					std::cout << std::endl;
					std::cout << "--";
					std::cout << std::endl;


				}
				else
				{

				std::cout << "Error: invalid interval as " << parameters[0] << " > " << parameters[1];
				std::cout << std::endl;
				print(immediate[0],immediate[1]);
				std::cout << std::endl;
				}
			}
			else
			{
			 print(parameters[0],parameters[1]);

			 immediate[0] = parameters[0]; ////setting immediate value array to values entered
			 immediate[1] = parameters[1];

			 std::cout << std::endl;

			 immediate_initalized = true; //// immediate memory is now initialzed

			}

		}

		else if (input == "negate") ///turns all posotive numbers negative
		{
			if (!immediate_initalized)
			{
				std::cout << "--";
				std::cout << std::endl;
			}
			else
			{
				double temp;

				temp = -immediate[0]; ///// when values are negated a must still be less that b ( a < b)
				immediate[0] = - immediate[1]; //////this reverses the values to allow for that condition to be true
				immediate[1] = temp;

				print(immediate[0],immediate[1]);
				std::cout << std::endl;


			}

		}

		else if (input == "invert") ////// same as 1/a and 1/b///
		{
			if (!immediate_initalized)
					{
						std::cout << "--";
						std::cout << std::endl;
					}
			else if (immediate[0] <= 0 && immediate[1] >= 0) ////however if the interval entered contains a zero (ex -1 -- 3) then you are dividing by zero at some point
			{
				std::cout << "Error: division by zero" << std::endl; //// if you do this an error is printed
				std::cout << "--";
				std::cout << std::endl;


				immediate_initalized = false; ///// the immediate interval is no longer initialized if you divide by zero
			}

			else
			{
				double temp;
				temp = 1 / immediate[0]; ///// if there is no zero, complete the operation 1/a 1/b
				immediate[0] = 1 / immediate[1];  //// however b will now be less than a so we need to re arrange interval
				immediate[1] = temp;

				print(immediate[0],immediate[1]);
				std::cout << std::endl;

			}

		}

		else if (input == "ms") //// if a immediate interval is initialized copy it to memory stored
		{
			if (!immediate_initalized)
					{
					std::cout << "--";
					std::cout << std::endl;
					}
			else
			{
				print(immediate[0],immediate[1]);

				memory[0] = immediate[0];
				memory[1] = immediate[1];

				std::cout << std::endl;

				memory_initalized = true;

			}
		}

		else if(input == "mr") //// if there is no stored memory but immediate memory print it out
		{
			if (!memory_initalized)
					{
				if(!immediate_initalized)
					{
					std::cout << "--";
					std::cout << std::endl;
					}
				else
				{
					print(immediate[0],immediate[1]);
					std::cout << std::endl;
				}

					}
			else
			{
				if(!immediate_initalized) ////if there is stored memory but no immediate do nothing
				{
					std::cout << "--";
					std::cout << std::endl;
				}


				else
				{

				immediate[0]= memory[0];	///if there is both values, copy the memory stored to the immediate inteval
				immediate[1]= memory[1];

				print(immediate[0],immediate[1]); /// the immediate and stored intervals are now the same
				std::cout << std::endl;
				}



			}
		}

		else if (input == "mc") //// if there is a immediate interval clear the stored interval
		{
			if (!immediate_initalized)
					{
					std::cout << "--";
					std::cout << std::endl;
					}
			else
			{
				print(immediate[0],immediate[1]);
				std::cout << std::endl;

				memory_initalized = false;

			}
		}
		else if (input == "m+") /////if there is an immediate and stored interval, add the immediate to the stored memory interval
		{
			if (!immediate_initalized)
								{
								std::cout << "--";
								std::cout << std::endl;
								}
			else if(!memory_initalized)
			{
				print(immediate[0],immediate[1]);
				std::cout << std::endl;

			}

			else
			{
				memory[0] += immediate[0]; // the memory becomes memory + immediate intervals
				memory[1]+= immediate[1];

				print(immediate[0],immediate[1]);
				std::cout << std::endl;
			}


		}
		else if (input == "m-")////subtract the immediate interval from the memory
				{
					if (!immediate_initalized || !memory_initalized)
										{
										std::cout << "--";
										std::cout << std::endl;
										}


					else
					{
						memory[0] -= immediate[0];
						memory[1]-= immediate[1];

						print(immediate[0],immediate[1]);
						std::cout << std::endl;
					}


				}

		else if (input == "scalar_add") /// adding a scalar to each end of the interval
		{
			double c;
			std::cin >> c;

			if (!immediate_initalized)
			{
				std::cout << "--";
				std::cout << std::endl;
			}
			else
			{


				immediate[0]+= c;
				immediate[1]+=c;

				print(immediate[0],immediate[1]);
				std::cout << std::endl;

			}

		}

		else if (input == "scalar_subtract") //// subtract a scalar from each end of the interval
			{

			double c;
			std::cin >> c;



			if (!immediate_initalized)
				{
					std::cout << "--";
					std::cout << std::endl;
				}
				else
				{

					immediate[0]-= c;
					immediate[1]-=c;

					print(immediate[0],immediate[1]);
					std::cout << std::endl;

				}

			}
		else if (input == "scalar_multiply") /// multiply each end by a scalar
					{


			double c;
			std::cin >> c;


			if (!immediate_initalized)
						{
							std::cout << "--";
							std::cout << std::endl;
						}
						else
						{

							immediate[0]*= c;
							immediate[1]*=c;

							if (immediate[0] > immediate[1]) //// if the scalar is negative we must re arrange because b will now be less than a ( a>b ) which is not valid
							{
								double temp;
								temp = immediate[0];
								immediate[0] = immediate[1];
								immediate[1] = temp;

							}
							print(immediate[0],immediate[1]);
							std::cout << std::endl;

						}

					}
		else if (input == "scalar_divide") /// divide each end by a scalar c
							{
							double c;
							std::cin >> c;


								if (!immediate_initalized)
								{
									std::cout << "--";
									std::cout << std::endl;
								}
								else
								{

									if(c == 0) /// if the user tries to divide by zero and error is printed
									{
									std::cout << "Error: divide by 0";
									std::cout << std::endl;
									std::cout << "--";
									std::cout << std::endl;

									immediate_initalized = false; //// this error un-initilaizes the immediate interval
									}

									else
									{
										immediate[0]/= c;
										immediate[1]/= c;

										if (immediate[0] > immediate[1]) //// again if you divide by a negative you must re arrange the interval to be valid
										{
										double temp;
											temp = immediate[0];
											immediate[0] = immediate[1];
											immediate[1] = temp;
										}

										print(immediate[0],immediate[1]);
										std::cout << std::endl;
									}
								}
							}
		else if (input == "scalar_divided_by") /// allows the user to divide by zero, but not if the interval contains zero
									{
									double c;
									std::cin >> c;

									if (!immediate_initalized)
										{
											std::cout << "--";
											std::cout << std::endl;
										}
										else
										{


											if(immediate[0] <= 0 && immediate[1] >= 0) // if the interval does contain zero, un-initialie it
											{
											std::cout << "Error: divide by 0";
											std::cout << std::endl;
											std::cout << "--";
											std::cout << std::endl;

											immediate_initalized = false;

											}

											else
											{
												immediate[0]/= c;
												immediate[1]/= c;

												if (immediate[0] > immediate[1])
												{
												double temp;
													temp = immediate[0];
													immediate[0] = immediate[1];
													immediate[1] = temp;
												}

												print(immediate[0],immediate[1]);
												std::cout << std::endl;
											}
										}
									}


		else if (input == "interval_add") //// enter an interval and add the first terms in the entered interval to the immediate
		{									// do the same thing with the second terms (a+c , a+d)

			std::cin >> interval_parameters[0] >> interval_parameters[1];

			if(!immediate_initalized)
				{
					if (interval_parameters[0] > interval_parameters[1])
				{


				std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
				std::cout << std::endl;
				std::cout << "--";
				std::cout << std::endl;
				}
				else
					{
						std::cout << "--";
						std::cout << std::endl;
					}
				}
			else /////depending on numbers enetered we may have to re arrange
			{
				if (interval_parameters[0] > interval_parameters[1])
					{
					std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
					std::cout << std::endl;

					print(immediate[0],immediate[1]);
					std::cout << std::endl;
					}
				else
				{
					immediate[0] += interval_parameters[0];
					immediate[1] += interval_parameters[1];

					print(immediate[0],immediate[1]);
					std::cout << std::endl;

				}

			}

	}

		else if (input == "interval_subtract") //// enter an interval and add the first terms in the entered interval to the immediate
		{										//// do the same with the second terms (a+c, a+d)
			std::cin >> interval_parameters[0] >> interval_parameters[1];

						if(!immediate_initalized)
							{
								if (interval_parameters[0] > interval_parameters[1])
							{


							std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
							std::cout << std::endl;
							std::cout << "--";
							std::cout << std::endl;
							}
							else
								{
									std::cout << "--";
									std::cout << std::endl;
								}
							}
						else
						{
							if (interval_parameters[0] > interval_parameters[1])
								{
								std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
								std::cout << std::endl;

								print(immediate[0],immediate[1]);
								std::cout << std::endl;
								}
							else
							{
								immediate[0] -= interval_parameters[1];
								immediate[1] -= interval_parameters[0];

								print(immediate[0],immediate[1]);
								std::cout << std::endl;

							}

						}
		}

		else if (input == "interval_multiply") /// multiply all the terms in the immediate by the terms in the entered interval
		{								//// print our the minimmum and maximum and that is our new immediate interval
			std::cin >> interval_parameters[0] >> interval_parameters[1];

						if(!immediate_initalized)
							{
								if (interval_parameters[0] > interval_parameters[1])
							{


							std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
							std::cout << std::endl;
							std::cout << "--";
							std::cout << std::endl;
							}
							else
								{
									std::cout << "--";
									std::cout << std::endl;
								}
							}
						else
						{
							if (interval_parameters[0] > interval_parameters[1])
								{
								std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
								std::cout << std::endl;

								print(immediate[0],immediate[1]);
								std::cout << std::endl;
								}
							else
							{
								double a, b, c ,d;
								a = immediate[0] * interval_parameters[0]; /////do all possible multiplications
								b = immediate[0] * interval_parameters[1];
								c = immediate[1] * interval_parameters[0];
								d = immediate[1] * interval_parameters[1];



								immediate[0] = std::min(std::min(std::min(a,b),c),d); ////store the min and max of all the multiplications
								immediate[1] = std::max(std::max(std::max(a,b),c),d);

								print(immediate[0],immediate[1]);
								std::cout << std::endl;
							}

						}



		}
		else if (input == "interval_divide") /// divide every term in the immediate interval by every term in the user entered interval
				{							//// print out min and max of there values, this is your new immediate interval

					std::cin >> interval_parameters[0] >> interval_parameters[1];

								if(!immediate_initalized)
									{
										if (interval_parameters[0] > interval_parameters[1])
									{


									std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
									std::cout << std::endl;
									std::cout << "--";
									std::cout << std::endl;
									}
									else
										{
											std::cout << "--";
											std::cout << std::endl;
										}
									}
								else
								{
									if (interval_parameters[0] > interval_parameters[1])
										{
										std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
										std::cout << std::endl;

										print(immediate[0],immediate[1]);
										std::cout << std::endl;
										}

									else if (interval_parameters[0] <= 0 && interval_parameters[1] >= 0) /// if the interval entered contains a zero, a divide by zero error is issued
									{
										std::cout << "Error: division by zero";
										std::cout << std::endl;
										std::cout << "--";
										std::cout << std::endl;

										immediate_initalized = false; //// immediate memory is now un-initialized if you divide by zero
									}


									else
									{
										double a, b, c ,d;
										a = immediate[0] / interval_parameters[0];
										b = immediate[0] / interval_parameters[1];
										c = immediate[1] / interval_parameters[0];
										d = immediate[1] / interval_parameters[1];



										immediate[0] = std::min(std::min(std::min(a,b),c),d);
										immediate[1] = std::max(std::max(std::max(a,b),c),d);

										print(immediate[0],immediate[1]);
										std::cout << std::endl;
									}

								}



				}
		else if (input == "intersect") ///where do the ranges of the immediate interval and user entered interval intersect
										///print this intersecting range
		{

			std::cin >> interval_parameters[0] >> interval_parameters[1];

						if(!immediate_initalized)
							{
								if (interval_parameters[0] > interval_parameters[1])
							{


							std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
							std::cout << std::endl;
							std::cout << "--";
							std::cout << std::endl;
							}
							else
								{
									std::cout << "--";
									std::cout << std::endl;
								}
							}
						else
						{
							if (interval_parameters[0] > interval_parameters[1])
								{
								std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
								std::cout << std::endl;

								print(immediate[0],immediate[1]);
								std::cout << std::endl;
								}


							else if( immediate[1] < interval_parameters[0] || interval_parameters[1] < immediate[0] )
								{
								 std::cout << "--";
								 std::cout << std::endl;

								 immediate_initalized = false; ///// if there is no intersection, then un-initialize the immediate interval

								}

							 else
							 {
								 immediate[0] = std::max(immediate[0],interval_parameters[0]);
								 immediate[1] = std::min(immediate[1], interval_parameters[1]);

								 print(immediate[0],immediate[1]);
								 std::cout << std::endl;


							 }

						}



		}

		else if(input == "integers") /// prints out all whole numbers within the range of the immediate interval
		{
			if(!immediate_initalized)
			{
				std::cout << "--";
				std::cout << std::endl;
			}
			else
			{
				double a;
				a = ceil(immediate[0]);

				while ( a <= floor(immediate[1]))
				{


					std::cout << a << ", ";


					a++;

				}
				std::cout << std::endl;

				print(immediate[0],immediate[1]);
				 std::cout << std::endl;

			}




		}

		else if (input == "cartesian_integers") /// prints out all cartesin integers within the immediate and user entered range
		{
			std::cin >> interval_parameters[0] >> interval_parameters[1];


			if(!immediate_initalized)
					{
						if (interval_parameters[0] > interval_parameters[1])
					{


					std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
					std::cout << std::endl;
					std::cout << "--";
					std::cout << std::endl;
					}
					else
						{
						std::cout << "--";
						std::cout << std::endl;
						}
					}

			else
				{
					if (interval_parameters[0] > interval_parameters[1])
						{
							std::cout << "Error: invalid interval as " << interval_parameters[0] << " > " << interval_parameters[1];
							std::cout << std::endl;

							print(immediate[0],immediate[1]);
							std::cout << std::endl;
						}

					else
						{
							double a, b, c, d; ////// calculations for range of cartesian integers

							a = std::ceil(immediate[0]); /////use ceil and floor to convert doubles from whole numbers
							b = std::floor(immediate[1]);
							c = std::ceil(interval_parameters[0]);
							d = std::floor(interval_parameters[1]);

							if(c > d)
							{
								print(immediate[0],immediate[1]);
								std::cout << std::endl;
							}

							else
							{

								for(double lower = a; lower <=b; ++lower )
								{
									for(double upper = c; upper <= d; ++upper)
									{


										std::cout << "(" << lower  << ", "<< upper << "), ";

									}


								}

								std::cout << std::endl;
								print(immediate[0],immediate[1]);
								std::cout << std::endl; ////////

							}

						}





				}


		}


		else //// if none of the allowed commands are entered print error and the loop is restarted, again asking the user for the input
		{

			std::cout << "Error: illegal command ";
			std::cout << std::endl;
		}







	}

	std::cout << " Bye bye: Terminating interval calculator program."; /// when "exit" is entered the look is broken and the program is terminated

	return 0;
}

void print(double a,double b)

{
	std::cout << "[" << a << ", " << b << "]";
}







