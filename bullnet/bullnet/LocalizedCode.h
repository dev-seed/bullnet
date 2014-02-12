#pragma once

typedef unsigned int LocalizedCodeValue;

class LocalizedCode : public XMLParser
{
public:
	LocalizedCode();
	~LocalizedCode();

	bool Init(  std::string XMLFileName, std::string outsideTag );

	const LocalizedCodeValue & GetLocalizedCode();

private :
	LocalizedCodeValue		m_LocalizedCodeValue;
};