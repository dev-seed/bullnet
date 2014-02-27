#pragma once

class PerformanceChecker
{
public :
	PerformanceChecker();
	~PerformanceChecker();

private :
	LARGE_INTEGER	m_Frequency;
	double			m_Resolution;
	LARGE_INTEGER	m_Counter[2];

public :
	void			StartCounter();
	void			EndCounter();

	double			GetElapsedTime();

};