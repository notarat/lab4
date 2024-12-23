#include "gazset.h"

gazset::gazset(pipe pe, int i, cs c11, int i1, cs cs22, int i2)
{
	p = pe;
	idp = i;
	c1 = c11;
	idc1 = i1;
	c2 = cs22;
	idc2 = i2;
	if (p.GetInRepair() == 0 || p.GetInRepair() == false) {
		q = sqrt(abs(c1.GetNumFac() - c2.GetNumFac()) / (p.GetLength())) * pow(p.GetDiameter(), 2.5);
	}
	else {
		q = 0;
	}
}

gazset::gazset()
{
	p = pipe();
	c1 = cs();
	c2 = cs();
}

pipe gazset::getPipe() const
{
	return p;
}

int gazset::getPipeID() const
{
	return idp;
}

cs gazset::getCs1() const
{
	return c1;
}

cs gazset::getCs2() const
{
	return c2;
}

int gazset::getCs1ID() const
{
	return idc1;
}

int gazset::getCs2ID() const
{
	return idc2;
}

double gazset::getQ() const
{
	return q;
}

void gazset::calculateQ()
{
	if (p.GetInRepair() == 0 || p.GetInRepair() == false) {
		q = c2.GetNumWorkFac() * c1.GetNumWorkFac() * pow(p.GetDiameter(), 2.5) / (pow(p.GetLength(), 3.5));
	}
	else {
		q = 0;
	}

}
