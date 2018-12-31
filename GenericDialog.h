#pragma once

#include <iup.h>

class GenericDialog
{
public:
	GenericDialog();
	virtual ~GenericDialog();
	virtual bool showModal();

protected:
	Ihandle *dialog;
};