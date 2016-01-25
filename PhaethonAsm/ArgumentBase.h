#pragma once

class ArgumentBase
{
public:
	enum Type
	{
		None = 0,
		Constant = 1,
        Register = 2,
        ConstAddress = 3,
        RegAddress = 4,
	};

    static const char* ppszTypeText[];
    static const char* ppszShortTypeText[];
};
