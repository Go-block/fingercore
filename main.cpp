#include <iostream>
#include <stdio.h>
#include "keys.hpp"



void get_message(const char *data){
	char _data;
	std::cin>>_data;
	data = &_data;
}

int main(){
	const char *text;
	std::cout<<"input data: ";
	get_message(text);
}

