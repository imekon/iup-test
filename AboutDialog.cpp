
#include "AboutDialog.h"

AboutDialog::AboutDialog()
{
	auto label = IupLabel("Help About Sample");
	auto okButton = IupButton("OK", "");
	IupSetCallback(okButton, "ACTION", onOK);
	auto box = IupHbox(label, okButton, nullptr);
	IupSetAttribute(box, "MARGIN", "10x10");
	IupSetInt(box, "GAP", 10);
	dialog = IupDialog(box);
	IupSetAttribute(dialog, "TITLE", "Hello World!");
}

int AboutDialog::onOK(Ihandle * self)
{
	return IUP_CLOSE;
}
