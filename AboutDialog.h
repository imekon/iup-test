#pragma once

#include <iup.h>

#include "GenericDialog.h"

class AboutDialog : public GenericDialog
{
public:
	AboutDialog();

private:
	static int onOK(Ihandle *self);
};