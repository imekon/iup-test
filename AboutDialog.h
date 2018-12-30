#pragma once

#include <iup.h>

class AboutDialog
{
public:
	AboutDialog();
	~AboutDialog();

	void showModal();

private:
	Ihandle *dialog;

	static int onOK(Ihandle *self);
};