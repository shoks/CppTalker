#include <iostream>
#include "ExampleModel.h"

int main(int argc, char* argv[])
{
	std::cout << "for testing purpose..." << std::endl;

	auto example = std::make_unique<ExampleModel>();
	example
	->Add("id", "56987")
	->Add("users", "shoks")
	->Add("password", 123456);
}
