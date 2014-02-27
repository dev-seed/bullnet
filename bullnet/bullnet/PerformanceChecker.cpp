#include "stdafx.h"

PerformanceChecker::PerformanceChecker()
	: m_Resolution(0)
{
	m_Frequency.QuadPart = 0;
	m_Counter[0].QuadPart = 0;
	m_Counter[1].QuadPart = 0;

	QueryPerformanceFrequency(&m_Frequency);

	m_Resolution = (1.0/m_Frequency.QuadPart*1000000);
}

PerformanceChecker::~PerformanceChecker()
{

}

void PerformanceChecker::StartCounter()
{
	QueryPerformanceCounter( &m_Counter[0] );
}

void PerformanceChecker::EndCounter()
{
	QueryPerformanceCounter( &m_Counter[1] );
}

double PerformanceChecker::GetElapsedTime()
{
	double elapsedTime = ((double)(m_Counter[1].QuadPart - m_Counter[0].QuadPart)*m_Resolution)/1000000;

	return elapsedTime;
}