//
//  main.cpp
//  Polynomial.cpp
//  Operations on Polynomials Calculator
//  Created by Mitchell Booth on 2018-11-12.
//  Copyright © 2018 Mitchell Booth. All rights reserved.
//

#include <iostream>
#include "Polynomial.h"
#include <algorithm>

void print_poly(poly_t &p);
void print_poly(poly_t &p)
{
    for(std::size_t i{0}; i < p.degree +1; i++) //// print function for testing purposes
    {
        std::cout << p.a_coeffs[i] << " ";
    }
    std::cout << std::endl;
}
#ifndef MARMOSET_TESTING
int main()
{
    poly_t my_poly{nullptr, 0};
    double init1[1]{127.319433};

    init_poly(my_poly, init1, 0);
    print_poly(my_poly);
    poly_diff(my_poly);
    print_poly(my_poly);
    
    return 0;
}
#endif
void init_poly(poly_t &p, double const init_coeffs[],unsigned int const init_degree ) ///// initialize the polynomial
{
    if( p.a_coeffs!= nullptr)
    {
        destroy_poly(p);
    }
    p = poly_t{nullptr,init_degree};
    p.a_coeffs = new double[init_degree + 1]; /// creates array of coefficients
    
    
    for(std::size_t i{0}; i < init_degree + 1; i++)
    {
        p.a_coeffs[i] = init_coeffs[i];             ///// assigns passes in array coefficient values to polynomial coefficients
    }
}

void destroy_poly(poly_t &p)//// function call to destroy the polynomial in memory
{
    delete [] p.a_coeffs;
    p.a_coeffs = nullptr;
}

unsigned int poly_degree( poly_t const &p ) ///// if the polynomial has no degree throw and error
{
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    return p.degree;
}
double poly_coeff( poly_t const& p, unsigned int n ) /// returns the value of a coefficients at its degree
{
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    
    return p.a_coeffs[n];
}

double poly_val(poly_t const &p, double const x ) //// evaluate the polynomial
{
    
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    
          // Initialize evalutaed value
     double evaluated = p.a_coeffs[p.degree];
        // Evaluate value of polynomial using Horner's method
    for(int i = p.degree - 1; i >= 0; --i)
    {
        evaluated *= x;
        evaluated += p.a_coeffs[i];
    }
    return evaluated;
}


void poly_add( poly_t &p, poly_t const &q ) /// add 2 polynomials
{
    if(p.a_coeffs == nullptr || q.a_coeffs == nullptr)
    {
        throw 0;
    }
    
    double temp[std::max( p.degree , q.degree) + 1]; ////new array is the size of the largers of the 2 passed in
    for(std::size_t i{0}; i < std::max(p.degree, q.degree) + 1; ++i)
    {
        temp[i] = 0;
    }
    
    for(std::size_t i{0}; i < std::max(p.degree, q.degree)+1; i++ )
    {
        if(i <= p.degree)
        {
            temp[i] += p.a_coeffs[i]; ////// add the two polynomials depending on the degreee
        }
        
        if(i <= q.degree)
        {
            temp[i] += q.a_coeffs[i];
        }
   
    }
    
    unsigned int deg{std::max(p.degree, q.degree)+1};
    
    for(std::size_t i{std::max(p.degree, q.degree)+1}; i >= 0; i-- )
    {
        if(temp[i] == 0) //// if a value is added to another such that the result is zero, decrease the degree
        {
            deg--;
        } else break;
        
    }
    destroy_poly(p);
    
    p.a_coeffs = new double[deg + 1];
    
    for(std::size_t i{0}; i < deg + 1; i ++) //// set the polynomila to the new added values
    {
        p.a_coeffs[i] = temp[i];
    }
    
    p.degree = std::max(p.degree, q.degree);
}
    
void poly_subtract( poly_t &p, poly_t const &q )
{
    if(p.a_coeffs == nullptr || q.a_coeffs == nullptr)
    {
        throw 0;
    }
    
    double temp[std::max( p.degree , q.degree) + 1];
    for(std::size_t i{0}; i < std::max(p.degree, q.degree) + 1; ++i)
    {
        temp[i] = 0;
    }
    
    for(std::size_t i{0}; i < std::max(p.degree, q.degree)+1; i++ )
    {
        if(i <= p.degree)
        {
            temp[i] += p.a_coeffs[i];
        }
        
        if(i <= q.degree)
        {
            temp[i] -= q.a_coeffs[i];
        }
        
    }
    
    unsigned int deg{std::max(p.degree, q.degree)+1};
    
    for(std::size_t i{std::max(p.degree, q.degree)+1}; i >= 0; i-- )
    {
        if(temp[i] == 0) ///// if the subtraction of 2 values of the same degree results in zero, decrease the degree
        {
            deg--;
        } else break;
        
    }
    destroy_poly(p);
    
    p.a_coeffs = new double[deg + 1];
    
    for(std::size_t i{0}; i < deg + 1; i ++)
    {
        p.a_coeffs[i] = temp[i];
    }
    
    p.degree = std::max(p.degree, q.degree);
    
}

void poly_multiply(poly_t&p, poly_t const &q )
{
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    
    double *prod = new double [p.degree + q.degree + 1]{};
   
    for (int i=0; i< p.degree + 1 ; i++) // Multiply two polynomials term by term
    {
        
        for (int j=0; j< q.degree + 1; j++)
            prod[i+j] += p.a_coeffs[i]*q.a_coeffs[j]; //// when multiply polynomials the new degree is the addition of the two existing degrees
    
    }
    
    
    p.degree = p.degree + q.degree;
    destroy_poly(p);
    p.a_coeffs = prod;
    prod = nullptr;
    
    
}


double poly_divide( poly_t &p, double r )
{
    double remainder{0};
    
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    

    if(p.degree != 0)
    {
    double *divide = new double[p.degree+1]{}; ///// use syntectic division to create new polynomial///
    divide[p.degree -1] = p.a_coeffs[p.degree];
    double count = p.a_coeffs[p.degree];
    for(std::size_t i{p.degree-1}; i > 0; i--)
    {

        count = count * r;
        count += p.a_coeffs[i];
        divide[i-1] = count;
    }
    count *= r;
    count += p.a_coeffs[0];  /////// the last term is the remainder
    remainder = count;
    destroy_poly(p);
    p.a_coeffs = divide;
    p.degree -= 1;
    divide = nullptr;
    }
    
    else
    {
        remainder = p.a_coeffs[0]; //// if the polynomial has a degree of zero, ie a contsant then the remiander is the passed polynomial
        p.a_coeffs[0] = 0;
       
    }
    
    return remainder;
    
}



void poly_diff( poly_t&p )
{
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    
    if(p.degree != 0)
    {
        double *diff = new double[p.degree + 1]{};
        for(std::size_t i{0}; i < p.degree; i++ )
    {
        diff[i] = p.a_coeffs[i + 1] * (i+1);     ///// every derms degree decreases by one, the coefficient is multiply by the previous degree
    
    }
        destroy_poly(p);
        p.a_coeffs = diff;
        p.degree -= 1;
        diff = nullptr;
        
    }
    else
    {
        p.a_coeffs[0] = 0; //// taking the derivative of a contsant gives zero
    }
    
}



double poly_approx_int(poly_t const&p,double a, double b,unsigned int n )
{
    if(p.a_coeffs == nullptr)
    {
        throw 0;
    }
    //// integral approximation using trapezoid formuale
    
    double h = (b-a)/ n;
    
    double sum = poly_val(p, a); ///// first and last care are handled seperately
    for(std::size_t  i{1};  i <  n ; i++ )
    {
        sum += 2 * poly_val(p, a + (i*h)); //// handles every in between case
    
    }
    sum += poly_val(p, b);
    sum = sum * h / 2.0;
    return sum ;
}


