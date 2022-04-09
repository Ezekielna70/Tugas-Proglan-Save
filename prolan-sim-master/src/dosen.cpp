#include <iostream>

#include "include/dosen.hpp"


dosen::dosen(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, int pendidikan)
		: person(id, nama, dd, mm, yy), npp(npp), departemen(departemen), pendidikan(pendidikan)
{
}

void dosen::setPendidikan(int pendidikan)
{
	this->pendidikan = pendidikan;
}

int dosen::getPendidikan()
{
	return this->pendidikan;
}

void dosen::setDepartemen(std::string departemen)
{
	this->departemen = departemen;
}

std::string dosen::getDepartemen()
{
	return this->departemen;
}

void dosen::setnpp(std::string npp)
{
	this->npp = npp;
}

std::string dosen::getnpp()
{
	return this->npp;
}



