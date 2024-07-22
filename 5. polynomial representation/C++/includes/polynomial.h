#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cmath>
#include <iostream>

struct Term
{
    int coefficient;
    int exponent;
};

class Polynomial
{
private:
    int numberOfTerms;
    Term* terms;
public:
    Polynomial(int numberOfTerms);
    ~Polynomial();
    int evaluate(int x);
    Polynomial operator+(Polynomial& other);
    friend std::istream& operator>>(std::istream& input, Polynomial& polynomial);
    friend std::ostream& operator<<(std::ostream& output, const Polynomial& polynomial);
};

Polynomial::Polynomial(int numberOfTerms)
{
    this->numberOfTerms = numberOfTerms;
    terms = new Term[this->numberOfTerms];
}

Polynomial::~Polynomial()
{
    delete[] terms;
}

int Polynomial::evaluate(int x)
{
    int result = 0;
    for(int i = 0; i < numberOfTerms; i++)
    {
        result += terms[i].coefficient * std::pow(x, terms[i].exponent);
    }
    return result;
}

Polynomial Polynomial::operator+(Polynomial& other)
{
    Polynomial result(numberOfTerms + other.numberOfTerms);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < numberOfTerms && j < other.numberOfTerms)
    {
        if(terms[i].exponent > other.terms[j].exponent)
        {
            result.terms[k++] = terms[i++];
        }
        else if(terms[i].exponent < other.terms[j].exponent)
        {
            result.terms[k++] = other.terms[j++];
        }
        else
        {
            result.terms[k].exponent = terms[i].exponent;
            result.terms[k++].coefficient = terms[i++].coefficient + other.terms[j++].coefficient;
        }
    }

    for (; i < numberOfTerms; i++) result.terms[k++] = terms[i];
    for (; j < other.numberOfTerms; j++) result.terms[k++] = other.terms[j];
    result.numberOfTerms = k;

    return result;    
}

std::istream& operator>>(std::istream& input, Polynomial& polynomial)
{
    std::cout << "Enter polynomial terms (coefficient - exponent): \n";
    for(int i = 0; i < polynomial.numberOfTerms; i++)
    {
        std::cin >> polynomial.terms[i].coefficient 
                 >> polynomial.terms[i].exponent;
    }
    std::cout << '\n';
    return input;
}

std::ostream& operator<<(std::ostream& output, const Polynomial& polynomial)
{
    for(int i = 0; i < polynomial.numberOfTerms; i++)
    {
        if(polynomial.terms[i].exponent == 0)
        {
            std::cout << polynomial.terms[i].coefficient
                      << "x^"
                      << polynomial.terms[i].exponent;
        }
        else
        {
            std::cout << polynomial.terms[i].coefficient
                      << "x^"
                      << polynomial.terms[i].exponent
                      << " + ";
        }
    }
    return output;
}

#endif