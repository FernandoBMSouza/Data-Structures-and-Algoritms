#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coefficient;
    int exponent;
};

struct Polynomial
{
    int numberOfTerms;
    struct Term* terms;
};

int evaluate(struct Polynomial* polynomial, int x)
{
    int sum = 0;
    for(int i = 0; i < polynomial->numberOfTerms; i++)
    {
        sum += polynomial->terms[i].coefficient * pow(x, polynomial->terms[i].exponent);
    }
    return sum;
}

struct Polynomial add(struct Polynomial* firstPolynomial, struct Polynomial* secondPolynomial)
{
    struct Polynomial result;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < firstPolynomial->numberOfTerms && j < secondPolynomial->numberOfTerms)
    {
        if(firstPolynomial->terms[i].exponent > secondPolynomial->terms[j].exponent)
        {
            result.terms[k++] = firstPolynomial->terms[i++];
        }
        else if(firstPolynomial->terms[i].exponent < secondPolynomial->terms[j].exponent)
        {
            result.terms[k++] = secondPolynomial->terms[j++];
        }
        else
        {
            result.terms[k] = firstPolynomial->terms[i++];
            result.terms[k++].coefficient += secondPolynomial->terms[j++].coefficient;
        }
    }

    for (; i < firstPolynomial->numberOfTerms; i++) result.terms[k++] = firstPolynomial->terms[i];
    for (; j < secondPolynomial->numberOfTerms; j++) result.terms[k++] = secondPolynomial->terms[j];
    result.numberOfTerms = k;
    return result;    
}

int main()
{
    struct Polynomial polynomial;

    printf("Enter number of terms: ");
    scanf("%d", &polynomial.numberOfTerms);

    polynomial.terms = (struct Term*)malloc(sizeof(struct Term) * polynomial.numberOfTerms);
    
    printf("Enter polynomial terms (coefficient - exponent): \n");
    for(int i = 0; i < polynomial.numberOfTerms; i++)
    {
        scanf("%d %d", &polynomial.terms[i].coefficient, &polynomial.terms[i].exponent);
    }

    printf("Evaluation: %d \n", evaluate(&polynomial, 2));

    return 0;
}