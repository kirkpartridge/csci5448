#include <iostream>
#include "./include/TransactionType.h"

int main( int argc, char **argv )
{
    TransactionType test;
	std::cout<< "Here\n";
	std::cout<< test.ToCSV();
    
	return 1;
}
